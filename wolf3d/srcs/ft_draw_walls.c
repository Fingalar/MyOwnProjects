/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 14:28:19 by tmertz            #+#    #+#             */
/*   Updated: 2015/01/27 16:16:22 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <libft.h>

void	ft_draw_walls(int draw_start, int draw_end, t_wolf *wolf, int j)
{
	int		i;

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

int		ft_count_lines(void)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open("map", O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Error there is no map anymore !", 2);
		return (-1);
	}
	while (get_next_line(fd, &line) > 0)
		i++;
	close (fd);
	return (i);
}
