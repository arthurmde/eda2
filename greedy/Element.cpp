#include "Element.hpp"
#include <iostream>
#include <climits>
#include <map>

Element::Element(){}

Element::~Element(){}

map<string,int> Element::get_criteria(void)
{
	return this->criteria;
}

int Element::get_criterion(string criterion)
const
{
	map<string,int>aux = this->criteria;
	return aux[criterion];
}
