/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumourot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 14:53:23 by jumourot          #+#    #+#             */
/*   Updated: 2019/05/17 15:10:39 by jumourot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_digit(int n)
{
	int	j;

	j = 1;
	while (n / 10)
	{
		n = n / 10;
		++j;
	}
	return (j);
}
