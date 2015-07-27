/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 15:24:31 by tmertz            #+#    #+#             */
/*   Updated: 2015/04/12 19:26:21 by tmertz           ###   ########.fr       */
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
		int		_hp;
		int		_index;

	public :
		Player();
		Player(int id);
		Player(Player & src);
		virtual ~Player();

		Player &		operator=(Player & rhs);
		int				getHp();
		int				decHp();
		int				getIndex();
};

#endif
