/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 12:48:50 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/10 15:14:34 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		way;

	i = 0;
	way = 0;
	if (!*s2)
		return ((char*)s1);
	while (s1[i])
	{
		i -= way;
		way = 0;
		j = 0;
		while (s1[i] == s2[j])
		{
			way++;
			j++;
			i++;
			if (s2[j] == '\0')
				return ((char*) &s1[i - way]);
		}
			i++;
	}
	return (NULL);
}
