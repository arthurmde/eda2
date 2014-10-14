#ifndef SCHEDULE_HPP_
#define SCHEDULE_HPP_

#include <string>
#include <vector>
#include "Element.hpp"
#include "Group.hpp"

using namespace std;

class Schedule : public Group
{
    public:
        Schedule();
        ~Schedule();

        void sort_elements(string criterion);
};

#endif
