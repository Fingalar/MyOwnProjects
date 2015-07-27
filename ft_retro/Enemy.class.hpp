/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 02:48:55 by tmertz            #+#    #+#             */
/*   Updated: 2015/04/12 02:00:23 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

#include "A_GameEntity.class.hpp"

# define CYLON 0
# define CRUISER 1
# define TAU 2
# define ELDARI 3
# define TETRIS 4


class		Enemy : public AGameEntity
{
		private :
			int		_direction;
			int		_id;
			int		_shape;

		public :
			Enemy();
			Enemy(int x, int y, int direction, int id, int shape);
			Enemy(Enemy & src);
			~Enemy();

			Enemy &			operator=(Enemy & rhs);
			int				getDirection() const;
			void			setId(int nbr);
			int				getId();
			int				getShape();
};

#endif
