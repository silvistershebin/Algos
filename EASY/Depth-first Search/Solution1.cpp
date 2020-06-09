/****************************************************
TC: O(v+e)
SC: O(v)
DFS on graph with multiple children
Method: Add current node Recursive call to the children nodes
*****************************************************/

#include <vector>
using namespace std;

class Node {
public:
  string name;
  vector<Node *> children;

  Node(string str) { name = str; }

  vector<string> depthFirstSearch(vector<string> *array) {
    array->push_back(this->name);
		for(auto i : this->children) {
			i->depthFirstSearch(array);
		}
    return *array;
  }

  Node *addChild(string name) {
    Node *child = new Node(name);
    children.push_back(child);
    return this;
  }
};
