#include "Group.hpp"
#include <iostream>
#include <map>
#include <algorithm>

Group::Group(){}

Group::~Group(){}

string g_criterion;
int g_order;

struct compare
{
	bool operator()(Element const& a, Element const& b)
	{
		int crit_a = a.get_criterion(g_criterion);
		int crit_b = b.get_criterion(g_criterion);
		if(g_order>0)
			return (crit_a<crit_b);
		else
			return (crit_a>crit_b);
	}
}compare;

void Group::sort_elements(string criterion, int order)
{
	g_criterion = criterion;
	g_order = order;
	sort(this->elements.begin(),this->elements.end(),compare);
}

void Group::push_back(Element element)
{
	this->elements.push_back(element);
}
