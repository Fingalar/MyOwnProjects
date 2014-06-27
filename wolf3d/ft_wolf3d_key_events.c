/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf3d_key_events.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 20:17:47 by tmertz            #+#    #+#             */
/*   Updated: 2014/01/12 23:29:32 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "wolf3d.h"
#include <math.h>
#include <mlx.h>
#include <stdlib.h>

int		key_hook(int keycode, t_wolf *wolf)
{

	if (keycode == 65307)
		exit(0);
	if (keycode == 65363)
		ft_wolf3d_turn_right(wolf);
	else if (keycode == 65361)
		ft_wolf3d_turn_left(wolf);
	else if (keycode == 65362)
		ft_wolf3d_move_forward(wolf);
	else if (keycode == 65364)
		ft_wolf3d_move_backward(wolf);
	return (1);
}

void    ft_wolf3d_turn_left(t_wolf *wolf)
{
	double old_dir_x;
	double old_plane_x;

	old_plane_x = wolf->plane_x;
	old_dir_x = wolf->dir_x;
	wolf->dir_x = wolf->dir_x * cos(wolf->rotation)
		- wolf->dir_y * sin(wolf->rotation);
	wolf->dir_y = old_dir_x * sin(wolf->rotation)
		+ wolf->dir_y * cos(wolf->rotation);
	wolf->plane_x = wolf->plane_x * cos(wolf->rotation)
		- wolf->plane_y * sin(wolf->rotation);
	wolf->plane_y = old_plane_x * sin(wolf->rotation)
		+ wolf->plane_y * cos(wolf->rotation);
	ft_expose_hook(wolf);
}

void	ft_wolf3d_turn_right(t_wolf *wolf)
{
	double old_dir_x;
	double old_plane_x;

	old_plane_x = wolf->plane_x;
	old_dir_x = wolf->dir_x;
	wolf->dir_x = wolf->dir_x * cos(-(wolf->rotation))
		- wolf->dir_y * sin(-(wolf->rotation));
	wolf->dir_y = old_dir_x * sin(-(wolf->rotation))
		+ wolf->dir_y * cos(wolf->rotation * -1);
	wolf->plane_x = wolf->plane_x * cos(-(wolf->rotation))
		- wolf->plane_y * sin(wolf->rotation * - 1);
	wolf->plane_y = old_plane_x * sin(-(wolf->rotation))
		+ wolf->plane_y * cos(-(wolf->rotation));
	ft_expose_hook(wolf);
}

void	ft_wolf3d_move_forward(t_wolf *wolf)
{
	int		x;
	int		y;
	int		x1;
	int		y1;

	x = wolf->pos_x + wolf->dir_x * wolf->move;
	y = wolf->pos_y;
	x1 = wolf->pos_x;
	y1 = wolf->pos_y + wolf->dir_y * wolf->move;
	if(wolf->map[x][y] == 0)
		wolf->pos_x += wolf->dir_x * wolf->move;
	if(wolf->map[x1][y1] == 0)
		wolf->pos_y += wolf->dir_y * wolf->move;
	ft_expose_hook(wolf);
}

void	ft_wolf3d_move_backward(t_wolf *wolf)
{
	int		x;
	int		y;
	int		x1;
	int		y1;

	x = wolf->pos_x - wolf->dir_x * wolf->move;
	y = wolf->pos_y;
	x1 = wolf->pos_x;
	y1 = wolf->pos_y - wolf->dir_y * wolf->move;
	if(wolf->map[x][y] == 0)
		wolf->pos_x -= wolf->dir_x * wolf->move;
	if(wolf->map[x1][y1] == 0)
		wolf->pos_y -= wolf->dir_y * wolf->move;
	ft_expose_hook(wolf);
}
