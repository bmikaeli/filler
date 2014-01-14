/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 13:14:57 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/10 15:14:57 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int		nb;
	size_t	i;

	nb = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			nb++;
		}
	}
	return (nb);
}

char		**ft_strsplit(char const *s, char c)
{
	size_t	nb;
	size_t	i;
	size_t	j;
	char	**tmp;

	i = 0;
	j = 0;
	nb = 0;
	tmp = (char **) malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	while (s[i] != '\0')
	{
		if (s[i] != c)
			nb++;
		i++;
		if ((nb != 0) && ((s[i] == c) || (s[i] == '\0')))
		{
			tmp[j] = ft_strnew(nb);
			tmp[j] = ft_strncpy(tmp[j], &s[i - nb], nb);
			nb = 0;
			j++;
		}
	}
	tmp[j] = '\0';
	return (tmp);
}
