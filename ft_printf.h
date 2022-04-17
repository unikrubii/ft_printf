/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:19:23 by sthitiku          #+#    #+#             */
/*   Updated: 2022/04/13 23:23:12 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_f
{
	va_list	arg;
	int		len;
	int		flen;
	int		stop;
	char	*flag;
}	t_f;

void	put_char(t_f *ar, char c);
t_f		*init_s(t_f *ar);
int		flag_len(char *fmt);

#endif