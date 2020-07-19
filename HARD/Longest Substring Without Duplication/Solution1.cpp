/****************************************************
TC: O(N)
SC: O(min(N, A))
Method: Simple method using hashmap
*****************************************************/

using namespace std;

string longestSubstringWithoutDuplication(string str) {
	map<char, int> lastSeen;
	int st = 0, lt = 0, index = 0, startIndex = 0;
	for(char c : str) {
		if(lastSeen.find(c) != lastSeen.end())
			startIndex = max(startIndex, lastSeen[c] + 1);
		if(lt - st < index - startIndex) {
			lt = index;
			st = startIndex;
		}
		lastSeen[c] = index;
		index++;
	}
	return str.substr(st, lt - st + 1);
}
