/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 18:04:22 by tmertz            #+#    #+#             */
/*   Updated: 2015/01/12 22:44:40 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <cstdlib>
#include <stdexcept>

int			main(void)
{
	Bureaucrat			*bur;
	std::string			name;
	std::string			buffer;

	std::cout << "Please enter a name of bureaucrat" << std::endl;
	std::getline(std::cin, buffer);
	name = buffer;
	std::cout << "Please enter a grade for " << name << std::endl;
	std::getline(std::cin, buffer);
	try
	{
		bur = new Bureaucrat(name, atoi(buffer.c_str()));
		bur->getGrade();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}
