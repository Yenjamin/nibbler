#include "Snake.class.hpp"

Snake::Snake(int w, int h)
{
	this->s.push_back(std::make_pair(w, h));
	for (int i = 1; i < 4; i++)
	{
		this->s.push_back(std::make_pair(w, h + i));
	}
	direction = UP;
}

Snake::~Snake(void)
{
}

std::vector< std::pair<int, int> >	Snake::getSnake(void)
{
	return this->s;
}

void	Snake::addSnake(std::pair<int, int> p)
{
	this->s.push_back(p);
}

void	Snake::moveSnake(keys keypressed)
{
	keys key;
	if (keypressed == UP || keypressed == DOWN || keypressed == RIGHT || keypressed == LEFT)
		key = keypressed;
	else 
		key = direction;

	if (key == UP)
	{
		if (direction != DOWN)
		{
			direction = UP;
			tmp = s[0];
			s[0].second--;
			for (int i = 1; i < static_cast<int>(s.size()); i++)
				swap(s[i], tmp);
		}
	}
	else if (key == DOWN)
	{
		if (direction != UP)
		{
			direction = DOWN;
			tmp = s[0];
			s[0].second++;
			for (int i = 1; i < static_cast<int>(s.size()); i++)
				swap(s[i], tmp);
		}
	}
	else if (key == LEFT)
	{
		if (direction != RIGHT)
		{
			direction = LEFT;
			tmp = s[0];
			s[0].first--;
			for (int i = 1; i < static_cast<int>(s.size()); i++)
				swap(s[i], tmp);
		}
	}
	else if (key == RIGHT)
	{
		if (direction != LEFT)
		{
			direction = RIGHT;
			tmp = s[0];
			s[0].first++;
			for (int i = 1; i < static_cast<int>(s.size()); i++)
				swap(s[i], tmp);
		}
	}
}

Snake::Snake(void)
{
	int w = 10;
	int h = 10;
	this->s.push_back(std::make_pair(w, h));
	for (int i = 1; i < 4; i++)
	{
		this->s.push_back(std::make_pair(w, h + i));
	}
	direction = UP;
}
Snake::Snake(Snake const & copy){
	this->width = copy.width;
	this->height = copy.height;
	this->s = copy.s;
	this->tmp = copy.tmp;
	this->direction = copy.direction;
}
Snake& Snake::operator=(const Snake& copy){
	return *(new Snake(copy));
}