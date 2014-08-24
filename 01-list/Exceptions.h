#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>
#include <exception>

struct key_not_found : std::exception
{
	const char* what() const throw() {return "\nKey not found\n";}
};

struct element_already_exists : std::exception
{
	const char* what() const throw() {return "\nElement already exists\n";}
};

struct circular_array_not_sorted : std::exception
{
	const char* what() const throw(){return "\nThe circular array isn't sorted\n";}
};

#endif