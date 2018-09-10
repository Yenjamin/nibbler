#include "../includes/Errors.class.hpp"
#include "../includes/Header.hpp"

const char	*errors::typeError::what() const throw()
{
	return ("parameters entered is not a number");
}

const char	*errors::argumentError::what() const throw()
{
	return ("incorrect amount of arguments");
}

const char	*errors::libError::what() const throw()
{
	return ("unidentified library");
}
