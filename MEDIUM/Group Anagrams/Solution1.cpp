/****************************************************
TC: O(wn(log(n))) : (w: no. of words; n: length of longest word)
SC: O(wn)
Method:
	1. Iterate through the string
	2. Check pallindrom by checking opposite characters : 2 cases
		a. Odd length
		b. Even Length
*****************************************************/

#include <vector>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> words) {
  vector<string> sortedString;
	unordered_map<string, vector<string>> m;
	for(string s : words) {
		string temp = s;
		sort(temp.begin(), temp.end());
		m[temp].push_back(s);
	}
	vector<vector<string>> res;
	for(auto it : m) {
		res.push_back(it.second);
	}
  return res;
}
