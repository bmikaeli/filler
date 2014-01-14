/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 12:18:32 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/10 15:14:53 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*s1;
	char	*s2;
	int		i;

	i = 0;
	s1 = (char *)s;
	s2 = (char *)malloc(sizeof(*s2) * ft_strlen(s1));
	while (s1[i] != '\0')
	{
		s2[i] = (*f)(s1[i]);
		i++;
	}
	return (s2);
}
