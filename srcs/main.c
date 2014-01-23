/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 12:13:04 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/23 12:29:50 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <get_next_line.h>
#include <filler.h>

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
			return (0);
	}
	return (0);
}
