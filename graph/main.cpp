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
	char line[502];
	int total_events;

	//Characters
	cin >> total_chars;

	for(int i=0; i<total_chars; i++)
	{
		char broke_line;
		int char_id;

		cin >> char_id;

		scanf("%c",&broke_line);
		cin.getline(line,500);

		string char_name(line);

		graph->insert_node(char_id);
		//TODO Save Char name and ID

	}

	//Events
	cin >> total_events;

	int chars_by_event;
	for(int i=0; i<total_events; i++)
	{
		int event_id;
		cin >> event_id;
		char broke_line;
		scanf("%c",&broke_line);
		cin.getline(line,500);
		string event_name(line);

		//TODO Save Event name and ID

		cin >> chars_by_event;
		int char_id;
		vector<int> chars_list;
		for(int i=0; i<chars_by_event; i++)
		{
			cin >> char_id;
			chars_list.push_back(char_id);
		}

		for(unsigned int i=0; i<(chars_list.size()-1); i++)
			for(unsigned int j=i+1; j<chars_list.size(); j++)
				graph->insert_edge(chars_list[i],chars_list[j]);
	}

	//cout << graph->to_dot();
	
	//Nodes related to Logan
	cout << graph->get_subgraph(1009156)->to_dot();

	delete graph;
	return 0;
}
