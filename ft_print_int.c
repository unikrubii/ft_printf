/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 01:01:47 by sthitiku          #+#    #+#             */
/*   Updated: 2022/04/21 20:56:21 by sthitiku         ###   ########.fr       */
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
		write(1, &"0123456789abcdef"[n], 1);
	else if (mode == 'X')
		write(1, &"0123456789ABCDEF"[n], 1);
	ar->len++;
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
	else
		n = (unsigned int)n;
	recur_base(n, ar, base, mode);
}

void	put_sharp(char *flag, t_f *ar)
{
	int				i;
	unsigned int	n;

	i = 2;
	n = (unsigned int)va_arg(ar->arg, unsigned int);
	if (n == 0)
	{
		write(1, "0", 1);
		ar->len++;
		return ;
	}
	while (i < ar->flen)
	{
		if (flag[i] == 'x')
		{
			write(1, "0x", 2);
			put_base(n, ar, 16, 'x');
		}
		else if (flag[i] == 'X')
		{
			write(1, "0X", 2);
			put_base(n, ar, 16, 'X');
		}
		ar->len += 2;
		return ;
		i++;
	}
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

void	put_space(char *flag, t_f *ar)
{
	// ("% s|% s", "", "-")
	printf("\n||%s||\n", flag);
}