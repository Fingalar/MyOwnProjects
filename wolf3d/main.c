/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz </var/mail/tmertz>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 01:40:47 by tmertz            #+#    #+#             */
/*   Updated: 2014/01/12 23:26:33 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "wolf3d.h"
#include <mlx.h>
#include "libft/libft.h"

int		main(int argc, char **argv)
{
	t_wolf	*wolf;

	wolf = (t_wolf *)malloc(sizeof(t_wolf *) * 1);
	if (argc == 1)
		return (1);
	if (argc > 2)
		return (1);
	else
		ft_wolf3d_parser(wolf, argv);
	ft_init_wolf3d(wolf);
	mlx_key_hook(wolf->win, key_hook, wolf);
	mlx_expose_hook(wolf->win, ft_expose_hook, wolf);
	mlx_loop(wolf->mlx);
	return (0);
}

void	ft_wolf3d_parser(t_wolf *wolf, char **argv)
{
	char		**split;
	int			i;
	int			j;
	int			fd;
	char		*line;

	j = 0;
	i = 0;
	wolf->map = (int **)malloc(sizeof(int **) * 1);
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) != 0)
	{
		split = ft_strsplit(line, ' ');
		while (split[i] != NULL)
			i++;
		wolf->map[j] = malloc(sizeof(int) * i);
		i = 0;
		while (split[i] != NULL)
		{
			wolf->map[j][i] = ft_atoi(split[i]);
			i++;
		}
		j++;
	}
}

void	ft_init_wolf3d(t_wolf *wolf)
{
	wolf->mlx = mlx_init();
	wolf->win = mlx_new_window(wolf->mlx, 640, 300, "Wolf3D");
	wolf->img = mlx_new_image(wolf->mlx, 640, 300);
	wolf->adr = (int *)mlx_get_data_addr(wolf->img, &(wolf->bits),
						&(wolf->size_line), &(wolf->endian));
	wolf->pos_x = 3;
	wolf->pos_y = 3;
	wolf->dir_x = -1;
	wolf->dir_y = 0;
	wolf->plane_x = 0;
	wolf->plane_y = 0.66;
	wolf->move = 0.8;
	wolf->rotation = 0.3;
}

int		ft_expose_hook(t_wolf *wolf)
{
	ft_bzero(wolf->adr, (MAP_W * MAP_H) * 4);
	ft_wolf3d_set_sky_and_ground(wolf);
	ft_wolf3d_raycasting(wolf);
	mlx_put_image_to_window(wolf->mlx, wolf->win, wolf->img, 0, 0);
	return (0);
}

void	ft_wolf3d_set_sky_and_ground(t_wolf *wolf)
{
	int		i;
	int		j;

	i = 0;
	while (i < 150)
	{
		j = 0;
		while (j < 640)
		{
			wolf->adr[i * MAP_W + j] = 0x88C0F0;
			j++;
		}
		i++;
	}
	while (i < 300)
	{
		j = 0;
		while (j < 640)
		{
			wolf->adr[i * MAP_W + j] = 0x5E3A3A;
			j++;
		}
		i++;
	}
}
