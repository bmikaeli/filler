/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 09:30:56 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/10 15:14:41 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*str;
	int		i;

	str = (void *)malloc(sizeof(char) * size);
	if (!str)
		return (NULL);
	i = 0;
	while (((char*)str)[i] != 0)
	{
		((char*)str)[i] = 0;
		i++;
	}
	return (str);
}
