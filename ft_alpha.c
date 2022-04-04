/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alpha.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:14:55 by sthitiku          #+#    #+#             */
/*   Updated: 2022/04/04 22:29:12 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(va_list arg)
{
	int		i;
	unsigned char	*s;
	
	s = (unsigned char *)va_arg(arg, unsigned char *);
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	print_c(va_list arg)
{
	unsigned char	input;

	input = (unsigned char)va_arg(arg, int);
	write(1, &input, 1);
	return (1);
}