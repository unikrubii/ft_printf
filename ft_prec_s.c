/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 22:30:09 by sthitiku          #+#    #+#             */
/*   Updated: 2022/05/04 00:03:10 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_pstr(char *str, t_f *ar)
{
	int		i;

	i = 0;
	if (!str)
	{
		if (ar->p_l > 6)
			while (i < ar->p_l && i < 6)
			{
				ft_putchar("(null)"[i], ar);
				i++;
			}
		return (i);
	}
	while (*str && i < ar->p_l)
	{
		ft_putchar(*str, ar);
		str++;
		i++;
	}
	return (i);
}

void	prec_s(t_f *ar, char mode)
{
	char	*str;
	int		len;

	str = (char *)va_arg(ar->arg, char *);
	len = ft_strlen(str) + 1;
	if (mode == 'm')
		len = put_pstr(str, ar);
	if (ar->p_l <= ft_strlen(str))
		len = ar->p_l;
	else
		len = ft_strlen(str);
	if (!str && ar->p_l > 5)
		len += 6;
	while (len < ar->p_w)
	{
		ft_putchar(' ', ar);
		len++;
	}
	if (mode == 'n')
		put_pstr(str, ar);
}
