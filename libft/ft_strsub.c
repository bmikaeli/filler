/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 12:49:08 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/10 15:14:32 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char			*dest;
	unsigned int	i;

	dest = (char *)malloc(sizeof(*dest) * (len + 1));
	i = 0;
	if (!dest)
		return (NULL);
	while (i < len)
		dest[i++] = s[start++];
	dest[i] = '\0';
	return (dest);
}
