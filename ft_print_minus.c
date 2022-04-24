/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_minus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 12:38:18 by sthitiku          #+#    #+#             */
/*   Updated: 2022/04/24 18:59:01 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	minus_i(int width, t_f *ar)
{
	int	var_i;
	int	len;

	var_i = (int)va_arg(ar->arg, int);
	ft_putnbr(var_i, ar);
	len = count_digit_int(var_i);
	if (width > len)
		width -= len;
	else
		width = 0;
	while (width > 0)
	{
		ft_putchar(' ', ar);
		width--;
	}
}

void	minus_u(unsigned int width, char spec, t_f *ar)
{
	unsigned int	var_u;
	unsigned int	len;

	var_u = (unsigned int)va_arg(ar->arg, unsigned int);
	if (spec == 'c')
	{
		ft_putchar(var_u, ar);
		len = 1;
	}
	else
	{
		ft_putnbr(var_u, ar);
		len = count_digit_int(var_u);
	}
	if (width > len)
		width -= len;
	else
		width = 0;
	while (width > 0)
	{
		ft_putchar(' ', ar);
		width--;
	}
}

void	minus_s(int width, t_f *ar)
{
	char	*var_s;
	int		len;

	var_s = (char *)va_arg(ar->arg, char *);
	if (!var_s)
		len = 6;
	else
		len = ft_strlen(var_s);
	ft_putstr(var_s, ar);
	if (width > len)
		width -= len;
	else
		width = 0;
	while (width > 0)
	{
		ft_putchar(' ', ar);
		width--;
	}
}

void	minus_t(unsigned int width, char spec, t_f *ar)
{
	size_t			var_t;
	unsigned int	len;

	var_t = (size_t)va_arg(ar->arg, size_t);
	if (spec == 'p')
		len = count_digit_u(var_t, 16, 0) + 2;
	else
		len = count_digit_u((unsigned int)var_t, 16, 0);
	put_base(var_t, ar, 16, spec);
	if (width > len)
		width -= len;
	else
		width = 0;
	while (width > 0)
	{
		ft_putchar(' ', ar);
		width--;
	}
}

void	put_minus(char *flag, t_f *ar)
{
	int		width;
	char	spec;

	width = ft_atoi(&flag[2]);
	spec = flag[ft_strlen(flag) - 1];
	if (spec == 'c' || spec == 'u')
		minus_u(width, spec, ar);
	else if (spec == 'd' || spec == 'i')
		minus_i(width, ar);
	else if (spec == 's')
		minus_s(width, ar);
	else if (spec == 'p' || spec == 'x' || spec == 'X')
		minus_t(width, spec, ar);
}
