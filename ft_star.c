/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 17:15:48 by sthitiku          #+#    #+#             */
/*   Updated: 2022/05/01 16:48:26 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*star_handle(char *flag, t_f *ar)
{
	int		len;
	int		i;
	char	*new_flag;

	len = ft_strlen(flag) - 1;
	ar->star1 = (int)va_arg(ar->arg, int);
	len += d_int(ar->star1);
	new_flag = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_flag)
		return (NULL);
	i = 0;
	while (flag[i] != '*')
	{
		new_flag[i] = flag[i];
		i++;
	}
	ar->st_v1 = ft_itoa(ar->star1);
	ft_strlcpy(&new_flag[i], ar->st_v1, len);
	new_flag[len - 1] = flag[ft_strlen(flag) - 1];
	new_flag[len] = '\0';
	// printf("ffff = %s\n", new_flag);
	free(flag);
	free(ar->st_v1);
	return (new_flag);
}

int	star_p_size(char *flag, t_f *ar)
{
	int		len;
	int		i;
	char	*new_flag;

	i = 0;
	int	s_count = 0;
	while (flag[i])
	{
		if (flag[i] == '*' && flag[i + 1] == '.')
		{
			ar->star1 = (int)va_arg(ar->arg, int);
			s_count++;
		}
		else if (flag[i] == '.' && flag[i + 1] == '*')
		{
			ar->star2 = (unsigned int)va_arg(ar->arg, unsigned int);
			s_count++;
		}
		i++;
	}
	len = i - s_count + d_int(ar->star1) + d_u(ar->star2, 10, 0) - 1;
	return (len);
}

char	*star_handle_p(char *flag, t_f *ar)
{
	int		len;
	int		i;
	char	*new_flag;

	len = star_p_size(flag, ar);
	new_flag = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	int	s_len = 0;
	int	j = 0;
	free(ar->st_v1);
	free(ar->st_v2);
	free(flag);
	return (new_flag);
}