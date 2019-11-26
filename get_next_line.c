/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumourot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:33:37 by jumourot          #+#    #+#             */
/*   Updated: 2019/11/26 18:33:29 by jumourot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static	size_t		ft_strichr(char *str, char c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

static	int		ft_checkendfile(char *str)
{
	if (ft_strchr(str, '\n'))
	{
		ft_strcpy(str, ft_strchr(str, '\n') + 1);
		return (0);
	}
	if(ft_strichr(str, '\n'))
	{
		ft_strcpy(str, ft_strchr(str, '\0'));
		return (0);
	}
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static char	*str[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];	
	char		*ptr;
	int			i;
	
	if (!line ||  fd < 0 || BUFFER_SIZE < 1 || fd > OPEN_MAX 
				|| read(fd, buf, 0) == -1)
		return (-1);
	if (!str[fd])
		str[fd] = NULL;
	while (!(ft_strchr(str[fd], '\n')) && (i = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[i] = '\0';
		ptr = str[fd];
		if (!(str[fd] = ft_strjoin(ptr, buf)))
				return (-1);
		free(ptr);
	}	
	*line = ft_substr(str[fd], 0, ft_strichr(str[fd], '\n'));
	if (!ft_checkendfile(str[fd]))
			return (1);
	return (0);
}	
