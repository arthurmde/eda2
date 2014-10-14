#ifndef ELEMENT_HPP_
#define ELEMENT_HPP_

#include <string>
#include <vector>

using namespace std;

class Element
{
    public:
        Element();
        virtual ~Element();

        friend bool operator< (Element const &e1, Element const &e2);
        friend ostream& operator<< (ostream& stream, const Element& element);

        //virtual void set_criteria();
        //vector<string> get_criteria();

        virtual bool less_than(Element const &e2) const;
        virtual string to_string() const;

		// map<string,int> get_criteria(void);
		// int get_criterion(string) const;
		// void set_criterion(string, int);
		// string to_string(void);

	protected:
		
		//vector<string> criteria;
    private:
		// map<string,int>criteria;
};

#endif
