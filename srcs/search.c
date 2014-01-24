/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 11:41:41 by bmiakeli          #+#    #+#             */
/*   Updated: 2014/01/24 19:01:29 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <filler.h>

static int	ft_checkpos(t_env *env, t_cord *piece, int y, int x)
{
	int		ret;
	t_cord	try;

	ret = 0;
	try.x = (x < 0) ? env->width - 1 + x : x;
	try.y = (y < 0) ? env->height - 1 + y : y;
	if (env->piece[piece->y][piece->x] == '*' && my_champ(env, try.y, try.x))
		ret = 1;
	else if (env->piece[piece->y][piece->x] == '*'
			&& opponent(env, try.y, try.x))
		ret = 2;
	return (ret);
}

static void	ft_initvar(t_cord *piece, int *ret, int *hit, int *oponent)
{
	piece->x = 0;
	piece->y = 0;
	*ret = 0;
	*hit = 0;
	*oponent = 0;
}

int			ft_trypiece(t_env *env, int y, int x)
{
	int		ret;
	int		hit;
	int		oponent;
	t_cord	piece;
	int		start_x;

	ft_initvar(&piece, &ret, &hit, &oponent);
	start_x = x;
	while (piece.y < env->piece_h)
	{
		while (piece.x < env->piece_w)
		{
			ret = ft_checkpos(env, &piece, y, x);
			hit = (ret == 1) ? hit + 1 : hit;
			oponent = (ret == 2) ? oponent + 1 : oponent;
			piece.x++;
			x++;
		}
		piece.x = 0;
		piece.y++;
		x = start_x;
		y++;
	}
	return ((hit == 1 && oponent == 0) ? 0 : 1);
}

static void	ft_checkmap(t_env *env)
{
	int		x;
	int		y;
	int		score;

	x = 0;
	y = 0;
	score = 0;
	static int i = 0;
	if (i % 4 == 1 && i >= env->width)
		up_left(x, y, score, env);
	else if (i % 4 == 2 && i >= env->width)
		up_right(x, y, score, env);
	else if (i % 4 == 3)
		down_left(x, y, score, env);
	else
		down_right(x, y, score, env);
	i++;
}

int			ft_search(t_env *env)
{
	ft_checkmap(env);
	ft_putnbr(env->best_y);
	ft_putchar(' ');
	ft_putnbr(env->best_x);
	ft_putchar('\n');
	ft_free(env);
	if (env->best_x == env->height && env->best_y == env->width)
		return (1);
	return (0);
}
