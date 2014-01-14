/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 13:42:54 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/14 20:17:22 by bmikaeli         ###   ########.fr       */
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
	char 	**tmpmap;
	char	**tmppiece;
	int		piece_h;
	int		piece_w;
	char 	*p1;
	char 	*p2;
	char 	**tmpplayer;
	char	**map;
}				t_struct;
#endif
