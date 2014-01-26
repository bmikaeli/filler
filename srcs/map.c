/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 13:13:40 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/26 15:43:58 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <get_next_line.h>
#include <libft.h>
#include <filler.h>

static int	set_size(int *height, int *width)
{
	char	**tmp;
	char	*line;

	line = 0;
	if (get_next_line(0, &line) != 1)
		return (-1);
	if (line == 0)
		return (-1);
	tmp = ft_strsplit(line, ' ');
	*height = ft_atoi(tmp[1]);
	*width = ft_atoi(tmp[2]);
	ft_freetab(tmp);
	tmp = 0;
	free(line);
	return (0);
}

int			load_map(t_env *env)
{
	char	*line;
	int		i;
	char	**tmp;

	i = 0;
	if (set_size(&env->height, &env->width) == -1)
		return (-1);
	env->map = (char **)malloc(sizeof(line) * (env->height + 1));
	get_next_line(0, &line);
	free(line);
	while (i < env->height)
	{
		if (get_next_line(0, &line) != 1)
			return (-1);
		tmp = ft_strsplit(line, ' ');
		env->map[i] = ft_strdup(tmp[1]);
		ft_freetab(tmp);
		tmp = 0;
		free(line);
		i++;
	}
	env->map[env->height] = 0;
	return (0);
}

int			load_piece(t_env *env)
{
	char	*line;
	int		i;

	i = 0;
	if (set_size(&env->piece_h, &env->piece_w) == -1)
		return (-1);
	env->piece = (char **)malloc(sizeof(line) * (env->piece_h + 1));
	while (i < env->piece_h)
	{
		if (get_next_line(0, &line) != 1)
			return (-1);
		env->piece[i] = ft_strdup(line);
		free(line);
		i++;
	}
	env->piece[env->piece_h] = 0;
	return (0);
}
