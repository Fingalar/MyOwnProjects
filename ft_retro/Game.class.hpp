/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 20:31:18 by tmertz            #+#    #+#             */
/*   Updated: 2015/04/12 20:15:24 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP

#include "Board.class.hpp"
#include "Draw.class.hpp"
#include "Player.class.hpp"
#include "Missile.class.hpp"
#include "Enemy.class.hpp"
#include <iostream>
#include <time.h>
#include <limits.h>

class		Game
{
		private :
			Board &			_board;
			Draw &			_win;
			Enemy			_enemy[2000];
			Missile			_missile[5000];
			Player &		_player;
			Player *		_player2;
			int				_missileId;
			int				_enemyId;
			int				_score;

			static Board	defBoard;
			static Draw		defWin;
			static Player	defPlayer;

		public :
			Game();
			Game(Board & board, Draw & win, Player & player);
			Game(Game & src);
			~Game();

			Game &		operator=(Game & rhs);
			Board &		getBoard(void) const;
			Player &	getPlayer(void) const;
			void		setBoard(Board & src);
			void		setPlayer(Player & player);

			void		keyHandler();
			void		lauchGame();
			void		gameLoop();
			void		moveMissiles();
			void		moveEnemies();
			void		spawnEnemies();
			void		ennemiesShoot();

			void		moveUp(Player & player);
			void		moveDown(Player & player);
			void		playerShoot(Player &player);
			void		loseHp(Player &player);

			int			checkIfCollision(AGameEntity & entity);
			void		deleteEntity(AGameEntity & entity);
			void		deleteShip(Enemy & entity);
			void		reformTab(AGameEntity & entity, int index);

			void		drawShip(Enemy &entity);
			void		drawPlayer(Player &player,AGameEntity *addr);
			void		drawCylon(Enemy & ship, AGameEntity *addr);
			void		drawTetris(Enemy & ship, AGameEntity *addr);
			void		drawCruiser(Enemy & ship, AGameEntity *addr);
			void		drawTau(Enemy & ship, AGameEntity *addr);
			void		drawEldari(Enemy & ship, AGameEntity *addr);
};

#endif
