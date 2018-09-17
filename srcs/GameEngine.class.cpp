#include "../includes/GameEngine.class.hpp"

GameEngine::GameEngine(void)
{
}

GameEngine::GameEngine(int w, int h) : width(w), height(h)
{
	//time = 1100000;
	//score = 0;
}

GameEngine::~GameEngine(void)
{
}

void	GameEngine::gameLoop(void)
{
	int	i = 2;
	Snake	s(width / 2, height / 2);
	Food	f(width, height);
	while (1)
	{
		tmp = std::make_pair(0, 0);
		if (i == 0)
			break;
		std::cout << i << std::endl;
		food = f.foodGenerate();
		std::cout << food.first << std::endl;
		std::cout << food.second << std::endl;
		snake = s.getSnake();
		if (snake[0] == food)
		{
			tmp = snake[snake.size() - 1];
		}
		s.moveSnake('w');
		if (tmp != std::make_pair(0, 0))
			s.addSnake(tmp);
		for (int i = 0; i < snake.size(); i++)
		{
			std::cout << snake[i].first << std::endl;
			std::cout << snake[i].second << std::endl;
		}
		i--;
		if (collision())
		{
			std::cout << "no!!!!" << std::endl;
			break;
		}
		usleep(1100000);
	}
}

bool	GameEngine::collision(void)
{
	if (snake[0].first == width)
		return true;
	if (snake[0].second == height)
		return true;
	if (snake[0].first == 0)
		return true;
	if (snake[0].second == 0)
		return true;
	for (int i = 2; i < snake.size(); i++)
	{
		if (snake[0] == snake[i])
			return true;
	}
	return false;
}
