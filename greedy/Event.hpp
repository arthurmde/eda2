#ifndef EVENT_HPP_
#define EVENT_HPP_

#include <string>
#include "Element.hpp"

using namespace std;

class Event : public Element
{
    public:
        Event();
        Event(int start, int end);
         ~Event();

        virtual bool less_than(Element const &e2) const;
        virtual string to_string() const;

        static string criterion;

    	int start;
    	int end;
};

#endif
