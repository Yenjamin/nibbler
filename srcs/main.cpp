#include "../includes/Header.hpp"

/*void	checkdimension(std::string width, std::string height)
{
	std::regex	num("^\\d+$");

	if (std::regex_match(width, num) == true)
	{
		if (std::regex_match(height, num) == true)
			return ;
		else
			throw errors::typeError();
	}
	else
		throw errors::typeError();
}

void	checklib(std::string name)
{
	std::regex      libName("(ncurses|sfml|sdl)\\b");
	if (std::regex_match(name, libName) == false)
		throw errors::libError();
}*/

int	main(int argc, char **argv)
{
	try {
		if (argc == 4)
		{
			/*checkdimension(argv[1], argv[2]);
			checklib(argv[3]);*/
		}
		else if (argc == 3)
		{
//			checkdimension(argv[1], argv[2]);
			everything.mWidth = atoi(argv[1]);
			everything.mHeight = atoi(argv[2]);
			std::cout << everything.mWidth << std::endl;
			std::cout << everything.mHeight << std::endl;
			//GameEngine	n(e);
			//n.gameLoop();
		}
		else
		{
			throw errors::argumentError();
		}
	} catch (std::exception &e) {
		std::cout << "Error: ";
		std::cout << e.what() << std::endl;
	}
	return (0);
}
