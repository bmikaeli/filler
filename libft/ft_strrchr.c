/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 20:25:06 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/10 15:14:57 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		length;

	str = (char *)s;
	length = ft_strlen(str);
	while (length--)
	{
		if (str[length] == (char)c)
			return (&(str[length]));
	}
	if (c == 0)
		return (&(str[ft_strlen(str)]));
	return (NULL);
}
