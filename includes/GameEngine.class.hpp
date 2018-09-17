#ifndef GAMEENGINE_CLASS_HPP
# define GAMEENGINE_CLASS_HPP

#include "Header.hpp"

class	GameEngine {
	public:
		GameEngine(void);
		GameEngine(int w, int h);
		~GameEngine(void);
		void	gameLoop(void);
		int	width;
		int	height;
		//int	score;
		//int	time;
		std::vector<std::pair<int, int>>	snake;
		std::pair<int, int>			food;
		bool	collision(void);
		std::pair<int, int>			tmp;
};

#endif
