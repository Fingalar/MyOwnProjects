/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Draw.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 14:15:01 by tmertz            #+#    #+#             */
/*   Updated: 2015/04/18 19:46:01 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Draw.class.hpp"
#include "A_GameEntity.class.hpp"
#include <ctime>

/* # Constructors
 * ========================================= */

Draw::Draw() : _score(0), _hpP1(3), _hpP2(-1)
{
	this->initNcurse();
	_isMenu = true;
}

Draw::Draw(Draw const & instance) : _score(0)
{
	*this = instance;
}

Draw::~Draw() 
{
	this->endNcurse();
}

/* # Ncurse init
 * ========================================= */

int			Draw::initNcurse()
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

int			Draw::endNcurse()
{
	endwin();
	return (1);
}

/* # Draw
 * ========================================= */

void		Draw::render(AGameEntity **matrice)
{
	drawFrame(matrice);
}

void		Draw::drawFrame(AGameEntity **matrice)
{
	int		i;

	i = 0;
	for (int y = 0; y < _h; y++)
	{
		for (int x = 0; x < _w; x++)
		{
			if (matrice[i])
			{
				switch (matrice[i]->getType())
				{
				case 0 :
					mvwaddch(stdscr, y, x, 32 | BLACK);
					break;
				case PLAYER:
					mvwaddch(stdscr, y, x, 32 | WHITE);
					break;
				case MISSILE:
					mvwaddch(stdscr, y, x, 32 | YELLOW);
					break;
				case ENEMY:
					mvwaddch(stdscr, y, x, 32 | RED);
					break;
				default :
					mvwaddch(stdscr, y, x, 32 | BLACK);
					break ;
				}
			}
			else
			{
				mvwaddch(stdscr, y, x, 32 | BLACK);
			}
			i++;
		}
		i++;
	}
	wmove(stdscr, _h - 5 , _w - 50);
	attron(WHITE);
	printw("Score : %d    Hp P1 : %d", _score, _hpP1);
	if (_hpP2 != -1)
		printw("Hp P2 : %d", _hpP2);
	wrefresh(stdscr);
}


/* # Keyboard handling
 * ========================================= */


void		Draw::renderMenu() {
	int		i;

	i = 0;
	_isMenu = true;
	for (int y = 0; y < _h; y++)
	{
		for (int x = 0; x < _w; x++)
		{
			mvwaddch(stdscr, y, x, BLACK);
			i++;
		}
		i++;
	}
	wborder(stdscr, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE);
	wmove(stdscr, _h / 2 - 2, _w / 2 - 26);
	attron(WHITE);
	addstr("~~~~ SPACE NAZIS ROXXXXOR 4 ~~~~");
	attron(WHITE_TEXT);
	wmove(stdscr, _h / 2, _w / 2 - 12);
	addstr("PRESS 1 or 2 TO SELECT THE NUMBER OF PLAYERS");
	wrefresh(stdscr);
}

void		Draw::renderWin() {
	int		i;

	i = 0;
	_isMenu = true;
	for (int y = 0; y < _h; y++)
	{
		for (int x = 0; x < _w; x++)
		{
			mvwaddch(stdscr, y, x, BLACK);
			i++;
		}
		i++;
	}
	wborder(stdscr, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE);
	wmove(stdscr, _h / 2, _w / 2 - 10);
	attron(WHITE);
	addstr("~~~~ YOU WON !! ~~~~");
	wrefresh(stdscr);
	sleep(5);
	std::exit(0);
}

void		Draw::renderLose() {
	int		i;

	i = 0;
	_isMenu = true;
	for (int y = 0; y < _h; y++)
	{
		for (int x = 0; x < _w; x++)
		{
			mvwaddch(stdscr, y, x, BLACK);
			i++;
		}
		i++;
	}
	wborder(stdscr, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE);
	wmove(stdscr, _h / 2, _w / 2 - 10);
	attron(WHITE);
	addstr("~~~~ YOU LOSE ... ~~~~");
	wrefresh(stdscr);
	sleep(5);
	std::exit(0);
}

/* # Accessors
 * ========================================= */

int			Draw::getH()
{
	return _h;
}

void		Draw::setH(int const h)
{
	_h = h;
}

int			Draw::getW()
{
	return _w;
}

void		Draw::setW(int const w)
{
	_w = w;
}

bool		Draw::getIsMenu()
{
	return _isMenu;
}

void		Draw::setIsMenu(bool const isMenu)
{
	_isMenu = isMenu;
}

void			Draw::incScore()
{
	_score++;
}

void			Draw::updateHp(int player, int hp)
{
	if (player == P1)
		_hpP1 = hp;
	if (player == P2)
		_hpP2 = hp;
}
