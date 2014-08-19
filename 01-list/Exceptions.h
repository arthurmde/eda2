#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>
#include <exception>

struct key_not_found : std::exception
{
  const char* what() const throw() {return "Key not found\n";}
};

struct element_already_exists : std::exception
{
  const char* what() const throw() {return "Element already exists\n";}
};

#endif