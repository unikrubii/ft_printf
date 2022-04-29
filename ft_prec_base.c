/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 10:39:02 by sthitiku          #+#    #+#             */
/*   Updated: 2022/04/30 01:30:47 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prec_bxm(t_f *ar, unsigned int n, int len, char spec)
{
	int	i;

	i = 0;
	while (i < ar->p_l - len)
	{
		ft_putchar('0', ar);
		i++;
	}
	recur_base(n, ar, 16, spec);
	while (len + i < ar->p_w)
	{
		ft_putchar(' ', ar);
		len++;
	}
}

void	prec_bxn(t_f *ar, unsigned int n, int len, char spec)
{
	int	i;

	// printf("%c\n", spec);
	if (len > ar->p_l)
		i = ar->p_l;
	else
		i = ar->p_l - len;
	// 0 3 8 5
	while (len + i < ar->p_w)
	{
		ft_putchar(' ', ar);
		i++;
	}
	i = 0;
	// printf("%d\n", len);
	// 0 2 8 5
	while (i < ar->p_l - len)
	{
		ft_putchar('0', ar);
		i++;
	}
	recur_base(n, ar, 16, spec);
}

void	prec_bx(t_f *ar, unsigned int n, char mode, char spec)
{
	int	len;
	
	len = count_digit_u(n, 16, 0);
	if (mode == 'm')
		prec_bxm(ar, n, len, spec);
	if (mode == 'n')
		prec_bxn(ar, n, len, spec);
}

void	prec_base(t_f *ar, char mode, char spec)
{
	size_t	n;

	n = (size_t)va_arg(ar->arg, size_t);
	if (ar->p_l == 0 && n == 0)
		return ;
	if (spec == 'p')
		printf("hello\n");
	else
	{
		n = (unsigned int)n;
		prec_bx(ar, n, mode, spec);
	}
}