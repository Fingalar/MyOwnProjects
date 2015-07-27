/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Board.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 20:39:59 by tmertz            #+#    #+#             */
/*   Updated: 2015/04/11 22:30:48 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOARD_HPP
# define BOARD_HPP

#include "A_GameEntity.class.hpp"

class		Board {
		private :
			AGameEntity		**_matrice;
			int				_w;
			int				_h;

		public :
			Board();
			Board(Board & src);
			Board(int, int);
			~Board();

			AGameEntity		**getMatrice(void) const;
			Board &			operator=(Board & rhs);
			AGameEntity *	getMatriceValueAt(int x, int y) const;
			void			setMatriceValueAt(int x, int y, AGameEntity * value);
};

#endif
