#include "Element.hpp"
#include <iostream>
#include <map>
#include <string>
#include <sstream>

using namespace std;

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

void Element::set_criterion(string criterion, int value)
{
	this->criteria[criterion] = value;
}

string Element::to_string(void)
{
	stringstream ss;
	string data;

	for(map<string,int>::iterator it=this->criteria.begin();
			it!=this->criteria.end(); it++)
	{
		ss << "{" << it->first << ":" << it->second << "}";
	}

	data = ss.str();
	return data;
}
