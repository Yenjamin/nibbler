#ifndef GAMEENGINE_CLASS_HPP
# define GAMEENGINE_CLASS_HPP

#include "Header.hpp"

class	GameEngine {
	public:
		GameEngine(void);
		GameEngine(int w, int h);
		~GameEngine(void);
		void	gameLoop(void);
		int	_width;
		int	_height;
		std::pair<int, int>	k;
};

#endif
