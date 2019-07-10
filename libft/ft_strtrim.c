/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumourot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 17:31:39 by jumourot          #+#    #+#             */
/*   Updated: 2019/05/17 19:52:35 by jumourot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int			ft_is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

static size_t		search_len(const char *s)
{
	int		i;
	int		len;

	len = ft_strlen(s);
	i = len - 1;
	while (ft_is_space(s[i]) == 1 && i >= 0)
	{
		i--;
		len--;
	}
	i = 0;
	while (ft_is_space(s[i]) == 1)
	{
		i++;
		len--;
	}
	if (len <= 0)
		return (0);
	return (len);
}

char				*ft_strtrim(char const *s)
{
	char		*str;
	size_t		i;
	size_t		j;
	size_t		len;

	if (s == NULL)
		return (NULL);
	len = search_len(s);
	if (!(str = ft_strnew(len)))
		return (NULL);
	i = 0;
	j = 0;
	while (ft_is_space(s[i]) == 1)
		i++;
	while (j < len)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
