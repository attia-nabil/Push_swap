/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nattia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 23:42:12 by nattia            #+#    #+#             */
/*   Updated: 2022/05/14 23:42:14 by nattia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	f;
	size_t	n_len;
	char	*s;

	s = (char *)haystack;
	if (!haystack && needle && !len)
		return (NULL);
	if (*needle == '\0' || haystack == needle)
		return (s);
	i = 0;
	n_len = ft_strlen(needle);
	while (s[i] && i < len)
	{
		f = 0;
		while (s[i + f] && needle[f] && i + f < len && s[i + f] == needle[f])
			f++;
		if (f == n_len)
			return (s + i);
		i++;
	}
	return (NULL);
}
