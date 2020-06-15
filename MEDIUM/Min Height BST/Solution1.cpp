/****************************************************
TC: O(nlogn) : every insertion takes logn time
SC: O(n) : to store n elements
Method: Recursive method. The middle element will be the root node - call this recursively.
*****************************************************/

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

  void insert(int value) {
    if (value < this->value) {
      if (left == NULL) {
        left = new BST(value);
      } else {
        left->insert(value);
      }
    } else {
      if (right == NULL) {
        right = new BST(value);
      } else {
        right->insert(value);
      }
    }
  }
};

BST *minHeightBstHelper(vector<int> array, BST *root, int start, int end) {
	if(end < start)
		return root;
	int mid = (start + end)/2;
	if(root == NULL)
		root = new BST(array[mid]);
	else root->insert(array[mid]);
	minHeightBstHelper(array, root, start, mid - 1);
	minHeightBstHelper(array, root, mid + 1, end);
	return root;
}
 
BST *minHeightBst(vector<int> array) {
  return minHeightBstHelper(array, NULL, 0, array.size() - 1);
}
