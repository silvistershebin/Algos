/****************************************************
Refactoring Solution2; Cleaner Code;
TC: O(n) : every insertion takes constant time
SC: O(n) : to store n elements
Method: Recursive method. The middle element will be the root node - call this recursively (same as solution2).
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
};

BST *minHeightBstHelper(vector<int> array, int start, int end) {
	if(end < start)
		return NULL;
	int mid = (start + end)/2;
	BST *node = new BST(array[mid]);
	node->left = minHeightBstHelper(array, start, mid - 1);
	node->right = minHeightBstHelper(array, mid + 1, end);
	return node;
}
 
BST *minHeightBst(vector<int> array) {
  return minHeightBstHelper(array, 0, array.size() - 1);
}
