#include "snake.hpp"

snakeclass::snakeclass()
{
}

snakeclass::snakeclass(int const width, int const height) : maxwidth(width), maxheight(height)
{
}

snakeclass::~snakeclass()
{
}

void	snakeclass::loop()
{
	int	i = 2;
	while (1)
	{
		if (i == 0)
			break;
		std::cout << maxwidth << std::endl;
		std::cout << maxheight << std::endl;
		i--;
	}
}
