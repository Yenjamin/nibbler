#include "Errors.class.hpp"

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

const char	*errors::minError::what() const throw()
{
	return ("value given is too low, has to be 10 or above");
}

const char	*errors::maxError::what() const throw()
{
	return ("value given is too big, has to be 50 or below");
}
