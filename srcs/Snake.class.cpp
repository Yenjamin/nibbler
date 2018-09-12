#include "../includes/Snake.class.hpp"

Snake::Snake(void)
{
}

Snake::Snake(int w, int h)
{
	s.push_back(std::make_pair(w / 2, h / 2));
}

Snake::~Snake(void)
{
}
