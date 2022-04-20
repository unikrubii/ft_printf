/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 01:01:47 by sthitiku          #+#    #+#             */
/*   Updated: 2022/04/20 21:32:54 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(unsigned char c, t_f *ar)
{
	write(1, &c, 1);
	ar->len++;
}

void	ft_putstr(unsigned char *str, t_f *ar)
{
	if (!str)
	{
		write(1, "(null)", 6);
		ar->len += 6;
		return ;
	}
	while (*str)
	{
		ft_putchar(*str, ar);
		str++;
	}
}

void	ft_putnbr(int n, t_f *ar)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		ar->len += 11;
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-', ar);
		n *= -1;
	}
	if (n >= 10)
		ft_putnbr(n / 10, ar);
	ft_putchar(n % 10 + '0', ar);
}

void	put_hex(int n, char mode, t_f *ar)
{
	if (mode == 'x' || mode == 'p' || mode == 'u')
	{
		write(1, &"0123456789abcdef"[n], 1);
		ar->len++;
	}
	else if (mode == 'X')
	{
		write(1, &"0123456789ABCDEF"[n], 1);
		ar->len++;
	}
}

void	recur_base(size_t n, t_f *ar, size_t base, char mode)
{
	if (n >= base)
		recur_base(n / base, ar, base, mode);
	n %= base;
	put_hex(n, mode, ar);
}

void	put_base(size_t n, t_f *ar, size_t base, char mode)
{
	if (mode == 'p')
	{
		write(1, "0x", 2);
		ar->len += 2;
	}
	else if (mode == 'u')
		n = (unsigned int)n;
	recur_base(n, ar, base, mode);
}