/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 18:26:44 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/10 15:14:44 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char				*buf;
	char				*p2;
	char				*p1;
	unsigned int		i;

	p1 = (char *) s1;
	p2 = (char *) s2;
	buf = (char *)malloc(sizeof(*buf) * ft_strlen(p2));
	i = 0;
	while (p2[i] != '\0' && i < n)
	{
		buf[i] = p2[i];
		i++;
	}
	i = 0;
	while (buf[i] != '\0' && i < n)
	{
		p1[i] = buf[i];
		i++;
	}
	return (s1);
}
