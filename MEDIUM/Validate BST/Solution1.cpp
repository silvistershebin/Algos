/****************************************************
TC: O(n)
SC: O(d)
Method: Recursion
*****************************************************/

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};

bool validateBstHelper(BST *tree, int min, int max) {
	if(tree == NULL)
		return true;
	if(tree->value < min || tree->value >= max)
		return false;
	return validateBstHelper(tree->left, min, tree->value) && validateBstHelper(tree->right, tree->value, max);
}

// O(n) time | O(d) space
bool validateBst(BST *tree) {
  return validateBstHelper(tree, INT_MIN, INT_MAX);
}
