#ifndef NCURSES_HPP
#define NCURSES_HPP

#include "IGraphic.hpp"
#include <curses.h>

class ncurses : IGraphic
{
public:
	ncurses(int w, int h);
	~ncurses(void);

	//coplians form, not used
	ncurses(void);
	ncurses(ncurses* const & copy);
	ncurses& operator=(const ncurses& rhs);

	keys keypress(void) override;
	void drawAndDisplay(std::vector< std::pair< int, int> > snake
	, std::pair<int, int> food) override;
private:
	int	_width;
	int	_hight;
	void drawBorder(void);
	void drawSnake(std::vector< std::pair< int, int> > snake) ;
	void drawFood(std::pair<int, int> food) ;
	void display(void) ;
};

extern "C"
{
	ncurses* createLibrary(int width_in_blocks, int hight_in_blocks) ;
	void deleatLibrary(ncurses* lib) ;

}
#endif