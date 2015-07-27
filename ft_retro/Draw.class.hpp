/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Draw.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 20:21:23 by tmertz            #+#    #+#             */
/*   Updated: 2015/04/12 19:42:53 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_CLASS_H
# define DRAW_CLASS_H

#include <curses.h>
#include <signal.h>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "A_GameEntity.class.hpp"

#define BLUE 32 | (COLOR_PAIR(1))
#define RED 32 | (COLOR_PAIR(2))
#define YELLOW 32 | (COLOR_PAIR(3))
#define BLACK 32 | (COLOR_PAIR(4))

#define WHITE (COLOR_PAIR(5))
#define WHITE_TEXT (COLOR_PAIR(6))

#define PLAYER_COLOR '>' | (COLOR_PAIR(7))
#define MISSILE_COLOR '.' | (COLOR_PAIR(8))
#define ENEMY_COLOR '<' | (COLOR_PAIR(9))

#define PLAYER 1
#define MISSILE 2
#define ENEMY 3

#define P1 1
#define P2 2


class Draw{
	private:
		int				_h;
		int				_w;
		int				_isMenu;
		int				_score;
		int				_hpP1;
		int				_hpP2;

	public:
		Draw();
		Draw(Draw const & instance);
		~Draw();

		int				getH();
		int				getW();
		void			setH(int const h);
		void			setW(int const w);
		bool			getIsMenu();
		void			setIsMenu(bool const isMenu);

		void			render(AGameEntity **matrice);
		void			drawFrame(AGameEntity **matrice);
		void			renderMenu();
		void			renderWin();
		void			renderLose();
		int				initNcurse();
		int				endNcurse();
		void			keyHandler(AGameEntity **matrice);
		void			incScore();
		void			updateHp(int player, int hp);
};

#endif

