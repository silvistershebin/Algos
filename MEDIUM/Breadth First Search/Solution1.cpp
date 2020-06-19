/****************************************************
TC: O(v + e)
SC: O(v)
Method: Use queue
*****************************************************/

#include <vector>
#include <queue>
using namespace std;

class Node {
public:
  string name;
  vector<Node *> children;

  Node(string str) { name = str; }

  vector<string> breadthFirstSearch(vector<string> *array) {
    queue<Node *> q;
		q.push(this);
		while(!q.empty()) {
			Node *n = q.front();
			array->push_back(n->name);
			q.pop();
			for(Node *node : n->children) {
				if(node != NULL)
					q.push(node);
			}
		}
    return *array;
  }

  Node *addChild(string name) {
    Node *child = new Node(name);
    children.push_back(child);
    return this;
  }
};
