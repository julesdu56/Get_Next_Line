/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumourot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:35:06 by jumourot          #+#    #+#             */
/*   Updated: 2019/12/03 13:29:11 by jumourot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	char *line;
	int fd;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
	printf("%d\n", get_next_line(fd, &line));
	return (0);
}

