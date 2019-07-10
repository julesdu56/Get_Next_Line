#include <stdio.h>

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
	char	*tmp;	
	printf("str%s\n", str);
	if (ft_strchr(str, 'A'))
	{
		tmp = ft_strdup(str);
		printf("tmp1%s\n", tmp);
		str = ft_strcpy(str, ft_strchr(str, 'A'));
		printf("str2%s\n", str);
		ft_strichr(tmp, 'A');
		printf("tmp2%s\n", tmp);
	}	
	return (1);
}	

int		main()
{
	char *str = "FGFH A FHGFHG AhfhjA";
 	char **line;
	ft_gnl(str, line);
	return (0);
}
