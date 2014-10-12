#ifndef GROUP_HPP_
#define GROUP_HPP_

#include <string>
#include <vector>
#include "Element.hpp"

using namespace std;

class Group
{
    public:
        Group();
        ~Group();
		void sort_elements(string criterion, int order);
		vector<Element> get_elements(void);
		void push_back(Element);

    private:
		vector<Element> elements;

};

#endif
