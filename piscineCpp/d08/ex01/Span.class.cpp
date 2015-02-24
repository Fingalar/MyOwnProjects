/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 20:34:09 by tmertz            #+#    #+#             */
/*   Updated: 2015/01/16 04:56:42 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.class.hpp"

Span::Span()
{
}

Span::Span(unsigned int i)
{
	_list.reserve(i);
}

Span::Span(Span & src)
{
	*this = src;
}

Span::~Span()
{
}

Span &				Span::operator=(Span & rhs)
{
	_list = rhs._list;

	return *this;
}

int					Span::shortestSpan(void)  const
{
	unsigned int			i;
	unsigned int			j;
	int						span;
	int						tmp;

	if (_list.size() == 1 || _list.size() == 0)
		throw std::string("Too small list to calculate a span");
	span = _list[0] - _list[1];
	if (span < 0)
		span = span * -1;
	i = 0;
	while (i < _list.size())
	{
		j = i + 1;
		while (j < _list.size())
		{
			if (_list[i] > _list[j])
			{
				tmp = _list[i] - _list[j];
			}
			else
			{
				tmp = _list[j] - _list[i];
				if (tmp < 0)
					tmp = tmp * -1;
			}
			if (tmp < span)
			{
				span = tmp;
			}
			j++;
		}
		i++;
	}
	return (span);
}

int					Span::longestSpan(void) const
{
	unsigned int			i;
	unsigned int			j;
	int						span;
	int						tmp;

	if (_list.size() == 1 || _list.size() == 0)
		throw std::string("Too small list to calculate a span");
	span = 0;
	i = 0;
	while (i < _list.size())
	{
		j = i + 1;
		while (j < _list.size())
		{
			if (_list[i] > _list[j])
			{
				tmp = _list[i] - _list[j];
			}
			else
			{
				tmp = _list[j] - _list[i];
				if (tmp < 0)
					tmp = tmp * -1;
			}
			if (tmp > span)
			{
				span = tmp;
			}
			j++;
		}
		i++;
	}
	return (span);
}

void				Span::addNumber(int nbr)
{
	try
	{
		if (_list.size() == _list.capacity())
		{
			throw std::string("Error, tab is allready full");
		}
		else
		{
			_list.push_back(nbr);
		}
	}
	catch (std::string & e)
	{
		std::cout << e << std::endl;
	}
}
