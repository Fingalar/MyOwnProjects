/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 15:24:31 by tmertz            #+#    #+#             */
/*   Updated: 2015/04/11 22:52:48 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER
# define CHARACTER

#include "A_GameEntity.class.hpp"

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

class		Player : public AGameEntity
{
	private :

	public :
		Player();
		Player(Player & src);
		virtual ~Player();

		Player &		operator=(Player & rhs);
};

#endif
