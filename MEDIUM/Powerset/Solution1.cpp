/****************************************************
TC: O(2^N * N)
SC: O(2^N * N)
Method: Simple Iterative Solution
*****************************************************/

#include <vector>
using namespace std;

vector<vector<int>> powerset(vector<int> array) {
  vector<vector<int>> pset;
	pset.push_back({});
	for(int num : array) {
		vector<vector<int>> temp = pset;
		for(int i = 0; i < pset.size(); i++) {
			temp[i].push_back(num);
		}
		for(int i = 0; i < temp.size(); i++) {
			pset.push_back(temp[i]);
		}
 	}
  return pset;
}
