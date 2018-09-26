#ifndef SDL2_HPP
#define SDL2_HPP

#include "IGraphic.hpp"
#include <SDL.h>

class SDL2 : IGraphic
{
public:
	SDL2(int width_in_blocks, int hight_in_blocks);
	~SDL2(void);

	//copliens form, not used
	SDL2(void);
	SDL2(const SDL2 & copy);
	SDL2& operator=(const SDL2& copy);

	keys keypress(void) override;
	void drawAndDisplay(std::vector< std::pair< int, int> > snake
		, std::pair<int, int> food) override;
private:
	int				_block_size = 20;
	SDL_Renderer *	_renderer;
	SDL_Event		_event;
	SDL_Window *	_window;
	void drawRect(int x, int y, Uint8 r, Uint8 g, Uint8 b);
	void drawSnake(std::vector< std::pair< int, int> > snake) ;
	void drawFood(std::pair<int, int> food) ;
	void display(void) ;

};

extern "C"
{
	SDL2* createLibrary(int width_in_blocks, int hight_in_blocks) ;
	void deleatLibrary(SDL2* lib) ;

}
#endif