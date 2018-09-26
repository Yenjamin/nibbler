#ifndef SFML_HPP
#define SFML_HPP

#include "IGraphic.hpp"
#include <SFML/Graphics.hpp>

class sfml : IGraphic
{
public:
	sfml(int width_in_blocks, int hight_in_blocks);
	~sfml(void);

	//copliens form, not used
	sfml(void);
	sfml(const sfml & copy);
	sfml& operator=(const sfml& copy);
	
	void drawAndDisplay(std::vector< std::pair< int, int> > snake
	, std::pair<int, int> food) override;
	void drawSnake(std::vector< std::pair< int, int> > snake) ;
	void drawFood(std::pair<int, int> food) ;
	void display(void) ;
	keys keypress(void) override;
private:
	int 				_width;
	int 				_hight;
	float				_block_size = 20.f;
	sf::RenderWindow*	_window;
	sf::Event 			_ev;
};

extern "C"
{
	sfml* createLibrary(int width_in_blocks, int hight_in_blocks) ;
	void deleatLibrary(sfml* lib) ;
}
#endif