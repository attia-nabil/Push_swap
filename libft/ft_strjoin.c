/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nattia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 23:41:37 by nattia            #+#    #+#             */
/*   Updated: 2022/05/14 23:41:39 by nattia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*rtn;
	int		len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	rtn = (char *)malloc(sizeof(char) * len + 1);
	if (!rtn)
		return (NULL);
	ft_strlcpy(rtn, s1, ft_strlen(s1) + 1);
	ft_strlcat(rtn, s2, len + 1);
	return (rtn);
}
