/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 18:51:17 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/15 19:15:21 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

void	print_result(int x, int y)
{
	ft_putnbr_fd(x, 1);
	ft_putstr_fd(" ", 1);
	ft_putnbr_fd(y, 1);
}

int		could_be_print_here(int x, int y, t_struct *coucou)
{
	if (coucou->map[y][x] && coucou->map[y + coucou->piece_h][x + coucou->piece_w]
		&& coucou->map[x - coucou->piece_h][coucou->piece_w])
		return (1);
	return (0);
}

int		where_to_print(t_struct *coucou)
{
	int	maybe_x;
	int	maybe_y;

	maybe_y = coucou->start_X_y;
	maybe_x = coucou->start_X_x;
	if (could_be_print_here(maybe_x, maybe_y, coucou) == 1)
		print_result(maybe_x, maybe_y);
	return(1);
}
