/****************************************************
TC: O(n)
SC: O(1)
Method:
	1. Check the number from where OutOfOrder starts
	2. Track minimum and maximum from there
	3. Find ideal position of max and min which is the ans
*****************************************************/

#include <bits/stdc++.h>
using namespace std;

bool isOutOfOrder(int i, vector<int> array) {
	if(i == 0)
		return array[i] > array[i+1];
	if(i == array.size() - 1)
		return array[i] < array[i-1];
	return array[i] > array[i+1] || array[i] < array[i-1];
}

vector<int> subarraySort(vector<int> array) {
  int minimum = INT_MAX, maximum = INT_MIN;
	for(int i = 0; i < array.size(); i++) {
		if(isOutOfOrder(i, array)) {
			minimum = min(minimum, array[i]);
			maximum = max(maximum, array[i]);
		}
	}
	if(minimum == INT_MAX || maximum == INT_MIN)
		return {-1,-1};
	int start = 0, end = array.size() - 1;
	while(array[start] <= minimum)
		start++;
	while(array[end] >= maximum)
		end--;
	return {start, end};
}
