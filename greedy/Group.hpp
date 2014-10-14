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
        virtual ~Group();
		virtual void sort_elements(string criterion);
		virtual vector<Element> get_elements(void);
		void push_back(Element& element);

    protected:
		vector<Element> elements;

};

#endif
