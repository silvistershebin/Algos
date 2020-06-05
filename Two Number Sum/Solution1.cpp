/****************************************************
Least Optimal
TC: O(n^2)
Method: Double for loop to find the two numbers
*****************************************************/

#include <bits/stdc++.h>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
	for(int i = 0; i < array.size(); i++) {
		for(int j = i + 1; j < array.size(); j++) {
			if((array[i] + array[j]) == targetSum)
				return {array[i],array[j]};
		}
	}
	return {};
}

int main() {
	vector<int> num = {3,5,-4,8,11,1,-1,6};
	int targetSum = 10;
	vector<int> res = twoNumberSum(num, targetSum);
	if (res.size() == 2)
		cout << res[0] << " " << res[1];}