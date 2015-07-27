/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 15:24:15 by tmertz            #+#    #+#             */
/*   Updated: 2015/04/11 22:54:56 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.class.hpp"
#include "Draw.class.hpp"

Player::Player() : AGameEntity(10, 10, PLAYER)
{
}


Player::Player(Player & src) :AGameEntity()
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

