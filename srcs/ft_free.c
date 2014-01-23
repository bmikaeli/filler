/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 11:02:36 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/23 11:02:51 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <get_next_line.h>
#include <filler.h>

void	ft_freetab(char **tab)
{
	int	i;

	i = 0;
	while (tab[++i])
	{
		free(tab[i]);
		tab[i] = 0;
	}
	free(tab);
}

void	ft_free(t_env *env)
{
	ft_freetab(env->map);
	env->map = 0;
	ft_freetab(env->piece);
	env->piece = 0;
	env->best_x = 0;
	env->best_y = 0;
	env->best_score = 0;
}
