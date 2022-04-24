/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:42:13 by sthitiku          #+#    #+#             */
/*   Updated: 2022/04/24 18:58:29 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_f *ar)
{
	write(1, &c, 1);
	ar->len++;
}

void	put_nonf(t_f *ar, char c)
{
	write(1, &c, 1);
	ar->len++;
	ar->flen = 1;
}

void	ft_putstr(char *str, t_f *ar)
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
