/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumourot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 18:29:40 by jumourot          #+#    #+#             */
/*   Updated: 2019/05/28 15:27:34 by jumourot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strichr(char *str, int c)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

int		checkeof(char *buff)
{
	if (ft_strchr(buff, '\n'))
	{
		ft_strcpy(buff, ft_strchr(buff, '\n') + 1);
		return (0);
	}
	if (ft_strichr(buff, '\0'))
	{
		ft_strcpy(buff, ft_strchr(buff, '\0'));
		return (0);
	}
	return (1);
}
		

int		get_next_line(const int fd, char **line)
{
	static char *mult[MAX_OPEN];
	char		*tmp;
	int 		i;
	char		buf[BUFF_SIZE]

	if (fd > MAX_OPEN || fd < 0 || BUFF_SIZE < 1 || !line 
			|| read(fd, buf, 0) == -1)
		return (-1);
	if (!mult[fd])
		mult[fd] == NULL;
	while (read(fd, buf, BUFF_SIZE) && ft_strchr(line, '\n))
	{
		
	}
	return (0);
}
