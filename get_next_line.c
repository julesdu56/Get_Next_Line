#include <stdio.h>
#include "get_next_line.h"
#include "libft/libft.h"

static size_t		ft_strichr(char *str, char c)
{
	size_t i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

static int			ft_checkend(char *str)
{
	if (ft_strchr(str, '\n'))
	{
		ft_strcpy(str, ft_strchr(str, '\n') + 1);
		return (0);
	}
	if (ft_strichr(str, '\n'))
	{
		ft_strcpy(str, ft_strchr(str, '\0'));
		return (0);
	}
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static char	*str[MAX_OPEN];
	int			i;
	char		buf[BUFF_SIZE + 1];
	char		*ptr;

	if (fd < 0 || fd > MAX_OPEN || !line || BUFF_SIZE < 1
			|| read(fd, buf, 0) == -1)
		return (-1);
	if (!str[fd])
		str[fd] = NULL;
	while (!(ft_strchr(str[fd], '\n')) && (i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[i] = '\0';
		ptr = str[fd];
		if (!(str[fd] = ft_strjoin(ptr, buf)))
				return (-1);
		free(ptr);
	}
	*line = ft_strsub(str[fd], 0, ft_strichr(str[fd], '\n'));
	if(!ft_checkend(str[fd]))
		return (1);
	return (0);
}
