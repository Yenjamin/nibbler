#ifndef SNAKE_HPP
# define SNAKE_HPP

#include <iostream>
#include <vector>
#include <ncurses.h>
#include <cstdlib>
#include <unistd.h>

class snakeclass {
	public:
		snakeclass();
		snakeclass(int const width, int const height);
		~snakeclass();
		void					loop();
		std::vector<std::pair<int, int>>	snake;
		std::pair<int, int>			food;
		int					score;
		int					maxwidth;
		int					maxheight;
		char					direction;
		bool					get;
};

#endif
