/****************************************************
TC: O(2^N * N)
SC: O(2^N * N)
Method: Simple Iterative Solution
*****************************************************/

#include <vector>
using namespace std;

vector<vector<int>> powerset(vector<int> array) {
  vector<vector<int>> pset = {{}};
	for(int num : array) {
		int len = pset.size();
		for(int i = 0; i < len; i++) {
			vector<int> temp = pset[i];
			temp.push_back(num);
			pset.push_back(temp);
		}
 	}
  return pset;
}
