/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncurse.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 20:21:23 by tmertz            #+#    #+#             */
/*   Updated: 2015/04/18 18:52:57 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_CLASS_H
# define DRAW_CLASS_H

#include <curses.h>
#include <signal.h>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "IMonitorDisplay.class.hpp"
#include "IMonitorModule.class.hpp"

#define BLACK 32 | (COLOR_PAIR(4))

class Ncurse : public IMonitorDisplay {
	private:
		int				_h;
		int				_w;

	public:
		Ncurse();
		Ncurse(Ncurse const & instance);
		~Ncurse();

		int				getH();
		int				getW();
		void			setH(int const h);
		void			setW(int const w);

		virtual int		init() const;
		virtual int		end() const ;
		virtual void	drawModule(IMonitorModule & module) const;
		virtual void	interpretData(std::string const & data) const;
};

#endif

