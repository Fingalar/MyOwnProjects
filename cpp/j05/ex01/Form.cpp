/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/14 14:39:51 by tmertz            #+#    #+#             */
/*   Updated: 2015/04/14 17:09:41 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

std::string defaut("toto");

Form::Form() : _name(defaut), _gradeToSign(-1), _gradeToExec(-1), _isSigned(false)
{
}

Form::Form(std::string & str, int gradeSign, int gradeExec) : _name(str)
					, _gradeToSign(gradeSign), _gradeToExec(gradeExec)
{
	if (gradeSign > 150)
		throw Form::GradeTooLowException();
	if (gradeSign < 1)
		throw Form::GradeTooHighException();
	if (gradeExec > 150)
		throw Form::GradeTooLowException();
	if (gradeExec < 1)
		throw Form::GradeTooHighException();
	_isSigned = false;
}

Form::~Form()
{
}

std::string &					Form::getName()
{
	return _name;
}

int								Form::getGradeToSign()
{
	return _gradeToSign;
}

int								Form::getGradeToExec()
{
	return _gradeToExec;
}

bool							Form::getSigned()
{
	return _isSigned;
}

void							Form::beSigned(Bureaucrat & bur)
{
	if (bur.getGrade() > _gradeToSign)
	{
		throw Form::GradeTooLowException();
	}
	else
		_isSigned = true;
}

/*\ Grade too high exception nested class \*/

Form::GradeTooHighException::GradeTooHighException() throw()
{
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{
}

const char *							Form::GradeTooHighException::what() const throw()
{
	return ("Error : Grade too high !");
}

/*\ Grade too low exception nested class \*/

Form::GradeTooLowException::GradeTooLowException() throw()
{
}

Form::GradeTooLowException::~GradeTooLowException() throw()
{
}

const char *		Form::GradeTooLowException::what() const throw()
{
	return ("Error : Grade too low !");
}

std::ostream &		operator<<(std::ostream & o, Form & form)
{
	return (o << form.getName() << ", form , need grade " << form.getGradeToSign() 
		<< "to be signed and grade " << form.getGradeToExec()
		<< " to be executed.");
}
