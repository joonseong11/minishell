/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whiplash_93.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekim <jeekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:45:35 by jeekim            #+#    #+#             */
/*   Updated: 2022/10/01 16:36:13 by jeekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	whiplash_img(void)
{
	int		fd;
	int		i;
	char	*str;

	fd = open(
			"/Users/jeekim/Desktop/team_whiplash/srcs/whiplash_img/whiplash_93",
			O_RDONLY);
	i = 0;
	printf("fd : %d\n", fd);
	while (i < 50)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free (str);
		i++;
	}
	printf("\n");
}
