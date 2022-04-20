/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:19:23 by sthitiku          #+#    #+#             */
/*   Updated: 2022/04/20 21:15:12 by sthitiku         ###   ########.fr       */
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

t_f		*init_s(t_f *ar);
int		flag_len(char *fmt);
void	put_nonf(t_f *ar, char c);
void	ft_putnbr(int n, t_f *ar);
void	ft_putchar(unsigned char c, t_f *ar);
void	ft_putstr(unsigned char *str, t_f *ar);
void	put_base(size_t n, t_f *ar, size_t base, char mode);
void	recur_base(size_t n, t_f *ar, size_t base, char mode);

#endif