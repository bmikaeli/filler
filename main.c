/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 13:42:48 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/14 20:50:46 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

void	get_info(char *line, t_struct *coucou)
{
	if (ft_strstr(line, "Plateau") != 0)
	{
		coucou->tmpmap = ft_strsplit(line, ' ');
		coucou->map_w = ft_atoi(coucou->tmpmap[2]);
		coucou->map_h = ft_atoi(coucou->tmpmap[1]);
	}
	if (ft_strstr(line, "Piece") != 0)
	{
		coucou->tmppiece = ft_strsplit(line, ' ');
		coucou->piece_w = ft_atoi(coucou->tmppiece[2]);
		coucou->piece_h = ft_atoi(coucou->tmppiece[1]);
	}
	if (ft_strstr(line, "exec p1") != 0)
	{
		coucou->tmpplayer = ft_strsplit(line, ' ');
		coucou->p1 = coucou->tmpplayer[4];
	}
	if (ft_strstr(line, "exec p2") != 0)
	{
		coucou->tmpplayer = ft_strsplit(line, ' ');
		coucou->p2 = coucou->tmpplayer[4];
	}
}

void	get_full_map(char *line, t_struct *coucou)
{
	static int i = 0;
	int j;
	int z;

	j = 0;
	z = 0;
	if (coucou->map_w != 0 && coucou->piece_w == 0)
	{
		while (line[j] != '.')
		{
			j++;
		}
		while (line[j] <= coucou->map_w)
		{
			coucou->map[i][z] = line[j];
			j++;
			z++;
		}
		i++;
		ft_putstr_fd(coucou->map[i], 2);
	}
}

int	main(void)
{
	t_struct	coucou;
	char 		*line;

	coucou.piece_w = 0;
	coucou.map_w = 0;
	while (get_next_line(1, &line))
	{
		get_full_map(line, &coucou);
		get_info(line, &coucou);
	}
	return (0);
}
