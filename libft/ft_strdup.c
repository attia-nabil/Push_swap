/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nattia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 23:41:27 by nattia            #+#    #+#             */
/*   Updated: 2022/05/14 23:41:29 by nattia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*rtn;

	rtn = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!rtn)
		return (NULL);
	i = -1;
	while (s1[++i])
		rtn[i] = s1[i];
	rtn[i] = '\0';
	return (rtn);
}
