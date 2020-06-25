/****************************************************
TC: O(n)
SC: O(n)
Method:
	1. Store all numbers in hashmap
	2. Iterate through map and for every element move F and B to check if element exists in the hashmap
	3. Keep track of the largest range
*****************************************************/

#include <vector>
using namespace std;

vector<int> largestRange(vector<int> array) {
  unordered_map<int, bool> m;
	for(int i : array)
		m[i] = true;
	int lsize = 0, start, end;
	for(auto it : m) {
		if(!it.second)
			continue;
		int tsize = 1, ts, te;
		int t = it.first;
		while(m.find(t - 1) != m.end()) {
			t--;
			tsize++;
		}
		ts = t;
		t = it.first;
		while(m.find(t + 1) != m.end()) {
			t++;
			tsize++;
		}
		te = t;
		if(tsize > lsize) {
			start = ts;
			end = te;
			lsize = tsize;
		}
	}
  return {start, end};
}
