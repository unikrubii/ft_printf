/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:01:03 by sthitiku          #+#    #+#             */
/*   Updated: 2022/05/03 23:36:54 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	if (ft_strchr(flag, '*'))
	{
		flag = parse_star(flag, ar);
		if (ar->st_v1)
			free(ar->st_v1);
		if (ar->st_v2)
			free(ar->st_v2);
	}
	// printf("%s\n", flag);
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
