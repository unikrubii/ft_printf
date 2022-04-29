/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:19:23 by sthitiku          #+#    #+#             */
/*   Updated: 2022/04/30 01:05:17 by sthitiku         ###   ########.fr       */
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
	int		p_w;
	int		p_l;
}	t_f;

t_f				*init_s(t_f *ar);
int				ft_printf(const char *format, ...);
int				flag_len(char *fmt);
int				ft_atoi(char *s);
int				ft_isdigit(int c);
int				ft_strlen(char *s);
int				count_digit_int(long n);
int				dot_pos(char *flag);
unsigned int	count_digit_u(size_t n, size_t base, unsigned int len);
void			get_flag(char *fmt, t_f *ar);
void			proc_bonus(char *flag, t_f *ar);
void			proc_flag(char *flag, t_f *ar);
void			put_nonf(t_f *ar, char c);
void			ft_putnbr(long n, t_f *ar);
void			ft_putchar(char c, t_f *ar);
void			ft_putstr(char *str, t_f *ar);
void			put_base(size_t n, t_f *ar, size_t base, char mode);
void			put_sharp(char *flag, t_f *ar);
void			put_plus(int n, t_f *ar);
void			put_space(char *flag, t_f *ar, char c);
void			put_space_s(t_f *ar, int space, char c);
void			put_space_int(t_f *ar, int space);
void 			put_zero(char *flag, t_f *ar);
void			put_minus(char *fl, t_f *ar);
void			minus_i(int width, t_f *ar);
void			minus_t(unsigned int width, char spec, t_f *ar);
void			minus_s(int width, t_f *ar);
void			minus_u(unsigned int width, char spec, t_f *ar);
void			z_int(int width, t_f *ar, char sp_c);
void			z_unsigned(unsigned int width, char spec, t_f *ar, char sp_c);
void			z_pointer(size_t width, t_f *ar, char sp_c);
void			z_str(int width, t_f *ar, char sp_c);
void			z_char(int width, t_f *ar, char sp_c);
void			z_put_space(t_f *ar, char sp_c, int digit);
void			ft_print_prec(char *flag, t_f *ar);
void			recur_base(size_t n, t_f *ar, size_t base, char mode);
void			put_pstr(char *str, t_f *ar);
void			prec_s(t_f *ar, char mode);
void			prec_d(t_f *ar, char mode);
void			prec_u(t_f *ar, char mode);
void			put_nbr_m(long n, t_f *ar, int len);
void			put_nbr_n(long n, t_f *ar, int len);
void			prec_base(t_f *ar, char mode, char spec);
void			prec_bx(t_f *ar, unsigned int n, char mode, char spec);
void			prec_bxm(t_f *ar, unsigned int n, int len, char spec);
char			*ft_strchr(const char *s, int c);
char			**ft_split(char const *s, char c);

#endif