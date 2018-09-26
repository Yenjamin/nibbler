#include "ncurses.hpp"

ncurses::ncurses(int w, int h) : _width(w), _hight(h)
{
	initscr();
	cbreak();
	noecho();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	curs_set(0);

	clear();
	redrawwin(stdscr);
	wrefresh(stdscr);
}

ncurses::~ncurses(void)
{
	endwin();
}

void ncurses::drawBorder(void)
{
	for (int i = 0; i <= _hight; i++)
	{
		mvaddch(i, _width * 2, '|');
	}
	for (int i = 0; i < _width * 2; i++)
	{
		mvaddch(_hight, i, '_');
	}
}

void ncurses::drawAndDisplay(std::vector< std::pair< int, int> > snake
	, std::pair<int, int> food) 
{
	
	clear();
	drawBorder();
	drawFood(food);
	drawSnake(snake);
	display();
}

void ncurses::drawSnake(std::vector< std::pair< int, int> > snake)
{
	for (std::pair<int, int> body : snake)
	{
		mvaddch(body.second, body.first * 2, 'O');
	}
	mvaddch(snake[0].second, snake[0].first * 2, '*');
}

void ncurses::drawFood(std::pair<int, int> food)
{
	mvaddch(food.second, food.first * 2, 'F');
}

void ncurses::display(void)
{
	refresh();
}

keys ncurses::keypress(void)
{
	int key = wgetch(stdscr);
	switch (key)
	{
		case 'a':
			return LEFT;
			break;
		case KEY_LEFT:
			return LEFT;
			break;
		case 's':
			return DOWN;
			break;
		case KEY_DOWN:
			return DOWN;
			break;
		case 'd':
			return RIGHT;
			break;
		case KEY_RIGHT:
			return RIGHT;
			break;
		case 'w':
			return UP;
			break;
		case KEY_UP:
			return UP;
			break;
		case ' ':
			return PAUSE;
			break;
		case '1':
			return ONE;
			break;
		case '2':
			return TWO;
			break;
		case '3':
			return THREE;
			break;
		case 27:
			return ESQ;
			break;
		default:
			return NONE;
			break;
	}
	return NONE;
}

ncurses*	createLibrary(int w, int h)
{
	return new ncurses(w, h);
}

void deleatLibrary(ncurses* Lib)
{
	delete Lib;
}


ncurses::ncurses(void) : _width(10), _hight(10)
{
	initscr();
	cbreak();
	noecho();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	curs_set(0);

	clear();
	redrawwin(stdscr);
	wrefresh(stdscr);
}
ncurses::ncurses(ncurses* const & copy)
{
	this->_hight = copy->_hight;
	this->_width = copy->_width;
}
ncurses& ncurses::operator=(const ncurses& rhs)
{
	this->_hight = rhs._hight;
	this->_width = rhs._width;
	return *this;
}
