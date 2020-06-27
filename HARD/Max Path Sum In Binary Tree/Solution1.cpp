/****************************************************
TC: O(N) : (N: number of elements)
SC: O(log(n))
Method: Recursion - return the branch sum and the max tree sum
*****************************************************/


#include <vector>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;
	int mps = 0;
  BinaryTree(int value);
  void insert(vector<int> values, int i = 0);
};

vector<int> maxPathSumHelper(BinaryTree *tree) {
	if(tree == NULL)
		return {0, INT_MIN};
	vector<int> l = maxPathSumHelper(tree->left);
	vector<int> r = maxPathSumHelper(tree->right);
	int v = tree->value;
	int lsb = l[0], ls = l[1];
	int rsb = r[0], rs = r[1];
	int mcsb = max(lsb, rsb);
	int msb = max(v, v + mcsb);
	int mst = max(msb, lsb + v + rsb);
	int rmps = max(mst, max(ls, rs));
	return {msb, rmps};
}

int maxPathSum(BinaryTree tree) {
	vector<int> v = maxPathSumHelper(&tree);
	return v[1];
}
