/****************************************************
TC: O(n)
SC: O(n)
Method: Iterative Solution; Swap and add to queue
*****************************************************/

#include <vector>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value);
  void insert(vector<int> values, int i = 0);
  void invertedInsert(vector<int> values, int i = 0);
};

void invertBinaryTree(BinaryTree *tree) {
  queue<BinaryTree*> q;
	q.push(tree);
	while(!q.empty()) {
		BinaryTree *node = q.front();
		q.pop();
		swap(node->left, node->right);
		if(node->left != NULL)
			q.push(node->left);
		if(node->right != NULL)
			q.push(node->right);
	}
}
