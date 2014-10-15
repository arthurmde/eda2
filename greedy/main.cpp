#include <iostream>
#include <vector>
#include <cstdlib>
#include "Element.hpp"
#include "Group.hpp"

#define ELEMENT_SIZE 3000

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
					((a >= x) && (a < y )) ||
					((b > x) && (b <= y )) ||
					((a <= x) && (b >= y )))
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

void imprime(vector<Element> result)
{
	for(vector<Element>::iterator it=result.begin(); it!= result.end(); it++)
	{
		cout << it->to_string() << endl;
	}
	cout << "--------" << endl << endl;
}


int main(void)
{
	vector<Element> result;

	vector<Element> elements;
	vector<Element> backup;


	// grupo.sort_elements("fim",1);
	// backup = grupo.get_elements();
	// cout << "Vetor inicial:" << endl << endl;
	// imprime(backup);

	int iniciomaior,iniciomenor,fimmaior,fimmenor,duracaomaior,duracaomenor;

	//Ordenando por um criterio em ordem decrescente

	bool has_solution = false;

	vector<int> total;

	for(int i = 0; i < 6; i++)
		total.push_back(0);

	int count = 0;

	while(!has_solution)
	{
		cout << "============Trying to find a solution==============" << endl;
		srand (time(NULL));

		if(count == 1)
		{
			has_solution = true;
		}

		Group grupo =  Group();
		
		for(int i=0;i<ELEMENT_SIZE;i++)
		{
			int inicio,fim,duracao;

			inicio = rand()%103;
			duracao = rand()%20+1;
			fim = inicio+duracao;

			Element element = Element();
			element.set_criterion("inicio", inicio);
			element.set_criterion("duracao", duracao);
			element.set_criterion("fim", fim);

			grupo.push_back(element);
		}

		if(total[0] != -1)
		{
			grupo.sort_elements("inicio",1);
			result = solucao(grupo.get_elements());
			iniciomenor = result.size();
			//cout << endl << "inicio menor:" << endl << endl;
			//imprime(result);
			total[0] = result.size();
			cout << "Inicio menor: " << iniciomenor << endl;
		}
		if(total[1] != -1)
		{
			grupo.sort_elements("inicio",-1);
			result = solucao(grupo.get_elements());
			iniciomaior = result.size();
			//cout << endl << "inicio maior:" << endl << endl;
			//imprime(result);
			total[1] = result.size();
			cout << "Inicio maior: " << iniciomaior << endl;
		}
		if(total[2] != -1)
		{
			grupo.sort_elements("fim",1);
			result = solucao(grupo.get_elements());
			fimmenor = result.size();
			//cout << endl << "Fim menor:" << endl << endl;
			//imprime(result);
			total[2] = result.size();
			cout << "Fim menor: " << fimmenor << endl;
		}
		if(total[3] != -1)
		{
			grupo.sort_elements("fim",-1);
			result = solucao(grupo.get_elements());
			fimmaior = result.size();
			//cout << endl << "Fim maior:" << endl << endl;
			//imprime(result);
			total[3] = result.size();
			cout << "Fim maior: " << fimmaior << endl;
		}
		if(total[4] != -1)
		{
			grupo.sort_elements("duracao",1);
			result = solucao(grupo.get_elements());
			duracaomenor = result.size();
			//cout << endl << "duracao menor:" << endl << endl;
			//imprime(result);
			total[4] = result.size();
			cout << "Duracao menor: " << duracaomenor << endl;
		}
		if(total[5] != -1)
		{
			grupo.sort_elements("duracao",-1);
			result = solucao(grupo.get_elements());
			duracaomaior = result.size();
			//cout << endl << "duracao maior:" << endl << endl;
			//imprime(result);
			total[5] = result.size();
			cout << "Duracao maior: " << duracaomaior << endl;
		}

		int biggest = 0;
		for(int i = 0; i < 6; i++)
		{
			if(total[i] != -1 && total[i] > biggest)
			{
				biggest = total[i];
			}
		}

		count = 0;
		for(int i = 0; i < 6; i++)
		{
			if(total[i] != biggest)
			{
				total[i] = -1;
			}
			else
			{
				count++;
			}
		}
	}

	cout << "The correct criterion is the last one listed above" << endl;

	return 0;
}
