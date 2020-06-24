/****************************************************
TC: 1. Average: O(n^2)
	2. Worst: O(n^3)
SC: O(n^2)
Method: 
	1. Consider Sum of Pair of numbers using double for loop
	2. Check if (targetSum - sum) is present in the MAP
	3. If yes, then insert into the result, else continue without doing anything
	4. Insert the sum of pair of all elements which are behind the first number of the pair after the end of the inner for loop
		(THIS METHOD WILL HELP AVOID DUPLICATE QUADRAPLETS)
		e.g:
		Consider input array with the following pointers.
			6	4	9	5	3	12	10	2
					^		^
		The sum to be inserted into the map: (6+3), (4+3), (9+3), (5+3)
*****************************************************/

#include <vector>
using namespace std;

vector<vector<int>> fourNumberSum(vector<int> array, int targetSum) {
	unordered_map<int, vector<vector<int>>> m;
	vector<vector<int>> result;
	int sum, diff;
  for(int i = 1; i < array.size(); i++) {
		for(int j = i+1; j < array.size(); j++) {
			sum = array[i] + array[j];
			diff = targetSum - sum;
			if(m.find(diff) != m.end()) {
				for(vector<int> p : m[diff]) {
					cout << array[i] << " " << array[j] << " " << p[0] << " " << p[1] << endl;
					p.push_back(array[i]);
					p.push_back(array[j]);
					result.push_back(p);
				}
			}
		}
		for(int t = 0; t < i; t++) {
			sum = array[t] + array[i];
			if(m.find(sum) != m.end())
				m[sum].push_back({array[t], array[i]});
			else
				m[sum] = vector<vector<int>>{{array[t], array[i]}};
		}			
	}
  return result;
}
