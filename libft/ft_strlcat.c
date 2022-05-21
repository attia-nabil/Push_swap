/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nattia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 23:41:47 by nattia            #+#    #+#             */
/*   Updated: 2022/05/14 23:41:49 by nattia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	rtn;
	size_t	s_len;
	size_t	d_len;

	s_len = ft_strlen(src);
	if (dstsize == 0 && !dst)
		return (s_len);
	d_len = ft_strlen(dst);
	if (d_len < dstsize)
		rtn = d_len + s_len;
	else
		rtn = s_len + dstsize;
	i = 0;
	while (src[i] && d_len + 1 < dstsize)
	{
		dst[d_len] = src[i];
		d_len++;
		i++;
	}
	dst[d_len] = '\0';
	return (rtn);
}
