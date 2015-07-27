/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missile.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 01:24:41 by tmertz            #+#    #+#             */
/*   Updated: 2015/04/11 22:50:38 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISSILE_HPP
# define MISSILE_HPP

#include "A_GameEntity.class.hpp"

class		Missile : public AGameEntity
{
		private :
			int		_direction;
			int		_damage;
			int		_id;

		public :
			Missile();
			~Missile();
			Missile(int x, int y, int direction, int damage, int id);
			Missile(Missile & src);

			Missile &		operator=(Missile & rhs);
			int				getDamage(void) const;
			int				getDirection(void) const;
			void					setId(int nbr);
			int						getId();
};


#endif
