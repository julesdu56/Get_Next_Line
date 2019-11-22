/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumourot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:33:37 by jumourot          #+#    #+#             */
/*   Updated: 2019/11/19 14:17:04 by jumourot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_strichr(char *str, char c)
{
	int	i;

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
		ft_strcpy(str, ft_strchr(str, '\n') + 1)
		return (0);
	}
	if(ft_strichr(str, '\n'))
	{
		ft_strcpy(str, ft_strchr(str, '\0'));
		return (0);
	}
}

int			get_next_line(int fd, char **line)
{
	static char	*str[MAX_OPEN];
	char		*buf;	
	char		*ptr;
	int		i;

	if (!line || fd < 0 || BUFF_SIZE < 1 || fd < MAX_OPEN 
		|| read(fd, buf, 0) == -1)
	if (!str[fd])
		return (0);
	while (i = read(fd, buf, BUFF_SIZE))
	{
		buf[i] = '\0';
		ptr = buf[fd];
		:


}	
