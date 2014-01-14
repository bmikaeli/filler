/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:15:03 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/10 15:14:52 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	int				u;

	i = 0;
	j = 0;
	while (i < size && dest[i] != '\0')
		i++;
	while (src[j] != '\0' && (i + j) < (size - 1))
	{
		dest[i + j] = src[j];
		j++;
	}
	if (j != 0)
		dest[j + i] = '\0';
	u = ft_strlen((char *)src);
	return (i + u);
}
