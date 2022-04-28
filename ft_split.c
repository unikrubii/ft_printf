/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthitiku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 00:39:01 by sthitiku          #+#    #+#             */
/*   Updated: 2022/02/25 03:29:32 by sthitiku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	word_count(char const *s, char c)
{
	int	words;

	words = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			while (*s != c && *s)
				s++;
			words++;
		}
	}
	return (words);
}

int	word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s)
	{
		s++;
		len++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		len;
	int		words;
	int		i;
	int		j;

	words = word_count(s, c);
	arr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*s == c && *s)
			s++;
		len = word_len(s, c);
		arr[i] = (char *)malloc(sizeof(char) * (len + 1));
		j = 0;
		while (*s != c && j < len && *s)
			arr[i][j++] = *s++;
		arr[i][j] = '\0';
		i++;
	}
	arr[words] = NULL;
	return (arr);
}
