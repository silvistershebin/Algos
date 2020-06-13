/****************************************************
TC: O(n^2)
SC: O(n)
Method: Fix the first number. Use 2 pointer method(L, R) and check if it matches the targetSum
*****************************************************/

#include <vector>
using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
	vector<vector<int>> res;
	sort(array.begin(), array.end());
  for(int i = 0; i < array.size(); i++) {
		int l = i + 1;
		int r = array.size() - 1;
		while(l < r) {
			if((array[i] + array[l] + array[r]) == targetSum) {
				res.push_back({array[i], array[l], array[r]});
				r--;
				l++;
			} else if((array[i] + array[l] + array[r]) < targetSum) {
				l++;				
			} else
				r--;
		}
	}
  return res;
}
