/****************************************************
TC: O(N*K)
SC: O(N*K) (Can be reduced to n space)
Method: DP
*****************************************************/

#include <vector>
using namespace std;

int maxProfitWithKTransactions(vector<int> prices, int k) {
	if(prices.size() == 0)
		return 0;
  vector<vector<int>> profit(k+1, vector<int>(prices.size(), 0));
	for(int r = 1; r < k + 1; r++) {
		int m = INT_MIN;
		for(int c = 1; c < prices.size(); c++) {
			m = max(m, profit[r - 1][c - 1] - prices[c - 1]);
			profit[r][c] = max(profit[r][c-1], prices[c] + m);
		}
	}
  return profit[k][prices.size() - 1];
}
