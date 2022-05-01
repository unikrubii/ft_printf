/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_zero_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:11:48 by sthitiku          #+#    #+#             */
/*   Updated: 2022/05/01 02:35:19 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	z_put_space(t_f *ar, char sp_c, int digit)
{
	int	i;

	i = 0;
	while (i++ < digit)
			ft_putchar(sp_c, ar);
}

void	z_int(int width, t_f *ar, char sp_c)
{
	long	num;
	int		digit;

	num = (long)va_arg(ar->arg, int);
	digit = d_int(num);
	if (width > digit)
		digit = width - digit;
	else
		digit = 0;
	if (sp_c == ' ')
	{
		z_put_space(ar, sp_c, digit);
	}
	if (num < 0)
	{
		ft_putchar('-', ar);
		num *= -1;
	}
	if (sp_c == '0')
	{
		z_put_space(ar, sp_c, digit);
	}
	ft_putnbr(num, ar);
}

void	z_pointer(size_t width, t_f *ar, char sp_c)
{
	size_t	i;
	size_t	base;

	base = (size_t)va_arg(ar->arg, size_t);
	if (!base)
	{
		if (width >= 3)
			width -= 3;
		else
			width = 0;
	}
	else
	{
		if (width >= 14)
			width -= 14;
		else
			width = 0;
	}
	i = 0;
	while (i < width)
	{
		ft_putchar(sp_c, ar);
		i++;
	}
	put_base(base, ar, 16, 'p');
}
