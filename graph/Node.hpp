#ifndef NODE_HPP
#define NODE_HPP
#include <vector>

using namespace std;

class Node
{
	public:
		Node();
		Node(int);
		~Node();
		void insert_neighbor(Node*);
		vector<Node*> get_neighbors(void);
		int get_value(void);
	private:
		vector<Node*> neighbor;
		int value;
};

#endif
