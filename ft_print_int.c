/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 01:01:47 by sthitiku          #+#    #+#             */
/*   Updated: 2022/04/30 17:24:51 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_digit_int(long n)
{
	if (n < 0)
	{
		if (n > -10)
			return (1 + count_digit_int(-n / 10));
		else
			return (2 + count_digit_int(-n / 10));
	}
	if (n >= 10)
		return (1 + count_digit_int(n / 10));
	return (1);
}

unsigned int	count_digit_u(size_t n, size_t base, unsigned int len)
{
	if (n >= base)
		len = count_digit_u(n / base, base, len);
	return (1 + len);
}

void	ft_putnbr(long n, t_f *ar)
{
	if (n < 0)
	{
		ft_putchar('-', ar);
		n *= -1;
	}
	if (n >= 10)
		ft_putnbr(n / 10, ar);
	ft_putchar(n % 10 + '0', ar);
}

void	put_plus(int n, t_f *ar)
{
	if (n >= 0)
	{
		write(1, "+", 1);
		ar->len++;
	}
	ft_putnbr(n, ar);
}
