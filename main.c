/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 18:10:28 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/21 19:35:30 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

void	set_struct(t_struct *map, t_struct *piece, t_struct *print);
void	print_final(t_struct *print);

void	get_map(t_struct *map, char *line)
{
	int j;
	int z;
	static int e = 0;

	j = 0;
	z = 0;
	if (map->weight != 0 && map->i < map->high && e >= 3)
	{
		while (j != 4)
			j++;
		map->j = j;
		while (j < map->weight + map->j)
		{
			map->data[map->i][z] = line[j];
			//ft_putchar_fd(map->data[map->i][z], 2);
			j++;
			z++;
		}
		map->i++;
		//ft_putchar_fd('\n', 2);
	}
	e++;
}

int		get_piece(t_struct *piece, char *line)
{
	int x = 0;
	static int y = 0;


	if (y == piece->high + 1 && piece->high != 0)
		return (0);
	if (piece->weight != 0)
	{
		while (line[x] && x <= piece->weight)
		{
			piece->data[y][x] = line[x];
			x++;
		}
		y++;
	}
	return (0);
}

void	get_info(t_struct *map, t_struct *piece, char *line)
{
	char **tmp;

	if (ft_strstr(line, "Plateau"))
	{
		tmp = ft_strsplit(line, ' ');
		map->weight = ft_atoi(tmp[2]);
		map->high = ft_atoi(tmp[1]);
	}
	if (ft_strstr(line, "Piece"))
	{
		tmp = ft_strsplit(line, ' ');
		piece->weight = ft_atoi(tmp[2]);
		piece->high = ft_atoi(tmp[1]);
	}

}
int	find_star_x(t_struct *piece)
{
	int i = 0;
	int j = 0;

	while (piece->data[i][j])
	{
		while (piece->data[i][j])
		{
			if (piece->data[i][j] == '*')
			{
				piece->final_y = i;
				piece->final_x = j;
				return (j);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (0);

}
int	find_star_y(t_struct *piece)
{
	int i = 0;
	int j = 0;

	while (piece->data[i][j])
	{
		while (piece->data[i][j])
		{
			if (piece->data[i][j] == '*')
			{
				piece->final_y = i;
				piece->final_x = j;
				return (i);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

int	where_to_print(t_struct *map, t_struct *piece)
{
	int i = 0;
	int j = 0;

	while (map->data[i][j])
	{
		while(map->data[i][j])
		{
			if ((map->data[i][j] == 'O' || map->data[i][j] == 'o') && map->data[i][j + 1] != 'o')
			{
				ft_putnbr_fd(i - find_star_y(piece), 1);
				ft_putchar_fd(' ', 1);
				ft_putnbr_fd(j - find_star_x(piece), 1);
				ft_putchar_fd('\n',1);
				return (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void	print_final(t_struct *print)
{
	ft_putnbr_fd(print->final_y - print->y, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(print->final_x - print->x, 1);
	ft_putchar_fd('\n',1);
}

void	set_struct(t_struct *map, t_struct *piece, t_struct *print)
{
	map->j = 0;
	map->i = 0;
	map->weight = 0;
	map->high = 0;
	piece->weight = 0;
	piece->high = 0;
	print->final_x = 0;
	print->final_y = 0;
	piece->final_x = 0;
	piece->final_y = 0;
}

int		main(void)
{
	t_struct piece;
	t_struct map;
	t_struct print;

	char *line;


	set_struct(&map, &piece, &print);
	while (get_next_line(0, &line))
	{

		/*ft_putstr_fd("map_high = ", 2);
		ft_putnbr_fd(map.high, 2);
		ft_putstr_fd(" | map_weight = ", 2);
		ft_putnbr_fd(map.weight, 2);
		ft_putstr_fd(" | piece_high = ", 2);
		ft_putnbr_fd(piece.high, 2);
		ft_putstr_fd(" | piece_weight = ", 2);
		ft_putnbr_fd(piece.weight, 2);
		ft_putstr_fd(" | final_x = ", 2);
		ft_putnbr_fd(print.final_x, 2);
		ft_putstr_fd(" | final_y = ", 2);
		ft_putnbr_fd(print.final_y, 2);*/
		//ft_putchar_fd('\n',2);
		get_piece(&piece, line);
		get_map(&map, line);
		get_info(&map, &piece, line);
		where_to_print(&map, &piece);
	}

	return (0);
}
