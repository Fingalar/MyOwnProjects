/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missile.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 01:24:49 by tmertz            #+#    #+#             */
/*   Updated: 2015/04/11 22:51:55 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Missile.class.hpp"
#include <iostream>
#include "Draw.class.hpp"

Missile::Missile() : AGameEntity(-1, -1, MISSILE), _id(0)
{
}

Missile::Missile(int x, int y, int direction, int damage, int id)
					: AGameEntity(x, y, MISSILE),
					_direction(direction), _damage(damage), _id(id)
{
}

Missile::Missile(Missile & src) : AGameEntity()
{
	*this = src;
}

Missile::~Missile()
{
}

Missile &		Missile::operator=(Missile & rhs)
{
	this->_type = rhs._type;
	this->_posX = rhs._posX;
	this->_posY = rhs._posY;
	this->_damage = rhs._damage;
	this->_direction = rhs._direction;
	this->setPosition(rhs.getPosX(), rhs.getPosY());
	return *this;
}

int				Missile::getDamage(void) const
{
	return (_damage);
}

int			Missile::getDirection(void) const
{
	return(_direction);
}

int			Missile::getId()
{
	return(_id);
}

void		Missile::setId(int nbr)
{
	_id = nbr;
}
