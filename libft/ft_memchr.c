/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 19:25:45 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/10 15:14:42 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;

	if (!s)
		return (NULL);
	str = (char*)s;
	while (n--)
	{
		if (*str++ == (unsigned char)c)
			return (--str);
	}
	return (NULL);
}
