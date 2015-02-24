/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 15:56:46 by tmertz            #+#    #+#             */
/*   Updated: 2015/01/27 16:14:15 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# define MAP_W 1280
# define MAP_H 600

# include <stdio.h>

typedef struct	s_wolf
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*adr;
	int			*size_lines;
	int			**map;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	int			side;
	int			size_line;
	int			bits;
	int			endian;
	double		wall_dist;
	double		plane_x;
	double		plane_y;
	double		cam_x;
	double		raydir_x;
	double		raydir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		raypos_x;
	double		raypos_y;
	int			step_x;
	int			step_y;
	double		rotation;
	double		move;
}				t_wolf;

void			ft_wolf3d_init(t_wolf *wolf);
void			ft_init_wolf3d(t_wolf *wolf);
void			ft_wolf3d_parser(t_wolf *wolf);
void			ft_wolf3d_raycasting(t_wolf *wolf);
void			ft_wolf3d_direction(t_wolf *wolf);
void			ft_wolf3d_draw_col(t_wolf *wolf, int j);
void			ft_wolf3d_do_dda(t_wolf *wolf);
int				key_hook(int keycode, t_wolf *wolf);
void			ft_wolf3d_calc_vectors(t_wolf *wolf, int i);
void			ft_wolf3d_set_sky_and_ground(t_wolf *wolf);
int				ft_expose_hook(t_wolf *wolf);
void			ft_wolf3d_turn_right(t_wolf *wolf);
void			ft_wolf3d_turn_left(t_wolf *wolf);
void			ft_wolf3d_move_backward(t_wolf *wolf);
void			ft_wolf3d_move_forward(t_wolf *wolf);
void			ft_draw_walls(int draw_start, int draw_end,
								t_wolf *wolf, int j);
int				ft_count_lines(void);

#endif
