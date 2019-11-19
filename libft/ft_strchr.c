/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumourot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 07:35:33 by jumourot          #+#    #+#             */
/*   Updated: 2019/08/29 17:50:56 by jumourot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char    *ft_strchr(const char *str, int c)
{
	unsigned int i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
		if ((char)c == '\0')
			return ((char *)&str[i]);
		i = 0;
		while (str[i])
		{
			if (str[i] == (char)c)
				return ((char *)&str[i]);
			i++;
		}
	}
	return (NULL);
}
