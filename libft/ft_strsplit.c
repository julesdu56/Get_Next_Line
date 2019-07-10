/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumourot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 12:39:13 by jumourot          #+#    #+#             */
/*   Updated: 2019/05/17 11:21:24 by jumourot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(const char *s, char c)
{
	int		count;
	int		word;

	count = 0;
	word = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (word == 0 && *s != c)
		{
			word = 1;
			count++;
		}
		else if (*s == c)
			word = 0;
		s++;
	}
	return (count);
}

static int		ft_wordslen(const char *s, char c)
{
	int		i;

	i = 0;
	while (*s && *s != c)
	{
		i++;
		s++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	int		count;
	char	**tab;
	int		i;

	i = 0;
	count = count_words(s, c);
	if (!s)
		return (NULL);
	if (!(tab = malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	while (count--)
	{
		while (*s && *s == c)
			s++;
		if (!(tab[i] = ft_strsub(s, 0, ft_wordslen(s, c))))
			return (NULL);
		s += ft_wordslen(s, c);
		i++;
	}
	tab[i] = 0;
	return (tab);
}
