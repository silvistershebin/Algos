/****************************************************
TC: O(n*d) : (n : target amount; d : number of denominations)
SC: O(n)
Method: DP
*****************************************************/

#include <vector>
using namespace std;

int numberOfWaysToMakeChange(int n, vector<int> denoms) {
  vector<int> count(n + 1, 0);
	count[0] = 1;
	for(int i : denoms) {
		for(int j = i; j <= n; j++) {
			count[j] += count[j - i];
		}
	}
  return count[n];
}
