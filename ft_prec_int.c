/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 02:00:23 by sthitiku          #+#    #+#             */
/*   Updated: 2022/05/04 11:03:44 by sthitiku         ###   ########.fr       */
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

	if (len >= ar->p_l)
		i = 0;
	else
		i = ar->p_l - len;
	// printf("iiii %d\tp_l %d\n", i, ar->p_l);
	if (n < 0)
	{
		if (len <= ar->p_l)
			i++;
	}
	// printf("i = %d\tlen = %d, p_w = %d\n", i, len, ar->p_w);
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
	if (ar->p_l == 0 && n == 0)
	{
		put_nbr_e(ar);
		return ;
	}
	len = d_u(n, 10, 0);
	if (mode == 'm')
		put_nbr_m(n, ar, len);
	else if (mode == 'n')
		put_nbr_n(n, ar, len);
}

void	put_nbr_e(t_f *ar)
{
	int	i;

	i = 0;
	while (i < ar->p_w)
	{
		ft_putchar(' ', ar);
		i++;
	}
}

void	prec_d(t_f *ar, char mode)
{
	int	n;
	int	len;
	
	n = (int)va_arg(ar->arg, int);
	if (ar->p_l == 0 && n == 0)
	{
		put_nbr_e(ar);
		return ;
	}
	len = d_int(n);
	if (mode == 'm')
		put_nbr_m(n, ar, len);
	else if (mode == 'n')
		put_nbr_n(n, ar, len);
}
