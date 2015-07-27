/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 15:24:15 by tmertz            #+#    #+#             */
/*   Updated: 2015/04/12 19:26:19 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.class.hpp"
#include "Draw.class.hpp"

Player::Player() : AGameEntity(10, 10, PLAYER) , _hp(3), _index(0)
{
}

Player::Player(int id) : AGameEntity(10, 10, PLAYER) , _hp(3), _index(id)
{

}

Player::Player(Player & src)
{
	*this= src;
}

Player &			Player::operator=(Player & rhs)
{
	this->setPosition(rhs.getPosX(), rhs.getPosY());
	return *this;
}

Player::~Player()
{
}

int					Player::getHp()
{
	return _hp;
}

int					Player::decHp()
{
	_hp--;
	return _hp;
}

int					Player::getIndex()
{
	return _index;
}
