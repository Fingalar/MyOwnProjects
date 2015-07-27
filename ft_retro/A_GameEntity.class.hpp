/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AGameEntity.class.hpp                              :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: tmertz <tmertz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 23:56:23 by tmertz            #+#    #+#             */
/*   Updated: 2015/04/11 22:47:01 by tmertz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AGAME_ENTITY
# define AGAME_ENTITY

class		AGameEntity {
		protected :
			int				_posX;
			int				_posY;
			int				_type;

		public :
			AGameEntity();
			AGameEntity(int x, int y, int type);
			AGameEntity(AGameEntity & src);
			virtual ~AGameEntity();

			virtual AGameEntity &	operator=(AGameEntity & rhs);
			int						getPosX() const;
			int						getPosY() const;
			void					setPosX(int x);
			void					setPosY(int y);
			void					goUp(void);
			void					goDown(void);
			void					goLeft(void);
			void					goRight(void);
			int						getType();
			void					setPosition(int x, int y);
};

#endif
