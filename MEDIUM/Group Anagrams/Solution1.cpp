/****************************************************
TC: O(wn(log(n))) : (w: no. of words; n: length of longest word)
SC: O(wn)
Method: Sort all the words and store it in hashmap as a vector
*****************************************************/

#include <vector>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> words) {
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
