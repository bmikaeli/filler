/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 15:23:57 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/10 15:14:41 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*elem;

	elem = malloc(sizeof(*elem));
	if (!elem)
		return (NULL);
	if (content)
	{
		elem->content = (void *)content;
		elem->content_size = content_size;
	}
	else
	{
		elem->content = NULL;
		elem->content_size = 0;
	}
	elem->next = NULL;
	return (elem);
}
