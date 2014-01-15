/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 18:50:02 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/15 18:51:51 by bmikaeli         ###   ########.fr       */
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

void		get_full_map(char *line, t_struct *coucou)
{
	int j;
	int z;
	static int bla = 0;

	j = 0;
	z = 0;

	if (coucou->map_w != 0 && coucou->i < coucou->map_h && bla >= 3)
	{
		get_start_location(coucou, line);

		while (line[j] != '.')
			j++;
		coucou->j = j;
		while (j < coucou->map_w + coucou->j)
		{
			coucou->map[coucou->i][z] = line[j];
			j++;
			z++;
		}
		coucou->map[coucou->i][z] = '\0';
		coucou->i++;
	}
	bla++;
}

void	get_piece(t_struct *coucou, char *line)
{
	int w = 0;
	static int h;
	if (coucou->piece_w != 0)
	{
		while (w <= coucou->piece_w)
		{
			coucou->piece[h][w] = line[w];
			w++;
		}
	}
}

int	get_start_location(t_struct *coucou, char *line)
{
	int e;
	static int i = 0;

	e = 0;
	if (ft_strstr(line, "X") != 0)
	{
		while (line[e])
		{
			if (line[e] == 'X')
			{
				coucou->start_X_x = e - coucou->j;
				coucou->start_X_y = i;
				return (1);
			}
			e++;
		}
		e = 0;
	}
	if (ft_strstr(line, "O") != 0)
	{
		while (line[e])
		{
			if (line[e] == 'O')
			{
				coucou->start_O_x = e - coucou->j;
				coucou->start_O_y = i;
				return (1);
			}
			e++;
		}
		e = 0;
	}
	i++;
	return (0);
}

