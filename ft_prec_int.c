/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 02:00:23 by sthitiku          #+#    #+#             */
/*   Updated: 2022/04/29 11:05:27 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_nbr_m(long n, t_f *ar, int len)
{
	int	i;

	i = -1;
	if (n < 0)
	{
		ft_putchar('-', ar);
		n *= -1;
		i--;
		ar->p_w--;
	}
	while (++i < ar->p_l - len)
		ft_putchar('0', ar);
	ft_putnbr(n, ar);
	while (len + i + 1 < ar->p_w + 1)
	{
		ft_putchar(' ', ar);
		len++;
	}
}

void	put_nbr_n(long n, t_f *ar, int len)
{
	int	i;

	if (len > ar->p_l)
		i = ar->p_l;
	else
		i = ar->p_l - len;
	if (n < 0)
		i++;
	while (i + len < ar->p_w)
	{
		ft_putchar(' ', ar);
		i++;
	}
	i = -1;
	if (n < 0)
	{
		ft_putchar('-', ar);
		n *= -1;
		i--;
	}
	while (++i < ar->p_l - len)
		ft_putchar('0', ar);
	ft_putnbr(n, ar);
}

void	prec_u(t_f *ar, char mode)
{
	unsigned int	n;
	int	len;
	
	n = (unsigned int)va_arg(ar->arg, unsigned int);
	len = count_digit_u(n, 10, 0);
	if (mode == 'm')
		put_nbr_m(n, ar, len);
	if (mode == 'n')
		put_nbr_n(n, ar, len);
}

void	prec_d(t_f *ar, char mode)
{
	int	n;
	int	len;
	
	n = (int)va_arg(ar->arg, int);
	len = count_digit_int(n);
	if (mode == 'm')
		put_nbr_m(n, ar, len);
	if (mode == 'n')
		put_nbr_n(n, ar, len);
}
