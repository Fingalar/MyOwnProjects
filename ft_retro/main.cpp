/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 07:59:19 by tmertz            #+#    #+#             */
/*   Updated: 2015/04/12 19:26:47 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.class.hpp"
#include "Draw.class.hpp"

int		main()
{
	Draw		win;
	Board		board(win.getW() + 1, win.getH() + 1);
	Player		player(1);
	Game		game(board, win, player);

	srand(time(NULL));
	game.lauchGame();
}

