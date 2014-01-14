/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:06:39 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/10 15:14:41 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char			*p1;
	char			*p2;
	unsigned int	i;

	p1 = (char *)s1;
	p2 = (char *)s2;
	i = 0;
	while (i < n)
	{
		p1[i] = p2[i];
		if (p2[i] == (unsigned char)c)
		{
			i++;
			return (&p1[i]);
		}
		i++;
	}
	return (NULL);
}
