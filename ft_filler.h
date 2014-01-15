/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 13:42:54 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/15 18:58:15 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H
# include <stdio.h>
# include "libft/includes/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

typedef	struct	s_struct
{
	int		map_w;
	int		map_h;
	char	**tmpmap;
	char	**tmppiece;
	int		piece_h;
	int		piece_w;
	char	*p1;
	char	*p2;
	char	**tmpplayer;
	char	map[100][100];
	char	piece[10][10];
	int		i;
	int		j;
	int		start_X_x;
	int		start_X_y;
	int		start_O_x;
	int		start_O_y;
	int		head_of_piece_x;
	int		head_of_piece_y;
	int		final_print_x;
	int		final_print_y;
}				t_struct;

void	get_info(char *line, t_struct *coucou);
void	get_full_map(char *line, t_struct *coucou);
void	get_piece(t_struct *coucou, char *line);
void	print_result(int x, int y);
int		could_be_print_here(int x, int y, t_struct *coucou);
int		where_to_print(t_struct *coucou);
int		get_start_location(t_struct *coucou, char *line);

#endif
