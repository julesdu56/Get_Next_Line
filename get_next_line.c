/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumourot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 13:41:20 by jumourot          #+#    #+#             */
/*   Updated: 2020/02/10 12:41:39 by jumourot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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
		return (0);
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

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX || !line
			|| read(fd, buf, 0) == -1)
		return (-1);
	if (!str[fd])
		str[fd] = ft_strdup("");
	if (ft_for_read(fd, buf, str) == -1)
	{
		free(str[fd]);
		return (-1);
	}
	*line = ft_substr(str[fd], 0, ft_strichr(str[fd], '\n'));
	if (*line == NULL)
		*line = ft_strdup("");
	if (!ft_checkendfile(str[fd]))
		return (1);
	return (0);
}
