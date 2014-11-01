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
		void remove_neighbor(Node*);
		vector<Node*> get_neighbors(void);
		int get_value(void);
		int degree(void);
		bool has_neighbor(Node*);
	private:
		vector<Node*> neighbors;
		int value;
};

#endif
