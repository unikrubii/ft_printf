/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 17:15:48 by sthitiku          #+#    #+#             */
/*   Updated: 2022/05/02 17:12:04 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// char	*star_handle(char *flag, t_f *ar)
// {
// 	int		len;
// 	int		i;
// 	char	*new_flag;

// 	len = ft_strlen(flag) - 1;
// 	ar->star1 = (int)va_arg(ar->arg, int);
// 	len += d_int(ar->star1);
// 	new_flag = (char *)malloc(sizeof(char) * (len + 1));
// 	if (!new_flag)
// 		return (NULL);
// 	i = 0;
// 	while (flag[i] != '*')
// 	{
// 		new_flag[i] = flag[i];
// 		i++;
// 	}
// 	ar->st_v1 = ft_itoa(ar->star1);
// 	ft_strlcpy(&new_flag[i], ar->st_v1, len);
// 	new_flag[len - 1] = flag[ft_strlen(flag) - 1];
// 	new_flag[len] = '\0';
// 	// printf("ffff = %s\n", new_flag);
// 	free(flag);
// 	free(ar->st_v1);
// 	return (new_flag);
// }

// int	star_p_size(char *flag, t_f *ar)
// {
// 	int		len;
// 	int		i;
// 	char	*new_flag;

// 	i = 0;
// 	int	s_count = 0;
// 	while (flag[i])
// 	{
// 		if (flag[i] == '*' && flag[i + 1] == '.')
// 		{
// 			ar->star1 = (int)va_arg(ar->arg, int);
// 			s_count++;
// 		}
// 		else if (flag[i] == '.' && flag[i + 1] == '*')
// 		{
// 			ar->star2 = (unsigned int)va_arg(ar->arg, unsigned int);
// 			s_count++;
// 		}
// 		i++;
// 	}
// 	len = i - s_count + d_int(ar->star1) + d_u(ar->star2, 10, 0) - 1;
// 	return (len);
// }

// char	*star_handle_p(char *flag, t_f *ar)
// {
// 	int		len;
// 	int		i;
// 	char	*new_flag;

// 	len = star_p_size(flag, ar);
// 	new_flag = (char *)malloc(sizeof(char) * (len + 1));
// 	i = 0;
// 	int	s_len = 0;
// 	int	j = 0;
// 	free(ar->st_v1);
// 	free(ar->st_v2);
// 	free(flag);
// 	return (new_flag);
// }

int	cx_f(char *flag, char c)
{
	while (*flag)
	{
		if (*flag == c)
			return (1);
		flag++;
	}
	return (0);
}

int	cnt_star(char *flag)
{
	int	count;

	count = 0;
	while (*flag)
	{
		if (*flag == '*')
		{
			count++;
		}
		flag++;
	}
	return (count);
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
		if (ar->star1 < 0)
			ar->star1 *= -1;
		ar->st_v1 = ft_itoa(ar->star1);
		ar->star2 = (unsigned int)va_arg(ar->arg, unsigned int);
		ar->st_v2 = ft_itoa(ar->star2);
	}
	else
	{
		ar->star1 = (int)va_arg(ar->arg, int);
		ar->st_v1 = ft_itoa(ar->star1);
		ar->star2 = ft_atoi(tmp + 1);
		ar->st_v2 = ft_itoa(ar->star2);
	}
}

void	cx_arg(char *flag, t_f *ar)
{
	int	tmp;

	tmp = 0;
	if (cnt_star(flag) == 1)
	{
		if (cx_f(flag, '.'))
			one_star(flag, ar);
		else
		{
			ar->star1 = (int)va_arg(ar->arg, int);
			if (ar->star1 < 0)
				tmp = ar->star1 * -1;
			ar->st_v1 = ft_itoa(tmp);
		}
	}
	else
	{
		ar->star1 = (int)va_arg(ar->arg, int);
		if (ar->star1 < 0)
			tmp = ar->star1 * -1;
		ar->st_v1 = ft_itoa(ar->star1);
		ar->star2 = (unsigned int)va_arg(ar->arg, unsigned int);
		ar->st_v2 = ft_itoa(ar->star2);
	}
	ar->star_l = d_int(ar->star1) + d_int(ar->star2);
}

char	*parse_star(char *flag, t_f *ar)
{
	int		len;
	int		i;
	char	*new_flag;

	cx_arg(flag, ar);
	len = 2 + cx_f(flag, '-') + cx_f(flag, '0') + cx_f(flag, '.') + ar->star_l;
	new_flag = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	new_flag[i++] = '%';
	if (cx_f(flag, '-') || ar->star1 < 0)
		new_flag[i++] = '-';
	if (cx_f(flag, '0'))
		new_flag[i++] = '0';
	ft_strlcpy(&new_flag[i], ar->st_v1, ft_strlen(ar->st_v1) + 1);
	i += ft_strlen(ar->st_v1);
	if (cx_f(flag, '.'))
	{
		new_flag[i++] = '.';
		ft_strlcpy(&new_flag[i], ar->st_v2, ft_strlen(ar->st_v2) + 1);
		i += ft_strlen(ar->st_v1);
	}
	new_flag[i] = flag[ft_strlen(flag) - 1];
	free(flag);
	return (new_flag);
}