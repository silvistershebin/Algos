/****************************************************
TC: O(N^3) (Can be reduced to N^2 by eliminating repetitive palindrome check using DP in the 2D vector)
SC: O(N^2)
Method: DP
*****************************************************/

#include <vector>
using namespace std;

bool isPal(string str) {
	int l = 0, r = str.length() - 1;
	while(l < r) {
		if(str[l] != str[r])
			return false;
		l++;
		r--;
	}
	return true;
}

int palindromePartitioningMinCuts(string str) {
  vector<vector<bool>> palindrome(str.length(), vector<bool>(str.length()));
	for(int i = 0; i < str.length(); i++) {
		for(int j = i; j < str.length(); j++) {
			palindrome[i][j] = isPal(str.substr(i , j + 1 - i)); 
		}
	}
	vector<int> cuts(str.length(), INT_MAX);
	for(int i = 0; i < str.length(); i++) {
		if(palindrome[0][i])
			cuts[i] = 0;
		else {
			cuts[i] = cuts[i-1] + 1;
			for(int j = 1; j < str.length(); j++) {
				if(palindrome[j][i] && cuts[j-1] + 1 < cuts[i])
					cuts[i] = cuts[j-1] + 1;
			}
		}
	}
  return cuts[str.length() - 1];
}
