/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:01:03 by sthitiku          #+#    #+#             */
/*   Updated: 2022/04/24 19:04:51 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	proc_bonus(char *flag, t_f *ar)
{
	int	i;

	i = 0;
	while (++i < ar->flen)
	{
		if (flag[i] == '#')
			put_sharp(flag, ar);
		else if (flag[i] == '+')
			put_plus(va_arg(ar->arg, int), ar);
		else if (flag[i] == ' ')
		{
			put_space(flag, ar, ' ');
			return ;
		}
		else if (ft_isdigit(flag[i]))
		{
			put_zero(flag, ar);
			return ;
		}
		else if (flag[i] == '-')
		{
			put_minus(flag, ar);
			return ;
		}
	}
}

void	proc_flag(char *flag, t_f *ar)
{
	int	i;

	i = 0;
	while (++i < ar->flen)
	{
		if (flag[i] == 'd' || flag[i] == 'i')
			ft_putnbr(va_arg(ar->arg, int), ar);
		else if (flag[i] == 'c')
			ft_putchar(va_arg(ar->arg, int), ar);
		else if (flag[i] == 's')
			ft_putstr(va_arg(ar->arg, char *), ar);
		else if (flag[i] == 'p')
			put_base(va_arg(ar->arg, size_t), ar, 16, 'p');
		else if (flag[i] == 'u')
			put_base(va_arg(ar->arg, size_t), ar, 10, 'u');
		else if (flag[i] == 'x')
			put_base(va_arg(ar->arg, size_t), ar, 16, 'x');
		else if (flag[i] == 'X')
			put_base(va_arg(ar->arg, size_t), ar, 16, 'X');
		else
		{
			proc_bonus(flag, ar);
			return ;
		}
	}
}

void	get_flag(char *fmt, t_f *ar)
{
	char	*flag;
	int		i;

	flag = (char *)malloc(sizeof(char) * (ar->flen + 1));
	if (!flag)
		return ;
	i = 0;
	while (i < ar->flen)
	{
		flag[i] = fmt[i];
		i++;
	}
	flag[i] = '\0';
	proc_flag(flag, ar);
	free(flag);
}

void	check_flags(t_f *ar, char *fmt)
{
	if (*(fmt + 1) == '%')
	{
		write(1, "%", 1);
		ar->flen = 2;
		ar->len++;
	}
	else
	{
		ar->flen = flag_len(fmt);
		get_flag(fmt, ar);
	}
}

int	ft_printf(const char *format, ...)
{
	t_f		*ar;
	char	*fmt;
	int		len;

	fmt = (char *)format;
	ar = (t_f *)malloc(sizeof(t_f));
	if (!ar)
		return (-1);
	ar = init_s(ar);
	va_start(ar->arg, format);
	while (*fmt)
	{
		if (*fmt != '%')
			put_nonf(ar, *fmt);
		else
			check_flags(ar, fmt);
		fmt = fmt + ar->flen;
	}
	va_end(ar->arg);
	len = ar->len;
	free(ar);
	return (len);
}
