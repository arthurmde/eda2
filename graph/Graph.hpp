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
		void insert_node(int, string);
		int insert_edge(int, int);
		int insert_edge(int, int, int);
		int increase_edge(int, int);
		void remove_edge(int, int);
		void remove_node(int);
		Node* get_node(int);
		vector<Node*> get_nodes();
		bool is_bidirectional();

		//TODO
		bool is_connected();
		bool is_strongly_connected();
		bool is_cyclical();
		bool is_tree();
		int distance(int,int);
		Graph *get_inverse(void);
		Graph *get_subgraph(int);


		string to_dot(void);
		int size(void);
		bool empty(void);

	private:
		void insert_node(Node*);
		void insert_edge(Node*,Node*);
		void insert_edge(Node*,Node*,int);
		void increase_edge(Node*,Node*);
		void remove_edge(Node*,Node*);

		//TODO

		vector<Node*> nodes;
		bool bidirectional;
};

#endif
