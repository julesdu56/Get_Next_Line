/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumourot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:16:37 by jumourot          #+#    #+#             */
/*   Updated: 2020/02/07 16:34:10 by jumourot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int main(int ac, char **av)
{
	char *line;
	int fd = open(av[1], O_RDONLY);
	int fd2 = open(av[2], O_RDONLY);
	int fd3 = open(av[3], O_RDONLY);
	int ret = 1;
	(void)ac;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		printf("%d %s\n", ret, line);
		free(line);
		ret = get_next_line(fd2, &line);
		printf("%d %s\n", ret, line);
		free(line);
		ret = get_next_line(fd3, &line);
		printf("%d %s\n", ret, line);
		free(line);
	}
	close(fd);
	close(fd2);
	close(fd3);
	system("leaks a.out");
	return (0);
}
