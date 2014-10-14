#include "Schedule.hpp"
#include "Event.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

Schedule::Schedule(){}

Schedule::~Schedule(){}

void Schedule::sort_elements(string criterion)
{
	if(criterion == "")
		return;

	Event::criterion = criterion;

	sort(this->elements.begin(), this->elements.end());
}