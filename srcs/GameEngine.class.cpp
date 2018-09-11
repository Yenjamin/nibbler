#include "../includes/GameEngine.class.hpp"

GameEngine::GameEngine(void)
{
}

GameEngine::GameEngine(int w, int h) : _width(w), _height(w)
{
}

GameEngine::~GameEngine(void)
{
}

void	GameEngine::gameLoop(void)
{
	int	i = 2;
	Snake	s(_width / 2, _height / 2);
	Food	f(_width, _height);
	while (1)
	{
		if (i == 0)
			break;
		std::cout << i << std::endl;
		k = f.foodGenerate();
		std::cout << k.first << std::endl;
		std::cout << k.second << std::endl;
		i--;
	}
}
