/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 22:30:09 by sthitiku          #+#    #+#             */
/*   Updated: 2022/04/29 01:42:36 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_pstr(char *str, t_f *ar)
{
	int		i;

	if (!str)
	{
		if (ar->p_l > 5)
			ft_putstr("(null)", ar);
		return ;
	}
	i = 0;
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
