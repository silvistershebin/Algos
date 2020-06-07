/****************************************************
TC: Average: O(log(n)); Worst: O(n)
SC: Average: O(log(n)); Worst: O(n)
Method: 
*****************************************************/

#include<bits/stdc++.h>

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};

int findClosestValueInBstHelper(BST *tree, int target, int closest) {
	int diff = abs(tree->value - target);
	if(diff < abs(target - closest))
		closest = tree->value;
	if (diff == 0)
		return target;
	if(target < tree->value) {
		if (tree->left != NULL)
			return findClosestValueInBstHelper(tree->left, target, closest);
		else
			return closest;
		}
	else {
		if(tree->right != NULL)
			return findClosestValueInBstHelper(tree->right, target, closest);
		else
			return closest;
	}
}

int findClosestValueInBst(BST *tree, int target) {
  return findClosestValueInBstHelper(tree, target, tree->value);
}
