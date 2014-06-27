/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 20:11:47 by tmertz            #+#    #+#             */
/*   Updated: 2014/05/24 18:30:14 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_TOOLS_H
# define PARSING_TOOLS_H
# include "../libft/libft.h"
# include "structs.h"

t_elem		*ft_priority_four(t_list *list);
t_elem		*ft_priority_three(t_list *list);
t_elem		*ft_priority_two(t_list *list);
t_elem		*ft_priority_one(t_list *list);
t_node		*ft_add_root(t_elem *elem, t_tree *tree);
t_node		*ft_add_node(t_node *node, t_elem *elem, int dir);
t_node		*ft_add_cmd_node(t_node *node, t_cmd *cmd, int dir);
t_list		*ft_sh_split_list_r(t_elem *elem, t_list *list);
t_list		*ft_sh_split_list_l(t_elem *elem, t_list *list);
t_node		*ft_add_redirection_node(t_node *node, t_elem *elem);

#endif
