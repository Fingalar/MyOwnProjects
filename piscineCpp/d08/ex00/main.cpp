/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 20:39:09 by tmertz            #+#    #+#             */
/*   Updated: 2015/01/16 05:02:00 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
int	&	easyfind(T & list, int nbr)
{
	typename	T::iterator  it;

	it = std::find(list.begin(), list.end(), nbr);
	if (it == list.end())
		throw std::string("Not found");
	else
		return *it;
}


int main()
{
	std::list<int>		list;
	std::vector<int>	vector;
	int					i;

	vector.push_back(-10);
	vector.push_back(-6);
	vector.push_back(-1);
	vector.push_back(1);
	vector.push_back(5);
	vector.push_back(7);
	vector.push_back(4);
	vector.push_back(1);
	vector.push_back(-63);
	vector.push_back(11);
	vector.push_back(10);
	try
	{
		i = easyfind(vector, 10);
		std::cout << i << " : found !" << std::endl;
	}
	catch (std::string & e)
	{
		std::cout << e << std::endl;
	}

	list.push_back(-10);
	list.push_back(-6);
	list.push_back(-1);
	list.push_back(1);
	list.push_back(5);
	list.push_back(7);
	list.push_back(4);
	list.push_back(1);
	list.push_back(-63);
	list.push_back(11);
	list.push_back(10);
	try
	{
		i = easyfind(list, 43);
		std::cout << i << " : found !" << std::endl;
	}
	catch (std::string & e)
	{
		std::cout << e << std::endl;
	}

}
