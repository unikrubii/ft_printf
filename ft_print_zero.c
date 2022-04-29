/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_zero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 15:11:48 by sthitiku          #+#    #+#             */
/*   Updated: 2022/04/30 01:04:56 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	z_unsigned(unsigned int width, char spec, t_f *ar, char sp_c)
{
	unsigned int	num;
	unsigned int	digit;
	unsigned int	i;

	num = (unsigned int)va_arg(ar->arg, unsigned int);
	if (spec == 'u')
		digit = count_digit_u(num, 10, 0);
	else
		digit = count_digit_u(num, 16, 0);
	if (width > digit)
		digit = width - digit;
	else
		digit = 0;
	i = 0;
	while (i++ < digit)
		ft_putchar(sp_c, ar);
	if (spec == 'u')
		put_base(num, ar, 10, 'u');
	else if (spec == 'x')
		put_base(num, ar, 16, 'x');
	else if (spec == 'X')
		put_base(num, ar, 16, 'X');
}

void	z_str(int width, t_f *ar, char sp_c)
{
	int		len;
	char	*str;

	str = (char *)va_arg(ar->arg, char *);
	len = ft_strlen(str);
	if (width > len)
		width -= len;
	else
		width = 0;
	if (!str)
		width -= 6;
	while (width > 0)
	{
		ft_putchar(sp_c, ar);
		width--;
	}
	ft_putstr(str, ar);
}

void	z_char(int width, t_f *ar, char sp_c)
{
	int		len;
	char	c;

	c = (char)va_arg(ar->arg, int);
	len = 1;
	if (width > len)
		width -= len;
	else
		width = 0;
	while (width > 0)
	{
		ft_putchar(sp_c, ar);
		width--;
	}
	ft_putchar(c, ar);
}

void	put_zero(char *flag, t_f *ar)
{
	int		width;
	char	sp_c;
	char	spec;

	spec = flag[ft_strlen(flag) - 1];
	if (flag[1] == '0' && flag[ft_strlen(flag) - 1] != 's')
		sp_c = '0';
	else
		sp_c = ' ';
	width = ft_atoi(&flag[1]);
	if (spec == 'd' || spec == 'i')
		z_int(width, ar, sp_c);
	else if (spec == 'p')
		z_pointer(width, ar, sp_c);
	else if (spec == 's')
		z_str(width, ar, sp_c);
	else if (spec == 'c')
		z_char(width, ar, sp_c);
	else
		z_unsigned(width, spec, ar, sp_c);
}
