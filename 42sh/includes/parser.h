/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyguel <nyguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 18:27:05 by tmertz            #+#    #+#             */
/*   Updated: 2014/06/06 19:42:11 by nyguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "structs.h"
# include "lexer.h"
# include "grammar.h"
# include "parsing_tools.h"
# include "../libft/libft.h"

t_tree		*ft_parser(t_list *tokens);
t_elem		*ft_find_highest_priority(t_list *tokens, int priority);
t_tree		*ft_parser_make_tree(t_tree *tree, t_list *tokens,
									t_node *node, int dir);
t_cmd		*ft_create_cmd(t_list *tokens);
t_elem		*ft_find_farest_redirection(t_elem *elem);
void		ft_add_redirections_to_tree(t_tree *tree, t_list *tokens
									, t_node *node, t_elem *elem);
void		ft_add_others_to_tree(t_tree *tree, t_list *tokens
									, t_node *node, int dir);
void		ft_add_cmd_to_tree(t_tree *tree, t_list *tokens,
									t_node *node, int dir);
t_cmd		*ft_create_cmd(t_list *tokens);

#endif
