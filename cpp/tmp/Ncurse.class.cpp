/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncurse.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 14:15:01 by tmertz            #+#    #+#             */
/*   Updated: 2015/04/18 18:52:51 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ncurse.class.hpp"
#include <ctime>

/* # Constructors
 * ========================================= */

Ncurse::Ncurse()
{
	this->init();
}

Ncurse::Ncurse(Ncurse const & instance)
{
	*this = instance;
}

Ncurse::~Ncurse()
{
	this->end();
}

/* # Ncurse init
 * ========================================= */

int			Ncurse::init()
{
	initscr(); // init
	cbreak(); // char by char init
	noecho(); // prevent echo
	keypad(stdscr, TRUE); // enabling special chars like delete
	start_color(); // init colors in ncurse

	init_pair( 1, COLOR_BLACK, COLOR_BLUE );
	init_pair( 2, COLOR_BLACK, COLOR_RED );
	init_pair( 3, COLOR_BLACK, COLOR_YELLOW );

	init_pair( 4, COLOR_BLACK, COLOR_BLACK);
	init_pair( 5, COLOR_BLACK, COLOR_WHITE );
	init_pair( 6, COLOR_WHITE, COLOR_BLACK );

	init_pair( 7, COLOR_WHITE, COLOR_BLACK );
	init_pair( 8, COLOR_YELLOW, COLOR_BLACK );
	init_pair( 9, COLOR_RED, COLOR_BLACK );

	bkgd(COLOR_PAIR(1)); // set background
	curs_set(0); // hidding the cursor
	getmaxyx(stdscr, _h, _w); // get actual x y values
	nodelay(stdscr, TRUE); // no delay on keypress
	srand(time(NULL));
	return (1);
}

int			Ncurse::end()
{
	endwin();
	return (1);
}

/* # Ncurse
 * ========================================= */

void		Ncurse::drawModule(IMonitorModule & module) const
{
	std::vector<std::string>				datas;

	datas = module.getDatas();
	printw("%s", datas[0].c_str());
	for_each(datas.begin() + 1, datas.end(), this->interpretData());
	wrefresh(stdscr);
}

void		Ncurse::interpretData(std::string const & data) const
{
	if (data[data.size() - 1] == '%')
		drawPercent(atoi(data.c_str()));
	if (isdigit(data[0]))
	{
		printValue(data);
	}
}

void		NCurse::printValue(std::string const & data)
{
	int			i;

	printw("%d ", atoi(data.c_str()));
	i = 0;
	while (i < data.size())
	{
		if (!isdigit(data[i]))
			break ;
		i++;
	}
	printw("%s", data.substr(i, data.size() - 1));
}

/* # Accessors
 * ========================================= */

int			Ncurse::getH()
{
	return _h;
}

void		Ncurse::setH(int const h)
{
	_h = h;
}

int			Ncurse::getW()
{
	return _w;
}

void		Ncurse::setW(int const w)
{
	_w = w;
}

