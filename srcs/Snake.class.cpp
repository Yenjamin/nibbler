#include "../includes/Snake.class.hpp"

Snake::Snake(void)
{
}

Snake::Snake(int w, int h)
{
	this->init(w, h);
}

Snake::~Snake(void)
{
}

void	Snake::init(int w, int h)
{
	this->s.push_back(std::make_pair(w, h));
	for (int i = 1; i < 4; i++)
	{
		this->s.push_back(std::make_pair(w, h + i));
	}
}

std::vector<std::pair<int, int>>	Snake::getSnake(void)
{
	return this->s;
}

void	Snake::addSnake(std::pair<int, int> p)
{
	this->s.push_back(p);
}

void	Snake::moveSnake(char c)
{
	if (c == 'w')
	{
		if (direction != 's')
		{
			direction = 'w';
			tmp = s[0];
			s[0].second--;
			for (int i = 1; i < s.size(); i++)
				swap(s[i], tmp);
		}
	}
	else if (c == 's')
	{
		if (direction != 'w')
		{
			direction = 's';
			tmp = s[0];
			s[0].second++;
			for (int i = 1; i < s.size(); i++)
				swap(s[i], tmp);
		}
	}
	else if (c == 'a')
	{
		if (direction != 'd')
		{
			direction = 'a';
			tmp = s[0];
			s[0].first--;
			for (int i = 1; i < s.size(); i++)
				swap(s[i], tmp);
		}
	}
	else if (c == 'd')
	{
		if (direction != 'a')
		{
			direction = 'd';
			tmp = s[0];
			s[0].first++;
			for (int i = 1; i < s.size(); i++)
				swap(s[i], tmp);
		}
	}
}
