/****************************************************
Similar to Solution1; Space Efficient
TC: O(n)
SC: O(1)
Method: DP (no extra array usef)
*****************************************************/

#include <vector>
using namespace std;

int maxSubsetSumNoAdjacent(vector<int> array) {
  if(array.size() == 0)
		return 0;
	if(array.size() == 1)
		return array[0];
	int first = array[0];
	int second = max(array[0], array[1]);
	for(int i = 2; i < array.size(); i++) {
		int curr = max(second, first + array[i]);
		first = second;
		second = curr;
	}
  return second;
}
