/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 17:16:11 by tmertz            #+#    #+#             */
/*   Updated: 2014/02/23 20:43:46 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft/libft.h"

typedef struct			s_map
{
	t_list			*lines;
	int				**adj_matrix;
	int				nb_ants;
	int				start;
	int				end;
	t_list			*rooms;
	t_list			*roads;
	int				*size_roads;
	struct s_ant	**ants;
}						t_map;

typedef struct			s_room
{
	char			*name;
	int				index;
	int				weight;
	int				coord_x;
	int				coord_y;
	int				visited;
	int				end;
	int				occupied;
	struct s_room	*prev;
}						t_room;

typedef struct			s_ant
{
	int				id;
	char			*position;
	t_list			*way;
	t_elem			*room;
	int				id_pos;
}						t_ant;

t_map		*ft_lemin_parser(t_map *map);
t_map		*ft_init_map(t_map *map);
int			ft_read_instructions(t_map *map);
int			ft_add_rooms(t_map *map);
int			ft_command_check_and_add(t_map *map, char *line);
int			ft_init_room(t_map *map, char *line);
int			ft_add_links(t_map *map, char *line);
void		ft_init_matrix(t_map *map);
void		ft_add_to_matrix(t_map *map, char **split);
int			ft_get_index(char *str, t_list *rooms);
int			ft_iscommand(char *str);
int			ft_iscomment(char *str);
int			ft_links_handle_fl(t_map *map, char *line);
int			ft_isliaison(char *str);

void		ft_display_instructions(t_map *map);

void		ft_multi_pathfinding(t_map *map);
void		ft_del_road(t_list *road, t_map *map);
int			*ft_how_many_adj(t_map *map, t_elem *elem);
t_list		*ft_make_road(t_map *map, int end, int start);
t_list		*ft_get_less_weights(t_list *rooms, int weight);
t_list		*ft_dijkstra(t_map *map, int weight);
t_elem		*ft_get_n_elem(t_list *list, int i);
int			ft_get_room(t_room *room, t_list *list);
int			ft_extend_dijkstra(t_map *map, t_elem *elem, int weight);
t_elem		*ft_memcpy_room(t_elem *new_elem, t_elem *elem);
void		ft_reinitialize_rooms(t_map *map);

void		ft_init_ants(t_map *map);
void		ft_exec_lemin(t_map *map);
void		ft_write_move(t_map *map, int i);
void		ft_define_way(t_map *map, int index, int i);

#endif
