/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 18:40:34 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/10 15:14:40 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin;
	t_list	*new;
	t_list	*temp;

	if (!lst)
		return (NULL);
	new = (*f)(lst);
	begin = new;
	lst = lst->next;
	while (lst)
	{
		temp = (*f)(lst);
		new->next = temp;
		new = temp;
		lst = lst->next;
	}
	return (begin);
}
