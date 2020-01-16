/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumourot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:35:06 by jumourot          #+#    #+#             */
/*   Updated: 2020/01/16 15:19:09 by jumourot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
int main(int ac, char **av)
{
	char *line;
	int fd;
	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		int ret = 1;
		while (ret > 0)
		{
			ret = get_next_line(fd, &line);
			printf("ret : %d, line : [%s]\n", ret, line);
			free(line);
		}
	}
	return (0);
}
