#include "../minishell.h"

void	main_init(
	int *syntx_erred, t_struct *p_ds, int argc, char **argv)
{
	whiplash_img();
	*syntx_erred = 0;
	p_ds->head_token = NULL;
	p_ds->root_node = NULL;
	(void)argc;
	(void)argv;
}

void	about_prompt(char **p_str)
{
	set_or_get_heredoc_status(0);
	signal_handler();
	*p_str = readline("whiplash > ");
	if (!(*p_str))
		exit(set_or_get_status(-1));
	add_history(*p_str);
}

void	tree_parser_error(char *str, t_struct *ds, int *syntax_erred)
{
	if (*syntax_erred)
		printf("Error: syntax error!\n");
	cleaner(str, ds, NULL);
	*syntax_erred = 0;
}

int	loop_shell_prompt(t_struct *ds, int *p_syntx_erred)
{
	char	*str;

	while (1)
	{
		about_prompt(&str);
		ds->head_token = tokenize(str);
		if (ds->head_token == NULL)
		{
			free(str);
			continue ;
		}
		if (make_tree(ds) == ERROR
			|| (!tree_parser(ds->root_node, p_syntx_erred) && *p_syntx_erred))
		{
			tree_parser_error(str, ds, p_syntx_erred);
			continue ;
		}
		if (set_or_get_heredoc_status(GET) == CTRL_C)
		{
			cleaner(str, ds, NULL);
			continue ;
		}
		execute(ds);
		cleaner(str, ds, NULL);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_struct	ds;
	int			syntx_erred;

	main_init(&syntx_erred, &ds, argc, argv);
	make_g_env_array(envp);
	loop_shell_prompt(&ds, &syntx_erred);
	return (0);
}
