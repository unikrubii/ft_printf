/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 00:41:13 by sthitiku          #+#    #+#             */
/*   Updated: 2022/02/23 15:20:39 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_digit(long n)
{
	if (n < 0)
	{
		if (n > -10)
			return (1 + count_digit(-n / 10));
		else
			return (2 + count_digit(-n / 10));
	}
	if (n >= 10)
		return (1 + count_digit(n / 10));
	return (1);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*result;
	long	nb;

	nb = n;
	i = count_digit(nb);
	result = (char *)malloc(sizeof(char) * (i + 1));
	if (!result)
		return (NULL);
	result[i--] = '\0';
	if (nb == 0)
		result[0] = '0';
	if (nb < 0)
	{
		result[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		result[i--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (result);
}
