#ifndef SEARCH_HPP
#define SEARCH_HPP
#include "Graph.hpp"
#include "Node.hpp"
#include <queue>
#include <stack>
#include <set>

using namespace std;

class Search
{
	public:
		Search();
		~Search();
		Graph* bfs(Graph *graph, int root);
		Graph* bfs(Graph *graph, Node *root);
		void dfs(Graph *graph, Node *root);
		void dijkstra(Graph *graph, Node *root, Node *target);

	private:
		queue<Node*> q;
		stack<Node*> s;
		set<Node*> not_visited;

		void visit(Node* node);
		bool is_visited(Node* node);
		void create_visitor(vector<Node*> nodes);
};

#endif
