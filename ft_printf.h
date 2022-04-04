/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 19:51:36 by sthitiku          #+#    #+#             */
/*   Updated: 2022/04/05 02:39:55 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_printf(const char *fmt, ...);
int		print_c(va_list arg);
int		check_flags(va_list arg, const char *fmt);
int		recur_base(size_t n, size_t base, int len, int p_mode);
int		print_str(va_list arg);
int		ft_putnbr_base(va_list arg, size_t base, char mode);
int		ft_putnbr(int n, int len);
int		ft_put_di(va_list arg);
void	ft_puthex(int n, int mode);

#endif