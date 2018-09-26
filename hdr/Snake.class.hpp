#ifndef SNAKE_CLASS_HPP
# define SNAKE_CLASS_HPP

# include "Header.hpp"
#include "e_keys.hpp"

class Snake {
	public:
		
		Snake(int w, int h);
		~Snake(void);
		int					width;
		int					height;
		std::vector< std::pair<int, int> >	s;
		std::pair<int, int>			tmp;
		std::vector< std::pair<int, int> >	getSnake(void);
		void					addSnake(std::pair<int, int>);
		void					moveSnake(keys key);
		keys					direction;

		//copliens form, not used
		Snake(void);
		Snake(Snake const & copy);
		Snake& operator=(const Snake& copy);
};

#endif
