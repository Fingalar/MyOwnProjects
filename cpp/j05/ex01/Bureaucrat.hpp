/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 16:43:04 by tmertz            #+#    #+#             */
/*   Updated: 2015/04/14 17:08:13 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>


class Form;

class		Bureaucrat {
	private :
		std::string	const		_name;
		int						_grade;

	public :
		Bureaucrat();
		Bureaucrat(Bureaucrat & src);
		Bureaucrat(std::string & name, int grade);
		~Bureaucrat();
		Bureaucrat &		operator=(Bureaucrat & rhs);
		std::string			getName() const;
		void				upGrade();
		void				downGrade();
		int					getGrade() const;
		void				signForm(Form &form);

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

std::ostream &			operator<<(std::ostream & o, Bureaucrat const & bur);

#endif
