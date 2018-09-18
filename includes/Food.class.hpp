#ifndef FOOD_CLASS_HPP
# define FOOD_CLASS_HPP

#include "Header.hpp"

class Food {
	public:
		Food(void);
		Food(int w, int h);
		~Food(void);
		int		fx;
		int		fy;
		int		x;
		int		y;
		std::pair<int, int>	foodGenerate(std::vector< std::pair<int, int> > snake);
		int		i;
};

#endif
