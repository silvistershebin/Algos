/****************************************************
Time Efficient; More Space
TC: O(n)
Method: HashMap to store the values
*****************************************************/

#include <bits/stdc++.h>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
	map<int,int> m;
	for(int i : array) {
		auto it = m.find(targetSum - i);
		if(it != m.end())
			return {i, targetSum - i};
		m[i] = i;
	}
	return {};
}

int main() {
	vector<int> num = {3,5,-4,8,11,1,-1,6};
	int targetSum = 10;
	vector<int> res = twoNumberSum(num, targetSum);
	if (res.size() == 2)
		cout << res[0] << " " << res[1];}