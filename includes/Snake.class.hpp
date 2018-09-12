#ifndef SNAKE_CLASS_HPP
# define SNAKE_CLASS_HPP

# include "Header.hpp"

class Snake {
	public:
		Snake(void);
		Snake(int w, int h);
		~Snake(void);
		std::vector<std::pair<int, int>>	s;
		void	addSnake(int w, int h);
		void	movesnake(char d);
};

#endif
