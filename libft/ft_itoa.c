/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumourot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:44:50 by jumourot          #+#    #+#             */
/*   Updated: 2019/05/17 17:45:34 by jumourot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(long n)
{
	int		neg;
	int		len;

	neg = 0;
	len = 1;
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	while (n > 9)
	{
		len++;
		n /= 10;
	}
	return (len + neg);
}

char		*ft_itoa(int n)
{
	int		len;
	long	nb;
	char	*num;

	nb = n;
	len = get_len(nb);
	if (!(num = ft_strnew(len)))
		return (NULL);
	if (nb < 0)
	{
		num[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		num[0] = '0';
	while (len-- >= 0 && nb != 0)
	{
		num[len] = nb % 10 + '0';
		nb /= 10;
	}
	return (num);
}
