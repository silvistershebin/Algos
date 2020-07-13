/****************************************************
TC: O(2^N * N)
SC: O(2^N * N)
Method: Recursive 
*****************************************************/

#include <vector>
using namespace std;

vector<vector<int>> powerSetHelper(vector<int> array, int idx) {
	if(idx < 0)
		return vector<vector<int>> {{}};
	int element = array[idx];
	vector<vector<int>> set = powerSetHelper(array, idx-1);
	int len = set.size();
	for(int i = 0; i < len; i++) {
		vector<int> newSet = set[i];
		newSet.push_back(element);
		set.push_back(newSet);
	}
	return set;
}

vector<vector<int>> powerset(vector<int> array) {
  return powerSetHelper(array, array.size() - 1);
}

