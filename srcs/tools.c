/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 16:11:55 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/22 11:56:54 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int		my_champ(t_env *env, int y, int x)
{
	if (env->map[y][x] == env->carac || env->map[y][x] == env->caracNew)
		return (1);
	else
		return (0);
}

int		opponent(t_env *env, int y, int x)
{
	if (env->map[y][x] != env->carac && env->map[y][x] != env->caracNew\
	&& env->map[y][x] != '.')
		return (1);
	else
		return (0);
}
