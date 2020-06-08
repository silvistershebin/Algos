#include <bits/stdc++.h>
#include <cassert>
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

bool contains(int val) {
	if(val < value) {
		if (left == NULL)
			return false;
		else
			return left->contains(val);
	} else if (val > value) {
		if (right == NULL)
			return false;
		else
			return right->contains(val);
	} else return true;
}

  BST &remove(int val, BST* parent = NULL) {
    if (val < value) {			//Traverse till we find the value
		if (left != NULL) 
			left->remove(val, this);
	} else if (val > value) {
		if (right != NULL) 
			right->remove(val, this);
	} else {					//Value found, now delete
		if(right == NULL && left == NULL) {		//leaf node condition
			if (parent != NULL) {
				if (parent->left == this)
					parent->left = NULL;
				else parent->right = NULL;
			}
		} else if (right == NULL && left != NULL) {	// node with only left branch condition
			if(parent->left == this)
				parent->left = left;
			else parent->right = left;
		} else if (right != NULL && left == NULL) {		//node with only right branch 
			if(parent->left == this)
				parent->left = right;
			else parent->right = right;
		} else if(right != NULL && left != NULL) {		//non leaf node
			BST *node = this;
			node = node->right;
			BST *node_parent = this;
			while(node->left != NULL) {
				node_parent = node;
				node = node->left;
			}

			if(parent != NULL) {
				node_parent->left = node->right;
				node->right = this->right;
				if(parent->right == this) {
					parent->right = node;
					node->left = this->left;
				} else {
					parent->left = node;
					node->left = this->left;
				}
			} else {
				this->value = node->value;
				node_parent->left = node->right;
			}
		}
	}
    return *this;
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
      
      root->remove(10);
	  assert(root->right->value == 15);
}