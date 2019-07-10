/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumourot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:14:51 by jumourot          #+#    #+#             */
/*   Updated: 2019/05/20 15:50:43 by jumourot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*des;
	char	*str;

	des = (char*)dest;
	str = (char*)src;
	if (des > str)
	{
		des = des + n - 1;
		str = str + n - 1;
		while (n > 0)
		{
			*des-- = *str--;
			n--;
		}
	}
	else
	{
		while (n > 0)
		{
			if (dest != NULL && src != NULL)
			{
				*des++ = *str++;
				n--;
			}		
		}
	}
	return (dest);
}
