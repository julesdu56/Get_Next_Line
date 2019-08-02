#include <stdio.h>
#include "get_next_line.h"
#include "libft/libft.h"

static size_t		ft_strichr(char *feed, char c)
{
	size_t i;

	i = 0;
	if (!feed)
		return (0);
	while (feed[i] != c && feed[i] != '\0')
		i++;
	return (i);
}

static int			ft_checkend(char *feed)
{
	if (ft_strchr(feed, '\n'))
	{
		ft_strcpy(feed, ft_strchr(feed, '\n') + 1);
		return (0);
	}
	if (ft_strichr(feed, '\n'))
	{
		ft_strcpy(feed, ft_strchr(feed, '\0'));
		return (0);
	}
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static char	*feed[MAX_OPEN];
	int			rd;
	char		buf[BUFF_SIZE + 1];
	char		*ptr;

	if (fd < 0 || fd > MAX_OPEN || !line || BUFF_SIZE < 1
			|| read(fd, buf, 0) == -1)
		return (-1);
	if (!feed[fd])
		feed[fd] = NULL;
	while (!(ft_strchr(feed[fd], '\n')) && (rd = read(fd, buf, BUFF_SIZE)) > 0)
	{
        buf[rd] = '\0';
		ptr = feed[fd];
        if (!(feed[fd] = ft_strjoin(ptr, buf)))
			return (-1);
		free(ptr);
	}
	*line = ft_strsub(feed[fd], 0, ft_strichr(feed[fd], '\n'));
	if (!ft_checkend(feed[fd]))
		return (1);
	return (0);
}