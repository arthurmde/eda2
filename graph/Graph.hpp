#ifndef GRAPH_HPP
#define GRAPH_HPP
#include "Node.hpp"
#include <string>
#include <vector>

using namespace std;

class Graph
{
	public:
		Graph(bool=false);
		~Graph();
		void insert_node(int);
		int insert_edge(int, int);
		void remove_edge(int, int);
		void remove_node(int);
		Node* get_node(int);
		string to_dot(void);
		int size(void);
		bool empty(void);

	private:
		void insert_node(Node*);
		void insert_edge(Node*,Node*);
		void remove_edge(Node*,Node*);
		vector<Node*> nodes;
		bool is_bidirectional;
};

#endif
