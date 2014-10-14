#include "Group.hpp"
#include <iostream>
#include <map>
#include <algorithm>

Group::Group(){}

Group::~Group(){}

void Group::sort_elements(string criterion)
{
	if(criterion == "")
		return;
}

void Group::push_back(Element& element)
{
	this->elements.push_back(element);
}

vector<Element> Group::get_elements(void)
{
	return this->elements;
}
