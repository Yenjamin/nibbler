#include "GameEngine.class.hpp"

#define LIB1 "sdl2/SDL2.so"
#define LIB2 "ncurses/ncurses.so"
#define LIB3 "sfml/sfml.so"

void dlerror_wrapper(void)
{
	std::cerr << "Error: " << dlerror() << std::endl;
	exit(EXIT_FAILURE);
}

GameEngine::GameEngine(int w, int h) : width(w), height(h)
{
	current_dl_handle = NULL;
	CurrentLib = NULL;
	CurrentLibCreator = NULL;
	CurrentLibDestoyer = NULL;
	time = 110000;
	score = 0;
}

void GameEngine::changeLibrary(int LibNum)
{
	std::string lib;
	switch (LibNum)
	{
		case 1:
			lib = LIB1;
			break;
		case 2:
			lib = LIB2;
			break;
		case 3:
			lib = LIB3;
			break;
		default:
			lib = "Error";
			break;
	}

	if (CurrentLib)
	{
		//close lib before opening a new one
		CurrentLibDestoyer(CurrentLib);
		dlclose(current_dl_handle);
	}
	std::cout << LibNum << std::endl;
	current_dl_handle = dlopen(lib.c_str(), RTLD_LAZY | RTLD_LOCAL);
	if (!current_dl_handle)
		dlerror_wrapper();

	CurrentLibCreator = (IGraphic *(*)(int, int)) dlsym(current_dl_handle, "createLibrary");

	if (!CurrentLibCreator)
		dlerror_wrapper();
	
	CurrentLib = CurrentLibCreator(width, height);
	CurrentLibDestoyer = (void (*)(IGraphic *)) dlsym(current_dl_handle, "deleatLibrary");
	if (!CurrentLibDestoyer)
		dlerror_wrapper();
}

GameEngine::~GameEngine(void)
{
	CurrentLibDestoyer(CurrentLib);
	dlclose(current_dl_handle);
	std::cout << "Your final score was: " << score << std::endl;
	std::cout << "Quiting game. Thanks for playing!" << std::endl;
}

void	GameEngine::gameLoop(std::string lib)
{
	keys keypressed;
	Snake	s(width / 2, height / 2);
	Food	f(width, height);
	snake = s.getSnake();
	food = f.foodGenerate(snake);
	if (lib == "sdl")
		changeLibrary(1);
	else if (lib == "ncurses")
		changeLibrary(2);
	else if (lib == "sfml")
		changeLibrary(3);

	while (1)
	{
		tmp = std::make_pair(0, 0);
		snake = s.getSnake();
		if (static_cast<int>(snake.size()) == (width * height))
		{
			std::cout << "you... have no life" << std::endl;
			break;
		}
		if (snake[0] == food)
		{
			food = f.foodGenerate(snake);
			score += 10;
			//increase speed
			if ( time >= 20000)
				time -= 1000;
			tmp = snake[snake.size() - 1];
		}
		std::cout << "score: " << score << std::endl; //Must we display the score here?
		keypressed = CurrentLib->keypress();
		s.moveSnake(keypressed);
		if (keypressed == ONE)
			changeLibrary(1);
		else if (keypressed == TWO)
			changeLibrary(2);
		else if (keypressed == THREE)
			changeLibrary(3);
		else if (keypressed == ESQ)
			break;
			
		if (tmp != std::make_pair(0, 0))
			s.addSnake(tmp);
		if (collision())
		{
			std::cout << "no!!!! You hit somthing" << std::endl;
			break;
		}
		CurrentLib->drawAndDisplay(snake, food);
		usleep(time);
	}
	
}

bool	GameEngine::collision(void)
{
	if (snake[0].first >= width)
		return true;
	if (snake[0].second >= height)
		return true;
	if (snake[0].first < 0)
		return true;
	if (snake[0].second < 0)
		return true;
	for (int i = 2; i < static_cast<int>(snake.size()); i++)
	{
		if (snake[0] == snake[i])
			return true;
	}
	return false;
}

GameEngine::GameEngine(void): width(10), height(10)
{
	current_dl_handle = NULL;
	CurrentLib = NULL;
	CurrentLibCreator = NULL;
	CurrentLibDestoyer = NULL;
	time = 110000;
	score = 0;
}
GameEngine::GameEngine(GameEngine const & copy){
	this->width = copy.width;
	this->height = copy.height;
	this->score = copy.score;
	this->time = copy.time;
	this->snake = copy.snake;
	this->food = copy.food;
	this->tmp = copy.tmp;
	current_dl_handle = NULL;
	CurrentLib = NULL;
	CurrentLibCreator = NULL;
	CurrentLibDestoyer = NULL;
}
GameEngine& GameEngine::operator=(const GameEngine& copy){
	return *(new GameEngine(copy));
}
