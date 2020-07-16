/****************************************************
TC: O(N*M)
SC: O(N*M)
Method: DP
Note: SC complexity can be reduced to O(max(N,M))
*****************************************************/

using namespace std;

int levenshteinDistance(string str1, string str2) {
  vector<vector<int>> E(str2.length() + 1, vector<int>(str1.length() + 1, 0));
	for(int i = 0; i <= str1.length(); i++)
		E[0][i] = i;
	for(int i = 0; i <= str2.length(); i++)
		E[i][0] = i;
	for(int r = 1; r <= str2.length(); r++) {
		for(int c = 1; c <= str1.length(); c++) {
			if(str1[c - 1] == str2[r - 1])
				E[r][c] = E[r-1][c-1];
			else
				E[r][c] = 1 + min(E[r-1][c], min(E[r][c-1], E[r-1][c-1]));
		}
	}
  return E[str2.length()][str1.length()];
}
