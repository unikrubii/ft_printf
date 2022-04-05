/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:17:52 by sthitiku          #+#    #+#             */
/*   Updated: 2022/04/05 12:21:10 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(int n, int mode)
{
	if (mode == 0)
		write(1, &"0123456789abcdef"[n], 1);
	else if (mode == 1)
		write(1, &"0123456789ABCDEF"[n], 1);
}

int	recur_base(size_t n, size_t base, int len, int p_mode)
{
	if (n >= base)
		len = recur_base(n / base, base, len, p_mode);
	n %= base;
	ft_puthex(n, p_mode);
	return (len + 1);
}

int	ft_putnbr_base(va_list arg, size_t base, char mode)
{
	ssize_t	n;
	int		len;
	int		p_mode;

	len = 0;
	p_mode = 0;
	n = (ssize_t)va_arg(arg, ssize_t);
	if (mode == 'p')
	{
		len += 2;
		write(1, "0x", 2);
	}
	else
	{
		n = (unsigned int)n;
		if (mode == 'X')
			p_mode = 1;
	}
	len += recur_base(n, base, 0, p_mode);
	return (len);
}

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

int	ft_put_di(va_list arg)
{
	int	len;
	long	n;

	n = (int)va_arg(arg, int);
	len = ft_putnbr(n, 0);
	return (len);
}