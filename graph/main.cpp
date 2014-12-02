#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "Graph.hpp"
#include "Search.hpp"

using namespace std;

int main(int argc, char** argv)
{
	int id = -1;

	if(argc > 1)
		id = atoi(argv[1]);
	else
		cout << "... Accessing SHIELD's database ..." << endl;

	Graph *graph = new Graph(true);
	Search searcher = Search();
	int total_chars;
	int total_events;

	ifstream infile;
	infile.open("all.txt");

	//Characters
	infile >> total_chars;

	for(int i = 0; i < total_chars; i++)
	{
		int char_id;

		infile >> char_id;

		string char_name;
		getline(infile, char_name);
		getline(infile, char_name);

		graph->insert_node(char_id, char_name);
		//TODO Save Char name and ID
	}

	//Events
	infile >> total_events;

	int chars_by_event;
	for(int i = 0; i < total_events; i++)
	{
		int event_id;

		infile >> event_id;

		string event_name;
		getline(infile, event_name);
		getline(infile, event_name);

		//TODO Save Event name and ID

		infile >> chars_by_event;

		int char_id;
		vector<int> chars_list;

		for(int i = 0; i < chars_by_event; i++)
		{
			infile >> char_id;
			chars_list.push_back(char_id);
		}

		for(unsigned int i = 0; i < (chars_list.size() - 1); i++)
			for(unsigned int j = i+1; j < chars_list.size(); j++)
				graph->increase_edge(chars_list[i], chars_list[j]);
	}

	infile.close();

	if(id == -1)
	{
		cout << "Type your character ID: ";
		cin >> id;

		Node *found = graph->get_node(id);

		if(found == 0)
		{
			cout << "Character not found!" << endl;
			return -1;
		}

		cout << endl << "Your charcater record: " << endl;
		cout << "\t" << "Identification: " << found->get_value() << endl;
		cout << "\t" << "Name: " << found->get_name() << endl;
		cout << "\t" << "Relevance position in the Universe: " << graph->relevance(id) << endl;

		vector<Neighbor> neighbors = found->get_neighbors();
		if(neighbors.size() == 0)
			cout << "\t" << "No relations!" << endl;
		else
		{
			cout << "\t" << "Relatated to (" << neighbors.size() << ") : " << endl;
			for(int i = 0; i < (int)neighbors.size(); i++)
				cout << "\t\t" << neighbors[i].neighbor->get_value() << " - " << neighbors[i].neighbor->get_name() << "(" << neighbors[i].weight << ")" << endl;

			cout << "\t" << "Closer relations (" << found->high_weight() << " events): " << endl;
			vector<Node*> closers = found->closers();
			for(int i = 0; i < (int)closers.size(); i++)
				cout << "\t\t" << closers[i]->get_value() << " - " << closers[i]->get_name() << endl;
		}
	}
	else
		cout << graph->get_subgraph(id)->to_dot();

	delete graph;
	return 0;
}
