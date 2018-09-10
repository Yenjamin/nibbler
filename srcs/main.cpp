#include "../includes/Header.hpp"

void	checkdimension(std::string width, std::string height)
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
}

int	main(int argc, char **argv)
{
	GameEngine	n;
	try {
		if (argc == 4)
		{
			checkdimension(argv[1], argv[2]);
			std::regex	libName("(ncurses|sfml|sdl)\\b");
			checklib(argv[3]);
		}
		else if (argc == 3)
		{
			checkdimension(argv[1], argv[2]);
			n.gameLoop();
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
