
#include "sfml.hpp"
#include <iostream>


#include <dlfcn.h>
#include <iostream>
#include <stdlib.h> 
#include <time.h>

void sfml::drawAndDisplay(std::vector< std::pair< int, int> > snake
	, std::pair<int, int> food)
{
	_window->clear();
	drawFood(food);
	drawSnake(snake);
	display();
}

sfml::sfml(int x, int y)
{
	this->_width = x;
	this->_hight = y;
	_window = new sf::RenderWindow(
		sf::VideoMode(x * _block_size, y * _block_size)
		, "SFML works!");
	sf::Vector2i pos(600,200);
	_window->setPosition(pos);
	_window->clear();
}

sfml::~sfml(void)
{
	_window->close();
	delete _window;
}

void sfml::drawSnake(std::vector< std::pair< int, int> > snake)
{
	sf::CircleShape shape((_block_size/2) - 1);
	shape.setFillColor(sf::Color::Green);
	for (std::pair<int, int> body : snake)
	{
		shape.setPosition(body.first * _block_size, body.second * _block_size);
		_window->draw(shape);
	}
	
	shape.setFillColor(sf::Color::Blue);
	shape.setPosition(snake[0].first * _block_size, snake[0].second * _block_size);
	_window->draw(shape);
}

void sfml::drawFood(std::pair<int, int> food)
{
	sf::CircleShape shape((_block_size/2) - 1);
	shape.setFillColor(sf::Color::Red);
	shape.setPosition(food.first * _block_size, food.second * _block_size);
	_window->draw(shape);
}

void sfml::display(void)
{
	this->_window->display();
}

keys sfml::keypress(void)
{
	while (_window->pollEvent(_ev))
	{
		if (_ev.type == sf::Event::KeyPressed)
		{
			switch (_ev.key.code)
			{
				case sf::Keyboard::A:
					return LEFT;
					break;
				case sf::Keyboard::Left:
					return LEFT;
				case sf::Keyboard::S:
					return DOWN;
					break;
				case sf::Keyboard::Down:
					return DOWN;
				case sf::Keyboard::D:
					return RIGHT;
					break;
				case sf::Keyboard::Right:
					return RIGHT;
				case sf::Keyboard::W:
					return UP;
					break;
				case sf::Keyboard::Up:
					return UP;
				case sf::Keyboard::Space:
					return PAUSE;
				case sf::Keyboard::Escape:
					return ESQ;
					break;
				case sf::Keyboard::Num1:
					return ONE;
					break;
				case sf::Keyboard::Num2:
					return TWO;
					break;
				case sf::Keyboard::Num3:
					return THREE;
					break;
				default :
					return NONE;
					break;
				
			}
		}
	}
	return NONE;
}

sfml*	createLibrary(int w, int h)
{
	return new sfml(w, h);
}

void deleatLibrary(sfml* Lib)
{
	delete Lib;
}

sfml::sfml(void)
{
	this->_width = 10;
	this->_hight = 10;
	_window = new sf::RenderWindow(
		sf::VideoMode(10 * _block_size, 10 * _block_size)
		, "SFML works!");
	sf::Vector2i pos(600,200);
	_window->setPosition(pos);
	_window->clear();
}
sfml::sfml(const sfml & copy){
	this->_block_size = copy._block_size;
	this->_width = copy._width;
	this->_hight = copy._hight;
	this->_window = copy._window;
	this->_ev = copy._ev;
}
sfml& sfml::operator=(const sfml& copy){
	return *(new sfml(copy));
}