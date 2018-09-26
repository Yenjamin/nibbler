#ifndef IGRAPHIC_HPP
#define IGRAPHIC_HPP

#include "e_keys.hpp"
#include <vector>

class IGraphic
{
public:
	virtual void drawAndDisplay(std::vector< std::pair< int, int> > snake
		, std::pair<int, int> food) = 0;
	virtual keys keypress(void) = 0;
	virtual ~IGraphic(void){};
};

#endif