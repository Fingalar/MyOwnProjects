/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Board.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 20:40:11 by tmertz            #+#    #+#             */
/*   Updated: 2015/04/12 00:22:35 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Board.class.hpp"

Board::Board()
{
}

Board::Board(Board & src)
{
	*this = src;
}

Board::Board(int x, int y)
{
	int			i;

	this->_matrice = new AGameEntity*[x * y];
	this->_w = x;
	this->_h = y;
	i = (x * y);
	while (i > 0)
	{
		_matrice[i] = 0;
		i--;
	}

}

Board::~Board()
{
}

Board &		Board::operator=(Board & rhs)
{
	this->_matrice = rhs._matrice;
	return *this;
}

AGameEntity			**Board::getMatrice(void) const
{
	return(_matrice);
}

AGameEntity *	Board::getMatriceValueAt(int x, int y) const
{
	return (this->_matrice[y * _w + x]);
}

void		Board::setMatriceValueAt(int x, int y, AGameEntity * value)
{
	this->_matrice[y * _w + x] = value;
}
