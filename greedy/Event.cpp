#include "Event.hpp"
#include <iostream>
#include <climits>
#include <map>

Event::Event(){}

Event::~Event(){}

map<string,int> Event::get_criteria(void)
{
	return this->criteria;
}

int Event::get_criterion(string criterion)
const
{
	map<string,int>aux = this->criteria;
	return aux[criterion];
}
