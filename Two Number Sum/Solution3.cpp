/****************************************************
Space Efficient
TC: O(nlogn + n)
Method: Sort the array and use 2 pointers starting from the 2 ends of the array
*****************************************************/

#include <bits/stdc++.h>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
	sort(array.begin(), array.end());
	auto first = array.begin();
	auto last = array.end();
	for(int i = 0; i < array.size(); i++) {
		int sum = *first + *last;
		if(sum == targetSum)
			return {*first, *last};
		else if(sum > targetSum)
			last --;
		else
			first++;
	}
	return {};
}

int main() {
	vector<int> num = {3,5,-4,8,11,1,-1,6};
	int targetSum = 10;
	vector<int> res = twoNumberSum(num, targetSum);
	if (res.size() == 2)
		cout << res[0] << " " << res[1];
}