#ifndef ELEMENT_HPP_
#define ELEMENT_HPP_

#include <string>
#include <map>

using namespace std;

class Element
{
    public:
        Element();
        ~Element();

		map<string,int> get_criteria(void);
		int get_criterion(string criterion) const;

    private:
		map<string,int>criteria;
};

#endif
