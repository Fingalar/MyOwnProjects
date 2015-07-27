/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 18:04:22 by tmertz            #+#    #+#             */
/*   Updated: 2015/04/14 17:01:04 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <cstdlib>
#include <stdexcept>

int			main(void)
{
	Bureaucrat			*bur;
	std::string			name;
	std::string			buffer;
	Form				*form;
	int					sign;
	int					exec;

	while (42)
	{
		std::cout << "Please enter a name of bureaucrat" << std::endl;
		std::getline(std::cin, buffer);
		name = buffer;
		std::cout << "Please enter a grade for " << name << std::endl;
		std::getline(std::cin, buffer);
		try
		{
			bur = new Bureaucrat(name, atoi(buffer.c_str()));
			std::cout << *bur << std::endl;
			std::cout << "Try to upgrade" << std::endl;
			bur->upGrade();
			std::cout << "Try to downgrade" << std::endl;
			bur->downGrade();
			bur->downGrade();
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
			std::exit(0);
		}
		std::cout << "Please enter a name of form" << std::endl;
		std::getline(std::cin, buffer);
		name = buffer;
		std::cout << "Please enter a grade to sign it" << std::endl;
		std::getline(std::cin, buffer);
		sign = atoi(buffer.c_str());
		std::cout << "Please enter a grade to exec it" << std::endl;
		std::getline(std::cin, buffer);
		exec = atoi(buffer.c_str());
		try
		{
			form = new Form(name, sign, exec);
			std::cout << *form << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
		bur->signForm(*form);
	}
}
