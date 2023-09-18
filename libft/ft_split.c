/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 20:21:25 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/05/24 22:36:14 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_rows(const char *str, char c)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (*str)
	{
		if (*str != c && flag == 0)
		{
			flag = 1;
			i++;
		}
		else if (*str == c)
			flag = 0;
		str++;
	}
	return (i);
}

static int	count_cols(char const *str, char c, int i)
{
	int	len;

	len = 0;
	while (str[i] != c && str[i])
	{
		len++;
		i++;
	}
	return (len);
}

static void	ft_free(char **arr, int j)
{
	while (j-- > 0)
		free(arr[j]);
	free(arr);
}

char	**ft_split(char const *str, char c)
{
	int		i;
	int		j;
	int		words;
	char	**arr;

	i = 0;
	j = -1;
	words = count_rows(str, c);
	arr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!(arr))
		return (NULL);
	while (++j < words)
	{
		while (str[i] == c)
			i++;
		arr[j] = ft_substr(str, i, count_cols(str, c, i));
		if (!(arr[j]))
		{
			ft_free(arr, j);
			return (NULL);
		}
		i += count_cols(str, c, i);
	}
	arr[j] = 0;
	return (arr);
}
