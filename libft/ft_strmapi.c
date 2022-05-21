/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nattia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 23:42:04 by nattia            #+#    #+#             */
/*   Updated: 2022/05/14 23:42:05 by nattia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*rtn;
	int		i;

	if (!s || !f)
		return (NULL);
	rtn = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!rtn)
		return (NULL);
	i = 0;
	while (s[i])
	{
		rtn[i] = f(i, *(s + i));
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}
