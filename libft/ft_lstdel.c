/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 15:56:10 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/10 15:14:38 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*cursor;

	if (!*alst)
		return ;
	while (*alst)
	{
		cursor = *alst;
		*alst = (*alst)->next;
		del(cursor->content, cursor->content_size);
		free(cursor);
	}
	*alst = NULL;
}
