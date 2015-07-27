/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 16:43:13 by tmertz            #+#    #+#             */
/*   Updated: 2015/04/14 17:09:37 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string & name, int grade) : _name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = grade;
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
	if (_grade <=1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void					Bureaucrat::downGrade()
{
	if (_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}


int					Bureaucrat::getGrade() const
{
	return (_grade);
}

Bureaucrat &		Bureaucrat::operator=(Bureaucrat & rhs)
{
	this->_grade = rhs.getGrade();
	return *this;
}


void				Bureaucrat::signForm(Form & form)
{
	try
	{
		form.beSigned(*this);
	}
	catch (std::exception & e)
	{
		std::cout << _name << " cannot sign " << form.getName() <<
			" because " << e.what() << "." << std::endl;
		return ;
	}
	std::cout << _name << " signs " << form.getName() << "." << std::endl;
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

std::ostream &		operator<<(std::ostream & o, Bureaucrat const & bur)
{
	return (o << bur.getName() << ", bureaucrat grade " << bur.getGrade() << ".");
}
