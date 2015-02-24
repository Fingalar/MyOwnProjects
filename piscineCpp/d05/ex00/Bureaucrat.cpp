/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 16:43:13 by tmertz            #+#    #+#             */
/*   Updated: 2015/01/12 22:52:58 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string & name, int grade) : _name(name), _grade(grade)
{
}

Bureaucrat::Bureaucrat(Bureaucrat & src)
{
	*this = src;
}

Bureaucrat::~Bureaucrat()
{
}

std::string			Bureaucrat::getName() const
{
	return (_name);
}

void					Bureaucrat::upGrade()
{
	_grade++;
}

void					Bureaucrat::downGrade()
{
	_grade--;
}


int					Bureaucrat::getGrade() const
{
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	return (_grade);
}

Bureaucrat &		Bureaucrat::operator=(Bureaucrat & rhs)
{
	this->_grade = rhs.getGrade();
	return *this;
}


/*\ Grade too high exception nested class \*/

Bureaucrat::GradeTooHighException::GradeTooHighException() throw()
{
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
}

const char *							Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Error : Grade too high !");
}

/*\ Grade too low exception nested class \*/

Bureaucrat::GradeTooLowException::GradeTooLowException() throw()
{
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
}

const char *		Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Error : Grade too low !");
}

std::ostream &		operator<<(std::ostream & o, Bureaucrat & rhs)
{
	try
	{
		o << 
	}
	catch
	{

	}
}
