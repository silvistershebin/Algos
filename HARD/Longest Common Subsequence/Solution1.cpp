/****************************************************
TC: O(N*M*min(N,M))
SC: O(N*M*min(N,M))
Method: DP
Note: TC and SC can be reduced to O(N*M)
*****************************************************/

#include <vector>
using namespace std;

vector<char> longestCommonSubsequence(string str1, string str2) {
  vector<vector<string>> E(str1.length() + 1, vector<string>(str2.length() + 1, ""));
	for(int r = 1; r <= str1.length(); r++) {
		for(int c = 1; c <= str2.length(); c++) {
			if(str1[r-1] == str2[c-1]) {
				E[r][c] = E[r-1][c-1] + str1[r-1];
			} else {
				if(E[r][c-1].length() > E[r-1][c].length())
					E[r][c] = E[r][c-1];
				else E[r][c] = E[r-1][c];
			}
		}
	}
  string subsequence = E[str1.length()][str2.length()];
	return vector<char>(subsequence.begin(), subsequence.end());
}
