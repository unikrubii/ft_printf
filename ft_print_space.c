/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:34:07 by sthitiku          #+#    #+#             */
/*   Updated: 2022/04/24 18:59:24 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_space_int(t_f *ar, int width)
{
	int	n;

	n = (int)va_arg(ar->arg, int);
	if (n >= 0)
		width++;
	while (width-- > 0)
		ft_putchar(' ', ar);
	ft_putnbr(n, ar);
}

void	put_space_s(t_f *ar, int width, char c)
{
	char	*str;
	int		len;

	str = (char *)va_arg(ar->arg, char *);
	len = ft_strlen(str);
	if (!str)
		len += 6;
	if (width > len)
		width -= len;
	else
		width = 0;
	while (width > 0)
	{
		ft_putchar(c, ar);
		width--;
	}
	ft_putstr(str, ar);
}

void	put_space(char *flag, t_f *ar, char c)
{
	int	i;
	int	width;

	width = ft_atoi(&flag[1]);
	i = 0;
	while (!(flag[i] == 's' || flag[i] == 'd' || flag[i] == 'i'))
		i++;
	if (flag[i] == 's')
		put_space_s(ar, width, c);
	else if (flag[i] == 'd' || flag[i] == 'i')
		put_space_int(ar, width);
}
