/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 02:48:53 by tmertz            #+#    #+#             */
/*   Updated: 2015/04/12 02:15:21 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.class.hpp"
#include "Draw.class.hpp"

Enemy::Enemy() : AGameEntity(-1, -1, ENEMY), _id(0)
{
}

Enemy::Enemy(int x, int y, int direction, int id, int shape)
					: AGameEntity(x, y, ENEMY) ,
					_direction(direction), _id(id), _shape(shape)
{
}

Enemy::Enemy(Enemy & src) : AGameEntity()
{
	*this = src;
}

Enemy::~Enemy()
{
}

Enemy &		Enemy::operator=(Enemy & rhs)
{
	this->_shape = rhs._shape;
	this->_posX = rhs._posX;
	this->_posY = rhs._posY;
	this->_type = rhs._type;
	this->_direction = rhs._direction;
	this->setPosition(rhs.getPosX(), rhs.getPosY());
	return *this;
}

int			Enemy::getDirection(void) const
{
	return(_direction);
}

int			Enemy::getId()
{
	return(_id);
}

void		Enemy::setId(int nbr)
{
	_id = nbr;
}

int			Enemy::getShape()
{
	return _shape;
}
