#include "Schedule.hpp"
#include <iostream>
#include <map>
#include <algorithm>

Schedule::Schedule(){}

Schedule::~Schedule(){}

string g_criterion;
int g_order;

struct compare
{
	bool operator()(Event const& a, Event const& b)
	{
		int crit_a = a.get_criterion(g_criterion);
		int crit_b = b.get_criterion(g_criterion);
		if(g_order>0)
			return (crit_a<crit_b);
		else
			return (crit_a>crit_b);
	}
}compare;

void Schedule::sort_events(string criterion, int order)
{
	g_criterion = criterion;
	g_order = order;
	sort(this->events.begin(),this->events.end(),compare);
}

void Schedule::push_back(Event event)
{
	this->events.push_back(event);
}
