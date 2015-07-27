/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/14 14:22:26 by tmertz            #+#    #+#             */
/*   Updated: 2015/04/14 17:07:33 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form  {
	private:
		std::string &				_name;
		int const					_gradeToSign;
		int const					_gradeToExec;
		bool						_isSigned;
		Form();

	public:
		Form(std::string & name, int gradeSign, int gradeExec);
		~Form();
		std::string &				getName();
		int							getGradeToSign();
		int							getGradeToExec();
		bool						getSigned();
		void						beSigned(Bureaucrat &bur);

		class		GradeTooHighException : public std::exception
		{
			public :
				~GradeTooHighException() throw();
				GradeTooHighException() throw();
				GradeTooHighException &		operator=(GradeTooHighException & rhs);
				virtual const char *		what() const throw();
		};
		class		GradeTooLowException : public std::exception
		{
			public :
				GradeTooLowException() throw ();
				~GradeTooLowException() throw();
				GradeTooLowException &		operator=(GradeTooLowException & rhs);
				virtual const char *		what() const throw();
		};
};

std::ostream &		operator<<(std::ostream & o, Form & form);

#endif
