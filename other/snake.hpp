#ifndef SNAKE_HPP
# define SNAKE_HPP

#include <iostream>
#include <vector>
#include <ncurses.h>
#include <cstdlib>
#include <unistd.h>

struct snakepart{
	int	x;
	int	y;
	snakepart(int col, int row);
	snakepart();
};

class snakeclass {
	int			points;
	int			del;
	int			maxwidth;
	int			maxheight;
	char			direction;
	char			partchar;
	char			oldalchar;
	char			foo;
	bool			get;
	snakepart 		food;
	std::vector<snakepart>	snake;
	
	void 	putfood();
	bool	collision();
	void	movesnake();
	public:
	snakeclass();
	~snakeclass();
	void	start();
};

#endif
