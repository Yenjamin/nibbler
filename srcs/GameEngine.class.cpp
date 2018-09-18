#include "../includes/GameEngine.class.hpp"

GameEngine::GameEngine(void)
{
}

GameEngine::GameEngine(int w, int h) : width(w), height(h)
{
	time = 1100000;
	score = 0;
}

GameEngine::~GameEngine(void)
{
}

void	GameEngine::gameLoop(void)
{
	int	i = 2;
	Snake	s(width / 2, height / 2);
	Food	f(width, height);
	snake = s.getSnake();
	food = f.foodGenerate(snake);
	while (1)
	{
		tmp = std::make_pair(0, 0);
//		if (i == 0)
//			break;
		std::cout << "loop number: " << i << std::endl;
		std::cout << "food pos: " << food.first << ", " << food.second << std::endl;
		snake = s.getSnake();
		if (snake[0] == food)
		{
			/*score += 10;
			if ( time >= 50000)
				time -= 1000;*/
			food = f.foodGenerate(snake);
			tmp = snake[snake.size() - 1];
		}
		//std::cout << score << std::endl;
		//std::cout << time << std::endl;
		if (i >= 0)
			s.moveSnake('w');
		else if ( i == -1)
			s.moveSnake('a');
		else if (i == -2)
			s.moveSnake('s');
		else if (i == -3)
			s.moveSnake('d');
		if (tmp != std::make_pair(0, 0))
			s.addSnake(tmp);
		for (int i = 0; i < snake.size(); i++)
		{
			std::cout << "snake pos" << i << ": " << snake[i].first << ", " <<snake[i].second << std::endl;
		}
		i--;
		if (collision())
		{
			std::cout << "no!!!!" << std::endl;
			break;
		}
		usleep(time);
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
