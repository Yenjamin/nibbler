#ifndef HEADER_HPP
# define HEADER_HPP

# include <iostream>
# include <regex>
# include "Errors.class.hpp"
# include <string>
# include "GameEngine.class.hpp"
# include "Snake.class.hpp"
# include <utility>
# include "Food.class.hpp"

struct	things_t {
	int	mWidth;
	int	mHeight;
	std::vector<std::pair<int, int>>	snake;
	std::pair<int, int>			food;
	int	i;
} everything;

#endif
