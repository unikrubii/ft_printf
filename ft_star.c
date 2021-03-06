/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 17:15:48 by sthitiku          #+#    #+#             */
/*   Updated: 2022/05/06 14:32:35 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	one_star_f(t_f *ar, char *tmp)
{
	ar->star1 = (int)va_arg(ar->arg, int);
	ar->st_v1 = ft_itoa(ar->star1);
	ar->star2 = ft_atoi(tmp + 1);
	ar->st_v2 = ft_itoa(ar->star2);
}

void	one_star(char *flag, t_f *ar)
{
	char	*tmp;

	tmp = flag;
	while (*tmp != '.')
		tmp++;
	if (*(tmp + 1) == '*')
	{
		ar->star1 = ft_atoi(flag + 1);
		ar->tmp = ar->star1;
		if (ar->star1 < 0)
			ar->star1 *= -1;
		ar->st_v1 = ft_itoa(ar->star1);
		ar->star2 = (int)va_arg(ar->arg, int);
		ar->tmp2 = ar->star2;
		if (ar->star2 < 0)
			ar->star2 = 1;
		if (ar->star1 == 0 && ar->tmp2 < 0)
			ar->star2 = -1;
		ar->st_v2 = ft_itoa(ar->star2);
	}
	else
		one_star_f(ar, tmp);
}

void	cx_arg2(char *flag, t_f *ar)
{
	ar->star1 = (int)va_arg(ar->arg, int);
	ar->tmp = ar->star1;
	if (ar->star1 < 0)
		ar->star1 *= -1;
	ar->st_v1 = ft_itoa(ar->star1);
	ar->star2 = (int)va_arg(ar->arg, int);
	ar->tmp2 = ar->star2;
	if ((ar->tmp <= 1 || ar->star2 < ar->tmp) && ar->star2 < 0)
		ar->star2 = 1;
	else if (ar->star2 < -1 && cx_f(flag, '0'))
		ar->star2 *= -1;
	ar->st_v2 = ft_itoa(ar->star2);
	ar->star_l = d_int(ar->star1) + d_int(ar->star2);
	if ((ar->tmp > 1 && ar->tmp2 < 0))
	{
		ar->star2 = -1;
		return ;
	}
	if (ar->tmp2 < 0 && flag[ft_strlen(flag) - 1] == 's')
		ar->star2 = -1;
}

void	cx_arg(char *flag, t_f *ar)
{
	if (cnt_star(flag) == 1)
	{
		if (cx_f(flag, '.'))
			one_star(flag, ar);
		else
		{
			ar->star1 = (int)va_arg(ar->arg, int);
			ar->tmp = ar->star1;
			if (ar->star1 < 0)
				ar->star1 *= -1;
			ar->st_v1 = ft_itoa(ar->star1);
		}
		ar->star_l = d_int(ar->star1) + d_int(ar->star2);
	}
	else
		cx_arg2(flag, ar);
}

char	*parse_star(char *flag, t_f *ar)
{
	int		len;
	int		i;
	char	*new_flag;

	cx_arg(flag, ar);
	len = 3 + cx_f(flag, '-') + cx_f(flag, '0') + cx_f(flag, '.') + ar->star_l;
	new_flag = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	new_flag[i++] = '%';
	if (cx_f(flag, '-') || ar->tmp < 0)
		new_flag[i++] = '-';
	if (cx_f(flag, '0'))
		new_flag[i++] = '0';
	ft_strlcpy(&new_flag[i], ar->st_v1, d_int(ar->tmp) + 1);
	i += ft_strlen(ar->st_v1);
	if (cx_f(flag, '.') && ar->star2 != -1)
	{
		new_flag[i++] = '.';
		ft_strlcpy(&new_flag[i], ar->st_v2, ft_strlen(ar->st_v2) + 1);
		i += ft_strlen(ar->st_v2);
	}
	new_flag[i++] = flag[ft_strlen(flag) - 1];
	new_flag[i] = '\0';
	free(flag);
	return (new_flag);
}
