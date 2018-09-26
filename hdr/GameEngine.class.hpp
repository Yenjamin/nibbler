#ifndef GAMEENGINE_CLASS_HPP
# define GAMEENGINE_CLASS_HPP

#include "Header.hpp"
#include "IGraphic.hpp"

class	GameEngine {
	public:
		GameEngine(int w, int h);
		~GameEngine(void);
		void	gameLoop(std::string lib);
		void changeLibrary(int libNum);
		int	width;
		int	height;
		int	score;
		int	time;
		std::vector< std::pair<int, int> >	snake;
		std::pair<int, int>			food;
		bool	collision(void);
		std::pair<int, int>			tmp;

		void*		current_dl_handle;
		IGraphic*	CurrentLib;
		IGraphic*	(*CurrentLibCreator)(int, int);
		void	(*CurrentLibDestoyer)(IGraphic *);

		//copliens form, not used
		GameEngine(void);
		GameEngine(GameEngine const & copy);
		GameEngine& operator=(const GameEngine& rhs);
};

#endif
