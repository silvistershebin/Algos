/****************************************************
TC: O(n*d) : (n : target amount; d : number of denominations)
SC: O(n)
Method: DP
*****************************************************/

#include <vector>
using namespace std;

int minNumberOfCoinsForChange(int n, vector<int> denoms) {
  vector<int> count(n+1, INT_MAX);
	count[0] = 0;
	for(int denom: denoms) {
		for(int i = denom; i < n+1; i++) {
			if(count[i - denom] != INT_MAX)
				count[i] = min(count[i], 1 + count[i - denom]);
		}
	}
	if(count[n] != INT_MAX)
		return count[n];
	else
		return -1;
}
