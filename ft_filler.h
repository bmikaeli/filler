/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 14:01:42 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/21 18:58:10 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H

# include <unistd.h>
# include "libft/includes/libft.h"

typedef struct s_struct
{
	char	data[999][999];
	int		weight;
	int		high;
	int		final_x;
	int		final_y;
	int		i;
	int		j;
	int		x;
	int		y;
}				t_struct;
#endif
