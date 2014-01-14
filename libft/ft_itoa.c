/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 12:07:03 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/10 15:14:37 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_cut_itoa(int *n, int *div, int *i, char **str)
{
	int		m;

	*i = 2;
	*div = 1;
	m = 0;
	if (*n < 0)
	{
		while (*n / *div < -9)
		{
			*div = *div * 10;
			*i = *i + 1;
		}
		m++;
	}
	else
	{
		while (*n / *div > 9)
		{
			*div = *div * 10;
			*i = *i + 1;
		}
	}
	*str = (char *)malloc(sizeof(**str) * (*i + m));
	return (m);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		div;
	int		i;
	int		m;

	m = ft_cut_itoa(&n, &div, &i, &str);
	if (!str)
		return (NULL);
	i = 0;
	if (m)
	{
		(str[i]) = '-';
		i++;
	}
	while (div)
	{
		if (m)
			str[i] = ((n / div) % 10) * (-1) + '0';
		else
			str[i] = (n / div) % 10 + '0';
		div /= 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}
