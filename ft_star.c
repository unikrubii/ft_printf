/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 17:15:48 by sthitiku          #+#    #+#             */
/*   Updated: 2022/04/30 17:32:13 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	star_handle(char *flag, t_f *ar)
{
	int		star;
	int		len;
	char	*new_flag;

	len = 2;
	printf("%s\n", flag);
	star = (ssize_t)va_arg(ar->arg, ssize_t);
	len += count_digit_int(star);
	printf("%d\t%d\n", star, len);
	new_flag = (char *)malloc(sizeof(char) * (len + 1));
	new_flag[0] = flag[0];
	new_flag[len] = flag[len];
	// return (new_flag);
}