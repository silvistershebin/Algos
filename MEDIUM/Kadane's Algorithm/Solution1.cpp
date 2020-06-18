/****************************************************
TC: O(n)
SC: O(n); can be reduced to O(1)
Method: DP
*****************************************************/

#include <vector>
using namespace std;

int kadanesAlgorithm(vector<int> array) {
  vector<int> sum(array.size(), INT_MIN);
	sum[0] = array[0];
	for(int i = 1; i < sum.size(); i++) {
		sum[i] = (array[i] + sum[i -1]) > array[i] ? (array[i] + sum[i -1]) : array[i];
	}
  return *max_element(sum.begin(), sum.end());
}
