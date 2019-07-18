
#include <stdio.h>
#include <unistd.h>
#include "libft.h"
#include "get_next_line.h"

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
		ft_bzero(*line, BUFF_SIZE);
	}
	return (0);
}	

int		get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			i;
	char static	*str[MAX_OPEN];

	
	if (fd < 0 || !line || fd > MAX_OPEN 
			|| BUFF_SIZE < 1 || read(fd, buf, 0) == -1)
			return (-1);
	if (!str[fd])
			return (str[fd]) == NULL;
	while (!(ft_strchr(str[fd], '\n')) && (i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		read(fd, line, BUFF_SIZE);
		ft_gnl(buf, line);
	}	
	return (1);
}