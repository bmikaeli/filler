/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 14:31:27 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/14 18:42:25 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		len;
	int		j;

	if (!s)
		return (NULL);
	len = ft_strlen((char *)s) - 1;
	i = 0;
	j = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (ft_strlen(s) == i)
		return (NULL);
	while (s[len - j] == ' ' || s[len - j] == '\n' || s[len - j] == '\t')
		j++;
	str = (char *)malloc(sizeof(*str) * (len - i - j + 1));
	str = ft_strsub(s, i, len - j - i + 1);
	return (str);
}
