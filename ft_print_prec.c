/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_prec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:41:38 by sthitiku          #+#    #+#             */
/*   Updated: 2022/04/30 14:39:42 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_prec(char spec, t_f *ar, char mode)
{
	if (spec == 's')
		prec_s(ar, mode);
	else if (spec == 'd' || spec == 'i')
		prec_d(ar, mode);
	else if (spec == 'u')
		prec_u(ar, mode);
	else if (spec == 'x' || spec == 'X')
		prec_base(ar, mode, spec);
}

void	ft_print_prec(char *flag, t_f *ar)
{
	char	**prec;
	char	mode;
	int		i;

	prec = ft_split(flag, '.');
	i = 1;
	while (flag[i] == '-')
		i++;
	if (flag[1] == '-')
		i--;
	ar->p_w = ft_atoi(&prec[0][i]);
	// printf("p_w = %d\n", ar->p_w);
	ar->p_l = ft_atoi(prec[1]);
	mode = 'n';
	if (ar->p_w < 0)
	{
		ar->p_w *= -1;
		mode = 'm';
	}
	check_prec(flag[ft_strlen(flag) - 1], ar, mode);
	free(prec[0]);
	free(prec[1]);
	free(prec);
}