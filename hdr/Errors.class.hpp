#ifndef ERRORS_CLASS_HPP
# define ERRORS_CLASS_HPP

#include "Header.hpp"

class errors {
	public:
		class typeError : public std::exception {
			public:
				const char *what() const throw();
		};
		class argumentError : public std::exception {
			public:
				const char *what() const throw();
		};
		class libError : public std::exception {
			public:
				const char *what() const throw();
		};
		class minError : public std::exception {
			public:
				const char *what() const throw();
		};
		class maxError : public std::exception {
			public:
				const char *what() const throw();
		};
};

#endif
