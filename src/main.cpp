#include <dlfcn.h>
#include <iostream>
#include "Header.hpp"
#include "IGraphic.hpp"

void	checkdimension(std::string width, std::string height)
{
	std::regex	num("^\\d+$");

	if (std::regex_match(width, num) == true && std::regex_match(height, num) == true)
	{
		return ;
	}
	else
		throw errors::typeError();
}

void	checklib(std::string name)
{
	std::regex      libName("(ncurses|sfml|sdl)\\b");
	if (std::regex_match(name, libName) == false)
		throw errors::libError();
}

void	checklimit(int w, int h)
{
	if (w < 10 || h < 10)
		throw errors::minError();
	if (w > 50 || h > 50)
		throw errors::maxError();
}

int	main(int argc, char **argv)
{
	try {
		int	w;
		int	h;
		std::string	lib = "sdl";
		if (argc == 4)
		{
			checkdimension(argv[1], argv[2]);
			checklib(argv[3]);
			w = atoi(argv[1]);
			h = atoi(argv[2]);
			checklimit(w, h);
			lib = argv[3];
			GameEngine	n(w, h);
			n.gameLoop(lib);
		}
		else if (argc == 3)
		{
			checkdimension(argv[1], argv[2]);
			w = atoi(argv[1]);
			h = atoi(argv[2]);
			std::cout << w << std::endl;
			std::cout << h << std::endl;
			checklimit(w, h);
			GameEngine	n(w, h);
			n.gameLoop(lib);
		}
		else
		{
			throw errors::argumentError();
		}
	} catch (std::exception &e) {
		std::cout << "Error: ";
		std::cout << e.what() << std::endl;
	} catch (std::string s) {
		std::cout << "Error: " << s << std::endl;
	} catch (const char* s) {
		std::cout << "Error: " << s << std::endl;
	}
	return (0);
}
