#ifndef SCHEDULE_HPP_
#define SCHEDULE_HPP_

#include <string>
#include "Event.hpp"

using namespace std;

class Schedule
{
    public:
        Schedule();
        ~Schedule();
		void sort(string criterion, bool order);

    private:
		vector<Event> events;

};

#endif
