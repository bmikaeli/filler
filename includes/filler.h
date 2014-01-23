/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <bmikaeli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 12:18:29 by bmikaeli          #+#    #+#             */
/*   Updated: 2014/01/23 11:11:56 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

typedef struct		s_env
{
	int		height;
	int		width;
	char	**map;
	char	**piece;
	int		piece_h;
	int		piece_w;
	int		best_x;
	int		best_y;
	int		best_score;
	char	carac;
	char	caracNew;
}					t_env;
typedef struct		s_cord
{
	int		x;
	int		y;
}					t_cord;
int			ft_search(t_env *env);
int			load_map(t_env *env);
int			load_piece(t_env *env);
void		ft_freetab(char **tab);
void		ft_free(t_env *env);
int			opponent(t_env *env, int y, int x);
int			my_champ(t_env *env, int y, int x);
void		up_left(int x, int y, int score, t_env *env);
void		up_right(int x, int y, int score, t_env *env);
void		down_left(int x, int y, int score, t_env *env);
void		down_right(int x, int y, int score, t_env *env);
int			ft_trypiece(t_env *env, int y, int x);

#endif
