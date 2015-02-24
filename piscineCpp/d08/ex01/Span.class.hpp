/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 20:34:01 by tmertz            #+#    #+#             */
/*   Updated: 2015/01/16 01:25:22 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <iostream>

class		Span {

		private:
			std::vector<int>		_list;

		public:
			Span();
			Span(unsigned int i);
			Span(Span & src);
			~Span();

			Span &			operator=(Span & rhs);
			int				shortestSpan(void) const;
			int				longestSpan(void) const;
			void			addNumber(int nbr);
};

#endif

