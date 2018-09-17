#include "../includes/Food.class.hpp"

Food::Food(void)
{
}

Food::Food(int w, int h)
{
	x = w;
	y = h;
}

Food::~Food(void)
{
}

std::pair<int, int>	Food::foodGenerate(void)
{
	fx = rand() % x + 1;
	fy = rand() % y + 1;
//	return (std::make_pair(fx, fy));
	return (std::make_pair(6, 10));
}


