#include "Element.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

Element::Element(){}

Element::~Element(){}

bool operator< (Element const &e1, Element const &e2)
{
	return e1.less_than(e2);
}

ostream& operator<< (ostream& stream, const Element& element)
{
	stream << element.to_string();
    return stream;
}

// vector<string> Element::get_criteria()
// {
// 	return this->criteria;
// }

bool Element::less_than(Element const &e2) const
{
	return true;
}

string Element::to_string() const
{
	return "";
}

// map<string,int> Element::get_criteria(void)
// {
// 	return this->criteria;
// }

// int Element::get_criterion(string criterion)
// const
// {
// 	map<string,int>aux = this->criteria;
// 	return aux[criterion];
// }

// void Element::set_criterion(string criterion, int value)
// {
// 	this->criteria[criterion] = value;
// }

// string Element::to_string(void)
// {
// 	stringstream ss;
// 	string data;

// 	for(map<string,int>::iterator it=this->criteria.begin();
// 			it!=this->criteria.end(); it++)
// 	{
// 		ss << "{" << it->first << ":" << it->second << "}";
// 	}

// 	data = ss.str();
// 	return data;
// }
