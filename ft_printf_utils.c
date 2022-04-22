/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:18:53 by sthitiku          #+#    #+#             */
/*   Updated: 2022/04/22 18:13:27 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}


int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

t_f	*init_s(t_f *ar)
{
	ar->len = 0;
	ar->flen = 0;
	return (ar);
}

void	put_nonf(t_f *ar, char c)
{
	write(1, &c, 1);
	ar->len++;
	ar->flen = 1;
}

int	flag_len(char *fmt)
{
	int	i;

	i = 1;
	while(fmt[i])
	{
		if (fmt[i] == 'c' || fmt[i] == 's' || fmt[i] == 'p' || \
			fmt[i] == 'd' || fmt[i] == 'i' || fmt[i] == 'u' || \
			fmt[i] == 'x' || fmt[i] == 'X')
			break ;
		else
			i++;
	}
	i++;
	return (i);
}

int	ft_atoi(char *s)
{
	int	minus;
	int	res;

	minus = 1;
	res = 0;
	while (*s == ' ')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			minus *= -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		res = res * 10 + (*s - '0');
		s++;
	}
	return (res * minus);
}