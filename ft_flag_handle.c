/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:43:10 by sthitiku          #+#    #+#             */
/*   Updated: 2022/05/06 03:14:10 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (0);
}

void	proc_bonus2(char *flag, t_f *ar)
{
	int	i;

	i = 1;
	if (flag[i] == '-' && !ft_strchr(flag, '.'))
	{
		put_minus(flag, ar);
		return ;
	}
	else if (ft_strchr(flag, '.'))
		ft_print_prec(flag, ar);
	// else if (flag[i] == '-' && ft_strchr(flag, '.'))
}

void	proc_bonus(char *flag, t_f *ar)
{
	int	i;

	i = 0;
	while (++i < ar->flen)
	{
		if (flag[i] == '#')
			put_sharp(flag, ar);
		else if (flag[i] == '+')
		{
			put_plus(va_arg(ar->arg, int), ar);
			return ;
		}
		else if (flag[i] == ' ')
		{
			put_space(flag, ar, ' ');
			return ;
		}
		else if (ft_isdigit(flag[i]) && !ft_strchr(flag, '.'))
		{
			put_zero(flag, ar);
			return ;
		}
		else
		{
			proc_bonus2(flag, ar);
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
