/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 20:36:16 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/10 15:14:56 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (!*s2)
		return ((char*)s1);
	while (s1[i] && n)
	{
		j = 0;
		if (s1[i] == s2[j])
		{
			while (s1[i + j] == s2[j] && n)
			{
				j++;
				if (s2[j] == '\0')
					return ((char*)(s1 + i));
				n--;
			}
			n += j - 1;
		}
		else
			n--;
		i++;
	}
	return (NULL);
}
