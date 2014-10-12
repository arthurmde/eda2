#ifndef EVENT_HPP_
#define EVENT_HPP_

#include <string>
#include <map>

using namespace std;

class Event
{
    public:
        Event();
        ~Event();

		map<string,int> get_criteria(void);
		int get_criterion(string criterion) const;

    private:
		map<string,int>criteria;
};

#endif
