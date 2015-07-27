/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AGameEntity.class.cpp                              :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 23:56:13 by tmertz            #+#    #+#             */
/*   Updated: 2015/04/11 22:52:11 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A_GameEntity.class.hpp"

AGameEntity::AGameEntity() : _posX(-1) , _posY(-1)
{
}

AGameEntity::AGameEntity(int x, int y, int type) : _posX(x),
									_posY(y), _type(type)
{
}
/*
AGameEntity::AGameEntity(int x, int y, Board & board, int color) : _posX(x),
									_posY(y), _board(&board), _color(color)
{
}
*/
AGameEntity::AGameEntity(AGameEntity & src)
{
	*this = src;
}

AGameEntity::~AGameEntity()
{
}

AGameEntity &			AGameEntity::operator=(AGameEntity & rhs)
{
	this->_posX = rhs._posX;
	this->_posY = rhs._posY;
	return *this;
}

void			AGameEntity::goUp()
{
	_posY = _posY - 1;
}

void			AGameEntity::goDown()
{
	_posY = _posY + 1;
}

void			AGameEntity::goLeft()
{
	_posX = _posX - 1;
}

void			AGameEntity::goRight()
{
	_posX = _posX + 1;
}

void			AGameEntity::setPosition(int x, int y)
{
	_posX = x;
	_posY = y;
}

int				AGameEntity::getPosX(void) const
{
	return (this->_posX);
}

int				AGameEntity::getPosY(void) const
{
	return (this->_posY);
}

void			AGameEntity::setPosX(int x)
{
	this->_posX = x;
}

void			AGameEntity::setPosY(int y)
{
	this->_posY = y;
}

int			AGameEntity::getType(void)
{
	return _type;
}
