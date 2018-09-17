#ifndef SNAKE_CLASS_HPP
# define SNAKE_CLASS_HPP

# include "Header.hpp"

class Snake {
	public:
		Snake(void);
		Snake(int w, int h);
		~Snake(void);
		int					width;
		int					height;
		std::vector<std::pair<int, int>>	s;
		std::pair<int, int>			tmp;
		void					init(int w, int h);
		std::vector<std::pair<int, int>>	getSnake(void);
		void					addSnake(std::pair<int, int>);
		void					moveSnake(char c);
		char					direction;
};

#endif
