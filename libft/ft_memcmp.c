/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 19:19:00 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/10 15:14:42 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char			*str1;
	unsigned char			*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
		if (!s1 || !s2)
			return (0);
	while (n && (*str1++ == *str2++))
	n--;
	return (*(--str1) - *(--str2));
}
