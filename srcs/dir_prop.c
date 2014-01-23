/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_prop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 11:03:47 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/23 15:24:59 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <filler.h>

void	up_left(int x, int y, int score, t_env *env)
{
	static int	i = 0;

	while (y + env->piece_h < env->height)
	{
		while (x + env->piece_w < env->width)
		{
			score = (env->height - y);
			if (i % 2 == 1)
				score = (env->height - y) + (env->width - x);
			if (ft_trypiece(env, y, x) == 0 && score < env->best_score)
			{
				env->best_x = x;
				env->best_y = y;
			env->best_score = score;
			}
			x++;
		}
		x = 0;
		y++;
	}
	i++;
}

void	up_right(int x, int y, int score, t_env *env)
{
	static int	i = 0;

	while (y + env->piece_h < env->height)
	{
		while (x + env->piece_w < env->width)
		{
			score = - (env->height - y);
			if (i % 2 == 1)
				score = - (env->height - y) + (env->width - x);
			if (ft_trypiece(env, y, x) == 0 && score < env->best_score)
			{
				env->best_x = x;
				env->best_y = y;
				env->best_score = score;
			}
			x++;
		}
		x = 0;
		y++;
	}
	i++;
}

void	down_left(int x, int y, int score, t_env *env)
{
	static int	i = 0;

	while (y + env->piece_h < env->height)
	{
		while (x + env->piece_w < env->width)
		{
			score = - (env->width - x);
			if (i % 2 == 1)
				score = - (env->height - y) - (env->width - x);
			if (ft_trypiece(env, y, x) == 0 && score < env->best_score)
			{
				env->best_x = x;
				env->best_y = y;
				env->best_score = score;
			}
			x++;
		}
		x = 0;
		y++;
	}
	i++;
}

void	down_right(int x, int y, int score, t_env *env)
{
	static int	i = 0;

	while (y + env->piece_h < env->height)
	{
		while (x + env->piece_w < env->width)
		{
			score = (env->width - x);
			if (i % 2 == 1)
				score = (env->height - y) - (env->width - x);
			if (ft_trypiece(env, y, x) == 0 && score < env->best_score)
			{
				env->best_x = x;
				env->best_y = y;
				env->best_score = score;
			}
			x++;
		}
		x = 0;
		y++;
	}
	i++;
}
