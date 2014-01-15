/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 13:42:48 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/15 19:15:19 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int		main(void)
{
	t_struct	coucou;
	char		*line;
	coucou.i = 0;
	coucou.piece_w = 0;
	coucou.map_w = 0;
	coucou.start_O_y = 0;
	coucou.start_O_x = 0;
	int i = 0;

	while (get_next_line(0, &line) > 0)
	{
		get_full_map(line, &coucou);
		get_info(line, &coucou);
		get_piece(&coucou, line);
		if (where_to_print(&coucou) == 1 && i > 3)
			break;
		i++;
	}

	return (0);
}
