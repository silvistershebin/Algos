/****************************************************
TC: O(n)
SC: O(n)
Method: DP (Store the maxSum in array)
*****************************************************/

#include <vector>
using namespace std;

int maxSubsetSumNoAdjacent(vector<int> array) {
  if(array.size() == 0)
		return 0;
	if(array.size() == 1)
		return array[0];
	vector<int> maxSum(array.size());
	maxSum[0] = array[0];
	maxSum[1] = max(array[0], array[1]);
	for(int i = 2; i < array.size(); i++) {
		maxSum[i] = max(maxSum[i - 1], maxSum[i - 2] + array[i]);
	}
  return maxSum[maxSum.size() - 1];
}
