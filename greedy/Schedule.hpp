#ifndef SCHEDULE_HPP_
#define SCHEDULE_HPP_

#include <string>
#include <vector>
#include "Event.hpp"

using namespace std;

class Schedule
{
    public:
        Schedule();
        ~Schedule();
		void sort_events(string criterion, int order);
		vector<Event> get_events(void);
		void push_back(Event);

    private:
		vector<Event> events;

};

#endif
