/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 18:03:54 by sthitiku          #+#    #+#             */
/*   Updated: 2022/04/06 21:04:46 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_di(va_list arg, char mode);
int	ft_nbr_sharp(va_list arg, size_t base, char mode);
int	ft_isdigit(const char c);
int	ft_atoi(const char *str);

int p_flags_b2(const char **fmt)
{
	int	len;
	int	space;

	len = 0;
	space = 0;
	if (*fmt == ' ')
	{
		space = ft_atoi(fmt);
		while (len < space)
		{
			write(1, " ", 1);
			len++;
		}
	}
	return (len);
}

int p_flags_b1(va_list arg, const char *fmt)
{
	int		len;
	char	mode;

	len = 0;
	mode = 's';
	if (*fmt == '#')
	{
		fmt++;
		if (*fmt == 'x' || *fmt == 'X')
		{
			if (*fmt == 'X')
				mode = 'S';
			len += ft_nbr_sharp(arg, 16, mode);
		}
	}
	else if(*fmt == '+')
	{
		mode = 'p';
		len += ft_put_di(arg, mode);
	}
	else
		len += p_flags_b2(&fmt);
	return (len);
}

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
		len += ft_put_di(arg, 'd');
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
	else
		len += p_flags_b1(arg, fmt);
	return (len);
}

int	check_flags(va_list arg, const char *fmt)
{
	int		len;

	len = 0;
	while (*fmt)
	{
		if (*fmt == '%' || *fmt == '+')
		{
			fmt++;
			len += p_flags(arg, fmt);
			if (*fmt == '#' || *fmt == '+')
				fmt++;
			else if (*fmt == ' ')
			{
				fmt++;
				while (ft_isdigit(*fmt))
					fmt++;
				len += p_flags(arg, fmt);
			}
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
	va_list		arg;
	int			len;

	va_start(arg, fmt);
	len = check_flags(arg, fmt);
	va_end(arg);
	// printf("\n==%d==\n", len);
	return (len);
}