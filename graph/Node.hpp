#ifndef NODE_HPP
#define NODE_HPP
#include <vector>
#include <string>

using namespace std;

class Node;

typedef struct _Neighbor
{
	int weight;
	Node* neighbor;
} Neighbor;

class Node
{
	public:
		Node();
		Node(int);
		Node(int, string);
		~Node();
		void insert_neighbor(Node*);
		void insert_neighbor(Node*,int);
		void increase_neighbor(Node*);
		void remove_neighbor(Node*);
		vector<Neighbor> get_neighbors(void);
		int get_value(void);
		string get_name(void);
		int degree(void);
		bool has_neighbor(Node*);
	private:
		//vector<Node*> neighbors;
		vector<Neighbor> neighbors;
		int value;
		string name;
};

#endif
