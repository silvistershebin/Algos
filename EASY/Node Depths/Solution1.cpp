/****************************************************
TC: O(n)
SC: O(log(n))
Method: Recursive traversal by passing sum; Push sum if leaf node
*****************************************************/

#include<bits/stdc++.h>
using namespace std;

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val) {
    value = val;
    left = NULL;
    right = NULL;
  }

  BST &insert(int val) {
    if(val > value) {
			if(right == NULL) {
				BST *node = new BST(val);
				right = node;
			} else {
				right->insert(val);
			}
		} else {
			if(left == NULL) {
				BST *node = new BST(val);
				left = node;
			} else {
				left->insert(val);
			}
		}
    return *this;
  }

void nodeDepthsHelper(BST *root, int depth, int *sum) {
	if (root == NULL)
		return;
	depth += 1;
	*sum += depth;
	nodeDepthsHelper(root->left, depth, sum);
	nodeDepthsHelper(root->right, depth, sum);
}

int nodeDepths(BST *root) {
	int sum;
	sum = 0;
	nodeDepthsHelper(root, -1, &sum);
	return sum;
}
  
};

int main(){
      BST* root = new BST(10);
      root->left = new BST(5);
      root->left->left = new BST(2);
      root->left->left->left = new BST(1);
      root->left->right = new BST(5);
      root->right = new BST(15);
      root->right->left = new BST(13);
      root->right->left->right = new BST(14);
      root->right->right = new BST(22);
      
      root->insert(12);
      assert(root->right->left->left->value == 12);
	  
	  cout << "Sum of Depth of nodes: " << root->nodeDepths(root);
}
