#include "Food.class.hpp"

Food::Food(void)
{
	x = 10;
	y = 10;
}

Food::Food(int w, int h)
{
	x = w;
	y = h;
}

Food::~Food(void)
{
}

std::pair<int, int>	Food::foodGenerate(std::vector< std::pair<int, int> > snake)
{
	fx = rand() % x;
	fy = rand() % y;
	for (int i = 0; i < static_cast<int>(snake.size()); i++)
		if (snake[i].first == fx && snake[i].second == fy)
			foodGenerate(snake);
	if (fx >= x || fy >= y)
		foodGenerate(snake);
	return (std::make_pair(fx, fy));
}

Food::Food(const Food & copy ){
	this->fx = copy.fx;
	this->fy = copy.fy;
	this->x = copy.x;
	this->y = copy.y;
}
Food& Food::operator=(const Food& rhs){
	this->fx = rhs.fx;
	this->fy = rhs.fy;
	this->x = rhs.x;
	this->y = rhs.y;
	return (*this);
}


