/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 01:05:40 by sthitiku          #+#    #+#             */
/*   Updated: 2022/04/06 01:24:23 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n, int len)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		len++;
	}
	if (n >= 10)
		len = ft_putnbr(n / 10, len);
	c = n % 10 + '0';
	write(1, &c, 1);
	return (len + 1);
}

int	ft_put_di(va_list arg, char mode)
{
	int	len;
	long	n;

	len = 0;
	n = (int)va_arg(arg, int);
	if (mode == 'p')
	{
		if (n >= 0)
		{
			write(1, "+", 1);
			len++;
		}
	}
	len += ft_putnbr(n, 0);
	return (len);
}