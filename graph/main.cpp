#include <iostream>
#include <fstream>
#include <string>

#include "Graph.hpp"
#include "Search.hpp"

using namespace std;

int main(void)
{
	Graph *graph = new Graph(true);
	Search searcher = Search();
	int total_chars;
	int total_events;

	ifstream infile; 
	infile.open("all.txt"); 
	
	cout << "Reading from the file" << endl; 
	
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
		char broke_line;

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

	//cout << graph->to_dot();
	
	int id;

	cout << "Type your character ID: ";
	cin >> id;

	Node *found = graph->get_node(id);
	
	if(found == 0)
	{
		cout << "Character not found!" << endl;
		return -1;
	}

	cout << endl << "Your charcater record: " << endl;
	cout << "\t" << "Identification: " << found->get_value();
	cout << "\t" << "Name: " << found->get_name();

	vector<Neighbor> neighbors = found->get_neighbors();
	if(neighbors.size() == 0)
		cout << "\t" << "No relations!" << endl;
	else
	{
		cout << "\t" << "Relatated to (" << neighbors.size() << ") : " << endl;
		for(int i = 0; i < (int)neighbors.size(); i++)
			cout << "\t\t" << neighbors[i].neighbor->get_value() << " - " << neighbors[i].neighbor->get_name() << endl;
    	
  //   	cout << "\t" << "Closer relations (" << found->high_weight() << " events): " << endl;
  //   	vector<Node*> closers = found->closers();
		// for(int i = 0; i < (int)closers.size(); i++)
		// 	cout << "\t\t" << closers[i].get_value << " - " << closers[i].get_name << endl;
    }

	//Nodes related to Logan 1009156
	cout << graph->get_subgraph(id)->to_dot();

	delete graph;
	return 0;
}
