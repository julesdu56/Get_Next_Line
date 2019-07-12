#include <stdio.h>
#include "libft/libft.h"
#include <unistd.h>


void		ft_strichr(char *str, char c)
{
	while (str)
	{
		if (*str != c && *str)
			str++;
		else if (*str == c)
			str = 0;
	}
}

int		ft_gnl(char *str, char **line)
{
	char	*tmp1;

	tmp1 = NULL;	
	if (ft_strchr(str, '\n'))
	{
		tmp1 = ft_strdup(str);
		str = ft_strcpy(str, ft_strchr(str, '\n'));
		ft_strichr(tmp1, '\n');
		ft_strjoin(*line, tmp1);
		free(tmp1);
	}	
	return (1);
	if (!(ft_strchr(str, '\n')))
	{
		ft_strjoin(*line ,str);
		bzero(*line, BUFF_SIZE);
	}
	return (0);
}	

int		get_next_line(const int fd, char **line)
{
	char static	buff[BUFF_SIZE];

	
	buff = read(fd, line, BUFF_SIZE);
	ft_gnl(buff, line);
}
