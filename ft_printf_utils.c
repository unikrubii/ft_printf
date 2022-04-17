/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:18:53 by sthitiku          #+#    #+#             */
/*   Updated: 2022/04/17 21:59:30 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_f	*init_s(t_f *ar)
{
	ar->len = 0;
	ar->flen = 0;
	ar->stop = 0;
	return (ar);
}

void	put_char(t_f *ar, char c)
{
	write(1, &c, 1);
	ar->len++;
	ar->flen = 1;
}

int		flag_len(char *fmt)
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
