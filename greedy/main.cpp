#include <iostream>
#include <vector>
#include "Element.hpp"
#include "Event.hpp"
#include "Group.hpp"
#include "Schedule.hpp"

using namespace std;

void schedule_group()
{
	vector<Element> result;

	Element * a = new Event(1, 4);
	Element * b = new Event(3, 5);
	Element * c = new Event(0, 6);
	Element * d = new Event(5, 7);
	Element * e = new Event(3, 8);
	Element * f = new Event(5, 9);
	Element * g = new Event(6, 10);
	Element * h = new Event(8, 11);
	Element * i = new Event(8, 12);
	Element * j = new Event(2, 13);
	Element * k = new Event(12, 14);

	Group * schedule = new Schedule();

	schedule->push_back(*a);
	schedule->push_back(*b);
	schedule->push_back(*c);
	schedule->push_back(*d);
	schedule->push_back(*e);
	schedule->push_back(*f);
	schedule->push_back(*h);
	schedule->push_back(*i);
	schedule->push_back(*j);
	schedule->push_back(*k);

	for(int cont = 0; cont < (int) result.size(); cont++)
	{
		cout << (&result[cont])->to_string() << endl;
	}

	schedule->sort_elements("lower_start");

	result = schedule->get_elements();

	for(int cont = 0; cont < (int) result.size(); cont++)
	{
		cout << result[cont] << endl;
	}


	delete a;
	delete b;
	delete c;
	delete d;
	delete e;
	delete f;
	delete g;
	delete h;
	delete i;
	delete j;
	delete k;
	delete schedule;
}

int main(void)
{
	schedule_group();

	return 0;
}
