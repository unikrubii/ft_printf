/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:19:23 by sthitiku          #+#    #+#             */
/*   Updated: 2022/04/22 21:53:50 by sthitiku         ###   ########.fr       */
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
}	t_f;

t_f		*init_s(t_f *ar);
int		ft_printf(const char *format, ...);
int		flag_len(char *fmt);
int		ft_atoi(char *s);
int		ft_isdigit(int c);
int		ft_strlen(char *s);
void	put_nonf(t_f *ar, char c);
void	ft_putnbr(long n, t_f *ar);
void	ft_putchar(unsigned char c, t_f *ar);
void	ft_putstr(unsigned char *str, t_f *ar);
void	put_base(size_t n, t_f *ar, size_t base, char mode);
void	put_sharp(char *flag, t_f *ar);
void	put_plus(int n, t_f *ar);
void	put_space(char *flag, t_f *ar, char c);
void	put_space_s(t_f *ar, int space, char c);
void	put_space_int(t_f *ar, int space);
void 	put_zero(char *flag, t_f *ar);
void	z_int(int width, t_f *ar);
void	recur_base(size_t n, t_f *ar, size_t base, char mode);

#endif