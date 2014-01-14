/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 10:43:48 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/10 15:14:55 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	unsigned int		i;
	unsigned int		j;

	i = 0;
	j = 0;
	while (i < n)
	{
		if (j == 0)
			s1[i] = s2[i];
		else
			s1[i] = '\0';
		if (s2[i] == '\0')
			j++;
		i++;
	}
	return (s1);
}
