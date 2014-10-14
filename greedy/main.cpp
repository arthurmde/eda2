#include <iostream>
#include <vector>
#include <cstdlib>
#include "Element.hpp"
#include "Group.hpp"

#define ELEMENT_SIZE 100

using namespace std;


vector<Element> solucao(vector<Element> vetor)
{
	vector<Element> solution;
	for(vector<Element>::iterator it=vetor.begin(); it!= vetor.end(); it++)
	{
		bool is_solution = true;

		for(vector<Element>::iterator it_sol=solution.begin(); it_sol!= solution.end(); it_sol++)
		{
			int a,b;
			int x,y;
			a = (it->get_criterion("inicio"));
			b = (it->get_criterion("fim"));
			x = (it_sol->get_criterion("inicio"));
			y = (it_sol->get_criterion("fim"));

			if(
					((a > x) && (a < y )) ||
					((b > x) && (b < y )) ||
					((a < x) && (b > y )))
			{
				is_solution=false;
				break;
			}
		}
		if(is_solution)
		{
			solution.push_back(*it);
		}

	}
	return solution;
}

int main(void)
{
	vector<Element> result;
	srand (time(NULL));

	vector<Element> elements;
	Group grupo =  Group();
	for(int i=0;i<ELEMENT_SIZE;i++)
	{
		int inicio,fim,duracao;

		inicio = rand()%103;
		duracao = rand()%73+1;
		fim = inicio+duracao;

		Element element = Element();
		element.set_criterion("inicio", inicio);
		element.set_criterion("duracao", duracao);
		element.set_criterion("fim", fim);

		grupo.push_back(element);
	}

	int iniciomaior,iniciomenor,fimmaior,fimmenor,duracaomaior,duracaomenor;

	//Ordenando por um criterio em ordem decrescente
	
	grupo.sort_elements("inicio",1);
	result = solucao(grupo.get_elements());
	iniciomenor = result.size();

	grupo.sort_elements("inicio",-1);
	result = solucao(grupo.get_elements());
	iniciomaior = result.size();

	grupo.sort_elements("fim",1);
	result = solucao(grupo.get_elements());
	fimmenor = result.size();

	grupo.sort_elements("fim",-1);
	result = solucao(grupo.get_elements());
	fimmaior = result.size();

	grupo.sort_elements("duracao",1);
	result = solucao(grupo.get_elements());
	duracaomenor = result.size();

	grupo.sort_elements("duracao",-1);
	result = solucao(grupo.get_elements());
	duracaomaior = result.size();

	
	cout << "Inicio menor: " << iniciomenor << endl;
	cout << "Inicio maior: " << iniciomaior << endl;
	cout << "Fim menor: " << fimmenor << endl;
	cout << "Fim maior: " << fimmaior << endl;
	cout << "Duracao menor: " << duracaomenor << endl;
	cout << "Duracao maior: " << duracaomaior << endl;




	for(vector<Element>::iterator it = result.begin(); it!= result.end(); it++)
	{
		//cout << it->to_string() << endl;
	}

	return 0;
}
