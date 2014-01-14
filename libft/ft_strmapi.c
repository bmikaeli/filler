/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 12:27:10 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/10 15:14:54 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*s1;
	char	*s2;
	int		i;

	i = 0;
	s1 = (char *)s;
	s2 = (char *)malloc(sizeof(*s2) * ft_strlen(s1));
	while (s1[i] != '\0')
	{
		s2[i] = (*f)(i, s1[i]);
		i++;
	}
	return (s2);
}
