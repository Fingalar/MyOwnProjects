/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 01:02:28 by tmertz            #+#    #+#             */
/*   Updated: 2015/01/16 04:52:01 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"

template <typename T>
MutantStack<T>::MutantStack(unsigned int maxSize) : _size(maxSize), _currElem(0)
{
	_data = new T[_size];
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack & src)
{
	*this = src;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
	delete [] _data;
}

template <typename T>
MutantStack<T> &			MutantStack<T>::operator=(MutantStack<T> & rhs)
{
	this->_data = rhs._data;
	this->_size = rhs._size;
	this->_currElem = rhs._currElem;
	return *this;
}

template <typename T>
T &							MutantStack<T>::operator[](unsigned int index)
{
	try
	{
		if (index > _currElem)
		{
			throw std::string("Cannot access to this index");
		}
		return (_data[index]);
	}
	catch (std::string & e)
	{
		std::cout << e << std::endl;
	}
}

template <typename T>
bool					MutantStack<T>::empty(void) const
{
	if (_currElem == 0)
		return true;
	else
		return false;
}


template <typename T>
unsigned int			MutantStack<T>::size(void) const
{
	return (_currElem);
}

template <typename T>
T &						MutantStack<T>::top(void) const
{
	return (_data[_currElem]);
}

template <typename T>
void					MutantStack<T>::push(T & src)
{
	_currElem++;
	_data[_currElem] = src;
}

template <typename T>
void					MutantStack<T>::pop(void)
{
	_currElem--;
}

template class MutantStack<int>;
template class MutantStack<std::string>;
template class MutantStack<char>;
