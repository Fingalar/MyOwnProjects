/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 20:31:33 by tmertz            #+#    #+#             */
/*   Updated: 2015/04/12 02:31:50 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.class.hpp"
#include "A_GameEntity.class.hpp"
#include <ctime>

Board Game::defBoard;
Draw Game::defWin;
Player Game::defPlayer;

Game::Game() : _board(defBoard), _win(defWin), _player(defPlayer)
{
}

Game::Game(Game & src) : _board(defBoard), _win(defWin), _player(defPlayer)
{
	_board = src._board;
	_win =  src._win;
	_player = src._player;
	*this = src;
}

Game::~Game()
{
}

Game::Game(Board & board, Draw & win, Player & player) :_board(board), _win(win)
															, _player(player), _missileId(0), _enemyId(0)
{
}

Game &			Game::operator=(Game & rhs)
{
	this->_board = rhs._board;
	return *this;
}

void			Game::deleteShip(Enemy & entity)
{
	switch (entity.getShape())
		{
		case TAU :
			drawTau(entity, NULL);
			break;
		case ELDARI :
			drawEldari(entity, NULL);
			break;
		case CRUISER :
			drawCruiser(entity, NULL);
			break ;
		case CYLON :
			drawCylon(entity, NULL);
			break ;
		case TETRIS:
			drawTetris(entity, NULL);
			break ;
		}
}

void			Game::deleteEntity(AGameEntity & entity)
{
	int		index;
	int			i;
	int			j;
	Missile		fake_miss;
	Enemy		fake_enemy;

	if (entity.getType() == MISSILE)
	{
		_board.setMatriceValueAt(entity.getPosX(), entity.getPosY(), 0);
		index = static_cast<Missile &>(entity).getId();
		i = index;
		j = index + 1;
		while (j <= _missileId)
		{
			_missile[i] = _missile[j];
			_missile[i].setId(i);
			i++;
			j++;
		}
		_missile[i] = fake_miss;
		_missileId--;
	}
	else
	{
		deleteShip(static_cast<Enemy &>(entity));
		index = static_cast<Enemy &>(entity).getId();
		i = index;
		j = index + 1;
		while (j <= _enemyId)
		{
			_enemy[i] = _enemy[j];
			_enemy[i].setId(i);
			i++;
			j++;
		}
		_enemy[i] = fake_enemy;
		_enemyId--;
	}
}


int				Game::checkIfCollision(AGameEntity & entity)
{
	AGameEntity		*result;

	result = _board.getMatriceValueAt(entity.getPosX(), entity.getPosY());
	if (!result)
		return 0;
	switch (result->getType())
	{
	case MISSILE:
		if (entity.getType() != MISSILE)
		{
			deleteEntity(*result);
			deleteEntity(entity);
			return 1;
		}
		break ;
	case ENEMY :
		{
			if (entity.getType() == MISSILE)
			{
				if (static_cast<Missile &>(entity).getDirection() == RIGHT)
				{
					deleteEntity(*result);
					deleteEntity(entity);
					return 1;
				}
				return 0;
			}
			else
				deleteEntity(*result);
		}
		return 1;
	case PLAYER :
		{
			_win.renderLose();
		}
	case 0:
		return 0;
	}
	return 0;
}

void			Game::spawnEnemies()
{
	int				posY;
	int				shape;

	posY = rand() % _win.getH();
	shape = rand() % 5;
	Enemy newEnemy(_win.getW() - 10, posY, LEFT, _enemyId, shape);
	_enemy[_enemyId] = newEnemy;
	drawShip(_enemy[_enemyId]);
	_enemyId++;
}

void			Game::ennemiesShoot()
{
	int		index;

	if (_enemyId)
		index = rand() % _enemyId;
	else
		index = 0;
	Missile miss(_enemy[index].getPosX() - 1, _enemy[index].getPosY(), LEFT, 10, _missileId);
	_missile[_missileId] = miss;
	_missileId++;
	_board.setMatriceValueAt(miss.getPosX(),
			miss.getPosY(), &miss);
}

void			Game::moveEnemies()
{
	int				i;

	i = 0;
	while (i < _enemyId)
	{
		deleteShip(_enemy[i]);
		_enemy[i].goLeft();
		if (_enemy[i].getPosX() < 0)
	//		_win.renderLose();
		if (_enemy[i].getPosY() > _win.getH() || _enemy[i].getPosY() < 0)
			deleteEntity(_enemy[i]);
		if (!checkIfCollision(_enemy[i]))
			drawShip(_enemy[i]);
		i++;
	}
}


void			Game::moveMissiles()
{
	int		i;

	i = 0;
	while (i < _missileId)
	{
		_board.setMatriceValueAt(_missile[i].getPosX(), _missile[i].getPosY(), 0);
		switch(_missile[i].getDirection())
		{
		case RIGHT :
			_missile[i].goRight();
			break;
		case LEFT :
			_missile[i].goLeft();
			break;
		}
		if (_missile[i].getPosX() > _win.getW() || _missile[i].getPosX() < 0)
			deleteEntity(_missile[i]);
		else if (_missile[i].getPosY() > _win.getW() || _missile[i].getPosY() < 0)
			deleteEntity(_missile[i]);
		else if (!checkIfCollision(_missile[i]))
		{
			_board.setMatriceValueAt(_missile[i].getPosX(), _missile[i].getPosY(), &_missile[i]);
			i++;
		}
	}
}

void			Game::gameLoop()
{
	int			i;
	int			j;
	int			k;
	int			l;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	this->spawnEnemies();
	while(42)
	{
		this->keyHandler();
		if (_win.getIsMenu())
			_win.renderMenu();
		else
		{
			_win.render(this->_board.getMatrice());
			if (i == 20)
			{
				this->moveMissiles();
				i = 0;
			}
			if (k == 2000)
			{
				this->spawnEnemies();
				k = 0;
			}
			if (j == 81)
			{
				this->moveEnemies();
				j = 0;
			}
			if (l == 200)
			{
				this->ennemiesShoot();
				l = 0;
			}
			i++;
			j++;
			k++;
			l++;
			usleep(17);
		}
	}
}

void			Game::moveUp()
{
	_board.setMatriceValueAt(_player.getPosX(), _player.getPosY(), 0);
	_player.goUp();
	if (_player.getPosY() > _win.getH())
		_player.setPosY(_win.getH());
	if ( _player.getPosY() < 0)
		_player.setPosY(0);
	_board.setMatriceValueAt(_player.getPosX(), _player.getPosY(), &_player);
}

void			Game::moveDown()
{
	AGameEntity		*result;

	_board.setMatriceValueAt(_player.getPosX(), _player.getPosY(), 0);
	_player.goDown();
	if (_player.getPosY() > _win.getH() -1)
		_player.setPosY(_win.getH() - 1);
	if ( _player.getPosY() < 0)
		_player.setPosY(0);
	result = _board.getMatriceValueAt(_player.getPosX(), _player.getPosY());
	if (result)
		_win.renderLose();
	_board.setMatriceValueAt(_player.getPosX(), _player.getPosY(), &_player);
}


void			Game::keyHandler()
{
	Missile miss(_player.getPosX() + 1, _player.getPosY(), RIGHT, 10, _missileId);

	switch (getch()) {
	case ' ':
		_missile[_missileId] = miss;
		_missileId++;
		_board.setMatriceValueAt(miss.getPosX(),
				miss.getPosY(), &miss);
		break;
	case KEY_UP:
		moveUp();
		break;
	case KEY_DOWN:
		moveDown();
		break;
	case 10:
		if (_win.getIsMenu() == true)
			_win.setIsMenu(false);
	}
}

void			Game::lauchGame(void)
{
	_board.setMatriceValueAt(_player.getPosX(), _player.getPosY(), &_player);
	this->gameLoop();
}

Player &		Game::getPlayer(void) const {
	return _player;
}

void			Game::setPlayer(Player & player) {
	_player = player;
}

Board &			Game::getBoard(void) const
{
	return (this->_board);
}

void			Game::setBoard(Board & src)
{
	this->_board = src;
}

void			Game::drawShip(Enemy & entity)
{
	switch (entity.getShape())
		{
		case TAU :
			drawTau(entity, &entity);
			break;
		case ELDARI :
			drawEldari(entity, &entity);
			break;
		case CRUISER :
			drawCruiser(entity, &entity);
			break ;
		case CYLON :
			drawCylon(entity, &entity);
			break ;
		case TETRIS:
			drawTetris(entity, &entity);
			break ;
		}
}

void			Game::drawCylon(Enemy & ship, AGameEntity *addr)
{
	_board.setMatriceValueAt(ship.getPosX(), ship.getPosY(), addr);
	_board.setMatriceValueAt(ship.getPosX(), ship.getPosY() - 1, addr);
	_board.setMatriceValueAt(ship.getPosX(), ship.getPosY() + 1, addr);
	_board.setMatriceValueAt(ship.getPosX() - 1, ship.getPosY() - 1, addr);
	_board.setMatriceValueAt(ship.getPosX() - 1, ship.getPosY() + 1, addr);
	_board.setMatriceValueAt(ship.getPosX() - 1, ship.getPosY() - 2, addr);
	_board.setMatriceValueAt(ship.getPosX() - 1, ship.getPosY() + 2, addr);
	_board.setMatriceValueAt(ship.getPosX() - 2, ship.getPosY() + 2, addr);
	_board.setMatriceValueAt(ship.getPosX() - 2, ship.getPosY() - 2, addr);
}

void			Game::drawTau(Enemy & ship, AGameEntity *addr)
{
	_board.setMatriceValueAt(ship.getPosX(), ship.getPosY(), addr);
	_board.setMatriceValueAt(ship.getPosX() + 1, ship.getPosY(), addr);
	_board.setMatriceValueAt(ship.getPosX() + 1, ship.getPosY() + 1, addr);
	_board.setMatriceValueAt(ship.getPosX() + 2, ship.getPosY(), addr);
	_board.setMatriceValueAt(ship.getPosX() + 2, ship.getPosY() - 1, addr);
	_board.setMatriceValueAt(ship.getPosX() + 3, ship.getPosY(), addr);
	_board.setMatriceValueAt(ship.getPosX() + 3, ship.getPosY() + 1, addr);
}

void			Game::drawCruiser(Enemy & ship, AGameEntity *addr)
{
	_board.setMatriceValueAt(ship.getPosX(), ship.getPosY(), addr);
	_board.setMatriceValueAt(ship.getPosX() + 1, ship.getPosY(), addr);
	_board.setMatriceValueAt(ship.getPosX() + 1, ship.getPosY() + 1, addr);
	_board.setMatriceValueAt(ship.getPosX() + 1, ship.getPosY() - 1, addr);
	_board.setMatriceValueAt(ship.getPosX() + 2, ship.getPosY(), addr);
	_board.setMatriceValueAt(ship.getPosX() + 3, ship.getPosY(), addr);
	_board.setMatriceValueAt(ship.getPosX() + 4, ship.getPosY(), addr);
}

void			Game::drawEldari(Enemy & ship, AGameEntity *addr)
{
	_board.setMatriceValueAt(ship.getPosX(), ship.getPosY(), addr);
	_board.setMatriceValueAt(ship.getPosX() + 1, ship.getPosY(), addr);
	_board.setMatriceValueAt(ship.getPosX() + 1, ship.getPosY() + 1, addr);
	_board.setMatriceValueAt(ship.getPosX() + 1, ship.getPosY() - 1, addr);
	_board.setMatriceValueAt(ship.getPosX() + 2, ship.getPosY() + 1, addr);
	_board.setMatriceValueAt(ship.getPosX() + 2, ship.getPosY() + 2, addr);
}

void			Game::drawTetris(Enemy & ship, AGameEntity *addr)
{
	_board.setMatriceValueAt(ship.getPosX(), ship.getPosY(), addr);
	_board.setMatriceValueAt(ship.getPosX() + 1, ship.getPosY(), addr);
	_board.setMatriceValueAt(ship.getPosX() + 1, ship.getPosY() + 1, addr);
	_board.setMatriceValueAt(ship.getPosX() + 1, ship.getPosY() - 1, addr);
}



