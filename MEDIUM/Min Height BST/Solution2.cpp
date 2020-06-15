using namespace std;

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int value) {
    this->value = value;
    left = NULL;
    right = NULL;
  }

};

BST *minHeightBstHelper(vector<int> array, BST *root, int start, int end) {
	if(end < start)
		return root;
	int mid = (start + end)/2;
	BST *node = new BST(array[mid]);
	if(root == NULL)
		root = node;
	else {
		if(node->value >= root->value) {
			root->right = node;
			root = root->right;
		}
		else {
 			root->left = node;
			root = root->left;
		}
	}
	minHeightBstHelper(array, root, start, mid - 1);
	minHeightBstHelper(array, root, mid + 1, end);
	return root;
}
 
BST *minHeightBst(vector<int> array) {
  return minHeightBstHelper(array, NULL, 0, array.size() - 1);
}
