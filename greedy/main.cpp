#include <iostream>
#include <vector>
#include "Element.hpp"
#include "Group.hpp"

using namespace std;

int main(void)
{
	vector<Element> result;

	Element a = Element();
	Element b = Element();
	Element c = Element();
	Element d = Element();
	Element e = Element();
	Element f = Element();
	Element g = Element();

	a.set_criterion("valor",1);
	b.set_criterion("valor",5);
	c.set_criterion("valor",10);
	d.set_criterion("valor",10);
	e.set_criterion("valor",20);
	f.set_criterion("valor",50);
	g.set_criterion("valor",100);
	
	Group grupo =  Group();

	grupo.push_back(a);
	grupo.push_back(b);
	grupo.push_back(c);
	grupo.push_back(d);
	grupo.push_back(e);
	grupo.push_back(f);
	grupo.push_back(g);

	//Ordenando por um criterio em ordem decrescente
	grupo.sort_elements("valor",-1);

	result = grupo.get_elements();

	for(vector<Element>::iterator it = result.begin(); it!= result.end(); it++)
	{
		cout << it->to_string() << endl;
	}

	return 0;
}
