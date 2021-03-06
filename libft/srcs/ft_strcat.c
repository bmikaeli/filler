/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:07:22 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/22 11:38:40 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(s1);
	while (*(s2 + i))
	{
		*(s1 + j) = *(s2 + i);
		i++;
		j++;
	}
	*(s1 + j) = 0;
	return (s1);
}

