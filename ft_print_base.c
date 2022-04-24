/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:44:08 by sthitiku          #+#    #+#             */
/*   Updated: 2022/04/24 18:58:25 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			write(1, "0x", 2);
		else if (flag[i] == 'X')
			write(1, "0X", 2);
		put_base(n, ar, 16, flag[i]);
		ar->len += 2;
		return ;
		i++;
	}
}
