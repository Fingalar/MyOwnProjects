/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 19:58:58 by tmertz            #+#    #+#             */
/*   Updated: 2014/01/12 23:21:24 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "libft/libft.h"
#include <stdlib.h>
#include "wolf3d.h"

void		ft_wolf3d_raycasting(t_wolf *wolf)
{
	int		i;

	i = 0;
	ft_wolf3d_set_sky_and_ground(wolf);
	while (i < MAP_W)
	{
		ft_wolf3d_calc_vectors(wolf, i);
		ft_wolf3d_direction(wolf);
		ft_wolf3d_do_DDA(wolf);
		ft_wolf3d_draw_col(wolf, i);
		i++;
	}
}

void	ft_wolf3d_calc_vectors(t_wolf *wolf, int i)
{
	wolf->cam_x = 2 * (double)i / (double)MAP_W - 1;
	wolf->raypos_x = wolf->pos_x;
	wolf->raypos_y = wolf->pos_y;
	wolf->raydir_x = wolf->dir_x + wolf->plane_x * wolf->cam_x;
	wolf->raydir_y = wolf->dir_y + wolf->plane_y * wolf->cam_x;
	wolf->map_x = (int)wolf->raypos_x;
	wolf->map_y = (int)wolf->raypos_y;
	wolf->delta_dist_x = sqrt(1 + (wolf->raydir_y * wolf->raydir_y)
							/ (wolf->raydir_x * wolf->raydir_x));
	wolf->delta_dist_y = sqrt(1 + (wolf->raydir_x * wolf->raydir_x)
							/ (wolf->raydir_y * wolf->raydir_y));
}

void		ft_wolf3d_direction(t_wolf *wolf)
{
	if (wolf->raydir_x < 0)
	{
		wolf->step_x = -1;
		wolf->side_dist_x = (wolf->raypos_x - wolf->map_x)
							* wolf->delta_dist_x;
	}
	else
	{
		wolf->step_x = 1;
		wolf->side_dist_x = (wolf->map_x + 1.0 - wolf->raypos_x)
			* wolf->delta_dist_x;
	}
	if (wolf->raydir_y < 0)
	{
		wolf->step_y = -1;
		wolf->side_dist_x = (wolf->raypos_y - wolf->map_y
							* wolf->delta_dist_y);
	}
	else
	{
		wolf->step_y = 1;
		wolf->side_dist_y = (wolf->map_y + 1.0 - wolf->raypos_y)
			* wolf->delta_dist_y;
	}
}

void	ft_wolf3d_do_DDA(t_wolf *wolf)
{
	int		hit;

	hit = 0;
	while (hit == 0)
	{
		if (wolf->side_dist_x < wolf->side_dist_y)
		{
			wolf->side_dist_x += wolf->delta_dist_x;
			wolf->map_x += wolf->step_x;
			wolf->side = 0;
		}
		else
		{
			wolf->side_dist_y += wolf->delta_dist_y;
			wolf->map_y += wolf->step_y;
			wolf->side = 1;
		}
		if (wolf->map[wolf->map_x][wolf->map_y] == 1)
			hit = 1;
	}
}


void		ft_wolf3d_draw_col(t_wolf *wolf, int j)
{
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		i;

	if (wolf->side == 0)
		wolf->wall_dist = fabs((wolf->map_x - wolf->raypos_x
								+ (1 - wolf->step_x) / 2)
									/ wolf->raydir_x);
	else
		wolf->wall_dist = fabs((wolf->map_y - wolf->raypos_y
								+ (1 - wolf->step_y) / 2)
									/ wolf->raydir_y);
	line_height = abs((int)(MAP_H / wolf->wall_dist));
	draw_start = (line_height * -1) / 2 + MAP_H / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + MAP_H / 2;
	if (draw_end > MAP_H)
		draw_end = MAP_H;
	i = draw_start;
	while (i < draw_end)
	{
		if (wolf->side == 1)
		{
			wolf->adr[i++ * MAP_W + j] = 0x333333;
		}
		else
		wolf->adr[i++ * MAP_W + j] = 0x777777;
	}
}
