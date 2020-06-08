/****************************************************
TC: O(n)
SC: O(log(n))
Method: Iterative, by tracking nodes using STL stack
*****************************************************/

#include<stack>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;
	int depth;
	
  BinaryTree(int value) {
    this->value = value;
    left = NULL;
    right = NULL;
  }
};

int nodeDepths(BinaryTree *root) {
	stack<BinaryTree*> s;
	s.push(root);
	BinaryTree *node = root;
	root->depth = 0;
	int sum = 0;
	int depth = 0;
	
  while(!s.empty()) {
		node = s.top();
		cout << node->value << endl;
		s.pop();
		if(node->left != NULL) {
			node->left->depth = node->depth+1;
			s.push(node->left);
		}
		if(node->right != NULL) {
			node->right->depth = node->depth+1;
			s.push(node->right);
		}
		sum += node->depth;;
	}
	return sum;
}