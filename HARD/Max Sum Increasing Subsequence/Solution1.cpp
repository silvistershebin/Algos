/****************************************************
TC: O(N^2)
SC: O(N)
Method: DP approach
*****************************************************/

#include <vector>
using namespace std;

vector<vector<int>> maxSumIncreasingSubsequence(vector<int> array) {
  vector<int> sums = array, sequences(array.size(), -1);
	int maxSum = INT_MIN, maxIndex = 0;
	for(int i = 0; i < array.size(); i++) {
		int currNum = array[i];
		for(int j = 0; j < i; j++) {
			if(array[j] < currNum) {
				int pre = sums[i];
				sums[i] = max(sums[i], array[i] + sums[j]);
				if(pre != sums[i]) {
					sequences[i] = j;
				}
			}
		}
		if(sums[i] > maxSum) {
			maxSum = sums[i];
			maxIndex = i;
		}
	}
	vector<int> res;
	int ptr = maxIndex;
	do{
		res.push_back(array[ptr]);
		ptr = sequences[ptr];
	} while (ptr != -1);
	reverse(res.begin(), res.end());
  return {
      {sums[maxIndex]}, // Sum of sequence.
      res,  // Elements of the sequence.
  };
}
