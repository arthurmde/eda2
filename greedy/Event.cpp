#include "Event.hpp"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Event::Event()
{
	// this->set_criteria();
}

Event::Event(int start, int end)
{
	this->start = start;
	this->end = end;

	// this->set_criteria();
}

// void Event::set_criteria()
// {
// 	this->criteria.push_back("lower_start");
// 	this->criteria.push_back("higher_start");
// 	this->criteria.push_back("lower_end");
// 	this->criteria.push_back("higher_end");
// 	this->criteria.push_back("lower_duration");
// 	this->criteria.push_back("higher_duration");
// }

Event::~Event(){}

string Event::criterion = "lower_start";

bool Event::less_than(Element const &e2) const
{
	const Event& event2 = dynamic_cast<const Event&>(e2);

	if(Event::criterion == "lower_start")
		return this->start < event2.start;
	else if(Event::criterion == "higher_start")
		return this->start > event2.start;
	else if(Event::criterion == "lower_end")
		return this->end < event2.end;
	else if(Event::criterion == "higher_end")
		return this->end > event2.end;
	else if(Event::criterion == "lower_duration")
		return (this->end - this->start) < (event2.end - event2.start);
	else
		return (this->end - this->start) > (event2.end - event2.start);
}

string Event::to_string() const
{
	cout << "ENTREIII" << endl;
	std::ostringstream os;
	os << "Start: ";
	os << this->start;
	os << " and End: ";
	os << this->end;
	return os.str() ;
}