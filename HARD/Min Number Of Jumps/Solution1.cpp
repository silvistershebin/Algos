/****************************************************
TC: O(N^2)
SC: O(N)
Method: Simple DP approach
*****************************************************/

#include <vector>
using namespace std;

int minNumberOfJumps(vector<int> array) {
  vector<int> jumps(array.size(), INT_MAX);
	jumps[0] = 0;
	for(int i = 1; i < array.size(); i++) {
		for(int j = i-1; j >= 0; j--) {
			if(array[j] + j >= i) {
				jumps[i] = min(jumps[i], jumps[j] + 1);
			}
		}
	}
  return jumps[jumps.size() - 1];
}
