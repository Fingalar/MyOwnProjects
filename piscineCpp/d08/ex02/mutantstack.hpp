/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 23:20:32 by tmertz            #+#    #+#             */
/*   Updated: 2015/01/16 04:49:38 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK
# define MUTANTSTACK

#include <iostream>
#include <iterator>

template <typename T>
class	MutantStack {

	class iterator : public std::iterator<std::input_iterator_tag, T>
	{
		private :

		public :
			iterator();
			iterator(iterator & iterator);
			iterator(T *elem);
			~iterator();
	};

	private :
		unsigned int		_size;
		T					*_data;
		unsigned int		_currElem;

	public :
		MutantStack(unsigned int MaxSize = 500);
		MutantStack(MutantStack & stack);
		~MutantStack();

		MutantStack &		operator=(MutantStack & src);
		bool				empty(void) const;
		unsigned int		size(void) const;
		T &					top(void) const;
		void				push(T & src);
		void				pop(void);
		iterator			begin();
		T &					operator[](unsigned int index);
};

#endif
