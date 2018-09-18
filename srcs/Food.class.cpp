#include "../includes/Food.class.hpp"

Food::Food(void)
{
}

Food::Food(int w, int h)
{
	i = 0;
	x = w;
	y = h;
}

Food::~Food(void)
{
}

std::pair<int, int>	Food::foodGenerate(std::vector< std::pair<int, int> > snake)
{
	i++;
	std::cout << "food loop: " << i << std::endl;
	fx = rand() % x + 1;
	fy = rand() % y + 1;
//	fx = 6;
//	fy = 10;
	std::cout << "food: " << fx << ", " << fy << std::endl;
	for (int i = 0; i < snake.size(); i++)
		if (snake[i].first == fx && snake[i].second == fy)
			foodGenerate(snake);
	if (fx >= x - 1 || fy >= y - 1)
		foodGenerate(snake);
//	return (std::make_pair(fx, fy));
	return (std::make_pair(6, 10));
}
