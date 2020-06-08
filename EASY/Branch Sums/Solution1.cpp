/****************************************************
TC: O(n)
SC: O(n)
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

void branchSumsHelper(BST *root, int sum, vector<int> &res) {
	if(root == NULL)
		return;
	sum += root->value;
	if (root->left == NULL && root->right == NULL) {
	  res.push_back(sum);
	}
	branchSumsHelper(root->left, sum, res);
	branchSumsHelper(root->right, sum, res);
}

vector<int> branchSums(BST *root) {
	vector<int> res;
	branchSumsHelper(root, 0, res);
	return res;
}

/*
void inorder(BST *node) {
	if(node->left != NULL)
		inorder(node->left);
	cout << node->value << endl;
	if(node->right != NULL)
		inorder(node->right);
}
*/
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
	  //root->inorder(root);
	  vector<int> res = root->branchSums(root);
	  for(int i : res) {
		cout << i << "\t";
	  }
}
