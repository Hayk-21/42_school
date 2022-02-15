/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakoyan <hsakoyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 20:49:19 by hsakoyan          #+#    #+#             */
/*   Updated: 2021/11/02 21:02:43 by hsakoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char				*ft_strtok_r(char *str, const char *sep, char **lasts)
{
	char			*w;

	if (!str)
		str = *lasts;
	while (*str && ft_strchr(sep, *str))
		++str;
	if (*str == '\0')
		return (NULL);
	w = str;
	while (*str && !ft_strchr(sep, *str))
		++str;
	if (*str)
		*str++ = '\0';
	*lasts = str;
	return (w);
}

char				*ft_strtok(char *str, const char *sep)
{
	static char		*ptr;

	return (ft_strtok_r(str, sep, &ptr));
}
