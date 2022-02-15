/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakoyan <hsakoyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 20:53:03 by hsakoyan          #+#    #+#             */
/*   Updated: 2021/11/02 21:00:53 by hsakoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    *ft_strdup(const char *str)
{
	int	lenght;
	char	*new_string;
	int	i;

	if (str == NULL)
		return (NULL);
	i = 0;
	lenght = ft_strlen(str);
	new_string = malloc(sizeof(char) * lenght);
	while (i < lenght)
	{
		new_string[i] = str[i];
		i++;
	}
	return (new_string);
}