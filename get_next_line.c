/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumourot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:33:37 by jumourot          #+#    #+#             */
/*   Updated: 2020/01/21 12:18:04 by jumourot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

char				*ft_strchr(const char *str, int c)
{
	unsigned int	i;

	i = 0;
	if (!str || str == NULL)
		return (NULL);
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

char				*ft_strcpy(char *dest, const char *src)
{
	int				i;

	i = 0;
	while (src[i] && dest[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static size_t		ft_strichr(char *str, char c)
{
		size_t			i;

		i = 0;
		if (!str)
			return (0);
		if (str[0] == '\n')
			return (1);
		while (str[i] != '\0' && str[i] != c)
			i++;
		return (i);
}

static int			ft_checkendfile(char *str)
{
	if (ft_strchr(str, '\n'))
	{
		ft_strcpy(str, ft_strchr(str, '\n') + 1);
		return (0);
	}
	else if (ft_strichr(str, '\n'))
	{
		ft_strcpy(str, &(str[ft_strichr(str, '\0')]));
		return (1);
	}
	return (1);
}

int					get_next_line(int fd, char **line)
{
	static char		*str[OPEN_MAX];
	char			buf[BUFFER_SIZE + 1];
	char			*ptr;
	int				i;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > OPEN_MAX || !line
			|| read(fd, buf, 0) == -1)
		return (-1);
	if (!str[fd])
		str[fd] = ft_strdup("");
	while (!(ft_strchr(str[fd], '\n')) && (i = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[i] = '\0';
		ptr = str[fd];
		if (!(str[fd] = ft_strjoin(ptr, buf)))
		{
			free(ptr);
			return (-1);
		}
		free(ptr);
	}
	*line = ft_substr(str[fd], 0, ft_strichr(str[fd], '\n'));
	if (!ft_checkendfile(str[fd]))
		return (1);
	ft_chausette(fd, str[fd], *line);
	return (0);
}

int main(int ac, char **av)
{
	char *line;
	int fd = open(av[1], O_RDONLY);
	int ret;

	(void)ac;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%d %s\n", ret, line);
		free(line);
	}
 	printf("%d %s\n\n", ret, line);
	free(line);
	close(fd);
	system("leaks a.out");
	return (0);
}
