/****************************************************
TC: O(n)
SC: O(1)
Method: 2 pointer method traversing both the arrays (while loop)
*****************************************************/

#include<bits/stdc++.h>
using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
	auto mpointer = array.begin();
	auto spointer = sequence.begin();
	while(mpointer != array.end() && spointer != sequence.end()) {
		if(*spointer == *mpointer)
			spointer++;
		mpointer++;
	}
	if(spointer == sequence.end())
		return true;
	return false;
}

int main(){
	vector<int> marray = {5, 1, 22, 25, 6, -1, 8, 10};
	vector<int> sarray = {1, 6, -1, 10};
	if(isValidSubsequence(marray, sarray))
		cout << "true";
	else
		cout << "false";
}
