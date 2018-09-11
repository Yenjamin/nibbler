#include "snake.hpp"

int	main(int ac, char** av)
{
	if (ac == 3)
	{
		int	x = atoi(av[1]);
		int	y = atoi(av[2]);
		snakeclass	s(x, y);
		s.loop();
	}
	else
		std::cout << "no!" << std::endl;
	return (0);
}
