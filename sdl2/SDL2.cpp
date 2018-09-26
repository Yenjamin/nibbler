#include "SDL2.hpp"

#include <iostream>

SDL2*	createLibrary(int w, int h)
{
	return new SDL2(w, h);
}

void deleatLibrary(SDL2* Lib)
{
	delete Lib;
}

SDL2::SDL2(int w, int h)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_CreateWindowAndRenderer(
		w * this->_block_size
		, h * this->_block_size
		, 0, &_window, &_renderer);
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 0);
	SDL_RenderClear(_renderer);
}

SDL2::~SDL2(void)
{
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

void SDL2::drawAndDisplay(std::vector< std::pair< int, int> > snake
	, std::pair<int, int> food) 
{
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 0);
	SDL_RenderClear(_renderer);
	drawFood(food);
	drawSnake(snake);
	display();
}

void SDL2::drawRect(int x, int y, Uint8 r, Uint8 g, Uint8 b)
{
	SDL_Rect c;
	c.x = (x * this->_block_size) + 1;
	c.y = (y * this->_block_size) + 1;
	c.w = this->_block_size - 2;
	c.h = this->_block_size - 2;
	SDL_SetRenderDrawColor( this->_renderer, r, g, b, 255 );
	SDL_RenderFillRect( this->_renderer, &c );
}

void SDL2::drawSnake(std::vector< std::pair<int, int> > snake)
{
	for (std::pair<int, int> body : snake)
	{
		drawRect(body.first, body.second, 0, 255, 0);
	}
	// std::cout << snake[0].first << ", " << snake[0].second << std::endl;

	drawRect(snake[0].first, snake[0].second, 0, 0, 255);
}

void SDL2::drawFood(std::pair<int, int> food)
{
	drawRect(food.first, food.second, 255, 0, 0);
}

void SDL2::display(void)
{
	SDL_RenderPresent(_renderer);
}

keys SDL2::keypress(void)
{
	while (SDL_PollEvent(&_event))
	{
		if(_event.type == SDL_KEYDOWN)
		{
			switch (_event.key.keysym.sym)
			{
				case SDLK_w:
					return UP;
				case SDLK_UP:
					return UP;
				case SDLK_s:
					return DOWN;
				case SDLK_DOWN:
					return DOWN;
				case SDLK_a:
					return LEFT;
				case SDLK_LEFT:
					return LEFT;
				case SDLK_d:
					return RIGHT;
				case SDLK_RIGHT:
					return RIGHT;
				case SDLK_SPACE:
					return PAUSE;
				case SDLK_ESCAPE:
					return ESQ;
				case SDLK_1:
					return ONE;
				case SDLK_2:
					return TWO;
				case SDLK_3:
					return THREE;
			}
		}
	}
	return NONE;
}

SDL2::SDL2(void)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_CreateWindowAndRenderer(
		10 * this->_block_size
		, 10 * this->_block_size
		, 0, &_window, &_renderer);
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 0);
	SDL_RenderClear(_renderer);
}
SDL2::SDL2(const SDL2 & copy){
	this->_block_size = copy._block_size;
	this->_renderer = copy._renderer;
	this->_event = copy._event;
	this->_window = copy._window;
}
SDL2& SDL2::operator=(const SDL2& copy){
	return *(new SDL2(copy));
}