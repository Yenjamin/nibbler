#include "../includes/Snake.class.hpp"

Snake::Snake(void)
{
}

Snake::Snake(int w, int h)
{
	s.push_back(std::make_pair(w, h));
	std::cout << s[0].first << std::endl;
	std::cout << s[0].second << std::endl;
}

Snake::~Snake(void)
{
}

/*void	Snake::movesnake(void)
{
}*/
