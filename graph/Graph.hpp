#ifndef GRAPH_HPP
#define GRAPH_HPP
#include "Node.hpp"
#include <string>
#include <vector>

using namespace std;

class Graph
{
	public:
		Graph();
		~Graph();
		void insert_node(Node*);
		int insert_link(int,int);
		Node* get_node(int);
		string to_dot(void);
	private:
		void insert_link(Node*,Node*);
		vector<Node*> nodes;
};

#endif
