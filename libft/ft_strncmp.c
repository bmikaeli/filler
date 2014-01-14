/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 12:39:42 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/10 15:14:55 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int		i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while ((s1[i] == s2[i]) && (s1[i] != '\0') && (i < n))
		i++;
	return (s1[i] - s2[i]);
}
