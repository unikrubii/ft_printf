/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 18:03:54 by sthitiku          #+#    #+#             */
/*   Updated: 2022/04/05 02:58:54 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_di(va_list arg);

int	p_flags(va_list arg, const char *fmt)
{
	int		len;

	len = 0;
	if (*fmt == 'c')
		len += print_c(arg);
	else if (*fmt == 's')
		len += print_str(arg);
	else if (*fmt == 'p')
		len += ft_putnbr_base(arg, 16, 'p');
	else if (*fmt == 'd' || *fmt == 'i')
		len += ft_put_di(arg);
	else if (*fmt == 'u')
		len += ft_putnbr_base(arg, 10, 'u');
	else if (*fmt == 'x')
		len += ft_putnbr_base(arg, 16, 'x');
	else if (*fmt == 'X')
		len += ft_putnbr_base(arg, 16, 'X');
	else if (*fmt == '%')
	{
		write(1, "%", 1);
		len++;
	}
	return (len);
}

int	check_flags(va_list arg, const char *fmt)
{
	int		len;

	len = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			len += p_flags(arg, fmt);
		}
		else
		{
			write(1, &(*fmt), 1);
			len++;
		}
		fmt++;
	}
	return (len);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	arg;
	int		len;

	va_start(arg, fmt);
	len = check_flags(arg, fmt);
	va_end(arg);
	// printf("\n==%d==\n", len);
	return (len);
}