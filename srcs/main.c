/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 12:13:04 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/22 17:14:24 by bmikaeli         ###   ########.fr       */
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

int		ft_setplayer(t_env *env)
{
	char	*line;

	line = 0;
	get_next_line(0, &line);
	if (line == 0)
		return (-1);
	if (ft_strstr(line, "exec p1"))
	{
		env->carac = 'O';
		env->caracNew = 'o';
	}
	else if (ft_strstr(line, "exec p2"))
	{
		env->carac = 'X';
		env->caracNew = 'x';
	}
	else
	{
		env->carac = 0;
		env->caracNew = 0;
		free(line);
		return (-1);
	}
	free(line);
	return (0);
}

int		main(void)
{
	t_env	env;

	if (ft_setplayer(&env) == -1)
		return (-1);
	while (load_map(&env) != -1 && load_piece(&env) != -1)
	{
		env.best_x = env.width;
		env.best_y = env.height;
		env.best_score = env.width + env.height;
		if (ft_search(&env) == 1)
			return(0);
	}
	return (0);
}
