/****************************************************
TC: O(N^2) : (Total number of elements)
SC: O(N)
*****************************************************/

#include <vector>
using namespace std;

bool comparator(vector<int> lhs, vector<int> rhs) {
   return lhs[2] < rhs[2];
}

vector<vector<int>> diskStacking(vector<vector<int>> disks) {
  sort(disks.begin(), disks.end(), &comparator);
	vector<int> height;
	for(vector<int> v : disks)
		height.push_back(v[2]);
	vector<int> sequence(disks.size(), -1);
	int maximum = INT_MIN, max_index = -1;
	for(int i = 0; i < disks.size(); i++) {
		int w = disks[i][0], d = disks[i][1],  h = disks[i][2];
		for(int j = 0; j < i; j++) {
			int w1 = disks[j][0], d1 = disks[j][1],  h1 = disks[j][2];
			if(w > w1 && d > d1) {
				int m = max(height[i], height[j] + h);
				if(m != height[i])
					sequence[i] = j;
				height[i] = m;
				if(m > maximum)
					max_index = i;
			}
		}
	}
	vector<vector<int>> res;
	for(int i : sequence)
		cout << i << " ";
	cout << endl;
	for(int i : height)
		cout << i << " ";
	do {
		res.insert(res.begin(), disks[max_index]);
		max_index = sequence[max_index];
	} while (max_index != -1);
  return res;
}
