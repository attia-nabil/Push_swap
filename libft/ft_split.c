/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nattia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 23:41:15 by nattia            #+#    #+#             */
/*   Updated: 2022/05/14 23:41:17 by nattia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_rows(char const *s, char c)
{
	int	r;
	int	i;

	i = 0;
	r = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			r++;
		i++;
	}
	return (r);
}

static int	row_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static void	leak(char **split, int r)
{
	int	i;

	i = -1;
	while (++i < r)
		free(split[i]);
	free(split);
}

static void	write_split(char **split, char const *s, char c, int r)
{
	int	i;
	int	j;
	int	l;

	i = -1;
	while (++i < r)
	{
		while (*s == c)
			s++;
		l = row_len(s, c);
		split[i] = (char *)malloc(sizeof(char) * (l + 1));
		if (!split[i])
			leak(split, i);
		j = -1;
		while (++j < l)
			split[i][j] = *s++;
		split[i][j] = '\0';
	}
}

char	**ft_split(char const *s, char c)
{
	char	**rtn;
	int		r;

	if (!s)
		return (NULL);
	r = count_rows(s, c);
	rtn = (char **)malloc(sizeof(char *) * (r + 1));
	if (!rtn)
		return (NULL);
	write_split(rtn, s, c, r);
	rtn[r] = NULL;
	return (rtn);
}
