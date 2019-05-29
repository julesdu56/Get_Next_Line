/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumourot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 18:29:40 by jumourot          #+#    #+#             */
/*   Updated: 2019/05/29 16:52:31 by jumourot         ###   ########.fr       */
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

int		checkeof(char *stock)
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
	static char		*stock[MAX_OPEN]
	int				i;
	char			*tmp;
	char			buff[BUFF_SIZE + 1];

	if (fd < 0 || fd > MAX_OPEN || !line || BUFF_SIZE < 1 
			|| read(fd, buff, 0) == -1)
		return (-1);
	if (!stock[fd])
		stock[fd] == NULL;
	while (ft_strchr(line, '\n') && i = read(fd, line, BUFF_SIZE) = 1)
	{
		buff[i] = '\0';
		*tmp = stock[fd];
		if(!stock[fd] = ft_strjoin(tmp, buff))
				return (-1);
		free(ptr);
	}
	
