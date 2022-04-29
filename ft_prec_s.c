/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 22:30:09 by sthitiku          #+#    #+#             */
/*   Updated: 2022/04/30 01:22:03 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_pstr(char *str, t_f *ar)
{
	int		i;

	i = 0;
	if (!str)
	{
		while (i < ar->p_l && i < 6)
		{
			ft_putchar("(null)"[i], ar);
			i++;
		}
		return ;
	}
	while (*str && i < ar->p_l)
	{
		ft_putchar(*str, ar);
		str++;
		i++;
	}
}

void	prec_s(t_f *ar, char mode)
{
	char	*str;
	int		len;

	str = (char *)va_arg(ar->arg, char *);
	len = ft_strlen(str) + 1;
	if (!str && ar->p_l > 5)
		len = 6;
	if (mode == 'm')
		put_pstr(str, ar);
	while (len - ar->p_w + ar->p_l < ar->p_w - 1)
	{
		ft_putchar(' ', ar);
		len++;
	}
	if (mode == 'n')
		put_pstr(str, ar);
}
