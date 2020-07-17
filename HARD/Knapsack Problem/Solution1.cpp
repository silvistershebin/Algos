/****************************************************
TC: O(N*C)
SC: O(N*C)
Method: DP
*****************************************************/

#include <vector>
using namespace std;

vector<vector<int>> getItems(vector<vector<int>>, vector<vector<int>>, int);

vector<vector<int>> knapsackProblem(vector<vector<int>> items, int capacity) {
  vector<vector<int>> E(items.size() + 1, vector<int>(capacity + 1, 0));
	for(int r = 1; r <= items.size(); r++) {
		int value = items[r-1][0], weight = items[r-1][1];
		for(int c = 0; c <= capacity; c++) {
			if(weight > c) {
				E[r][c] = E[r - 1][c];
			} else {
				E[r][c] = max(E[r-1][c], value + E[r-1][c-weight]);
			}
		}
	}
  return getItems(E, items, E[items.size()][capacity]);
}

vector<vector<int>> getItems(vector<vector<int>> E, vector<vector<int>> items, int weight) {
	vector<vector<int>> solution = {{}, {}};
	int r = E.size() - 1;
	int c = E[0].size() - 1;
	while(r > 0 && c > 0) {
		if(E[r][c] == E[r-1][c]) {
			r--;
		} else {
			solution[1].insert(solution[1].begin(), r-1);
			c -= items[r-1][1];
			r--;
		}
	}
	solution[0].push_back(weight);
	return solution;
}
