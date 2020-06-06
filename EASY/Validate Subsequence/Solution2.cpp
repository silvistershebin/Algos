/****************************************************
TC: O(n)
SC: O(1)
Method: 2 pointer method traversing both the arrays (for loop)
*****************************************************/

#include<bits/stdc++.h>
using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
	auto spointer = sequence.begin();
	for (int i : array) {
		if(i == *spointer) {
			spointer++;
			if(spointer == sequence.end())
				return true;
		}
	}
	return false;
}

int main(){
	vector<int> marray = {5, 1, 22, 25, 6, -1, 8, 10};
	vector<int> sarray = {1, 6, -1, 1};
	if(isValidSubsequence(marray, sarray))
		cout << "true";
	else
		cout << "false";
}
