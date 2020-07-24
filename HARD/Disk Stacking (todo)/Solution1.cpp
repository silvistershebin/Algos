/****************************************************
TC: O(N^2) : (Total number of elements)
SC: O(N)
*****************************************************/

#include <vector>
using namespace std;

bool isValid(vector<int> other, vector<int> curr) {
	return other[0] < curr[0] && other[1] < curr[1] && other[2] < curr[2];
}

vector<vector<int>> buildSeq(vector<vector<int>> array, vector<int> sequences, int currIndex) {
	vector<vector<int>> sequence;
	while(currIndex != INT_MIN) {
		sequence.insert(sequence.begin(), array[currIndex]);
		currIndex = sequences[currIndex];
	}
	return sequence;
}

vector<vector<int>> diskStacking(vector<vector<int>> disks) {
  sort(disks.begin(), disks.end(), [](vector<int> &lhs, vector<int> &rhs){
		return lhs[2] < rhs[2];
	});
	vector<int> heights;
	for(int i = 0; i < disks.size(); i++)
		heights.push_back(disks[i][2]);
	vector<int> seq;
	for(int i = 0; i < disks.size(); i++)
		seq.push_back(INT_MIN);
	int maxHeightIndex = 0;
	for(int i = 1; i < disks.size(); i++) {
		vector<int> currDisk = disks[i];
		for(int j = 0; j < i; j++) {
			vector<int> otherDisk = disks[j];
			if(isValid(otherDisk, currDisk)) {
				if(heights[i] <= currDisk[2] + heights[j]) {
					heights[i] = currDisk[2] + heights[j];
					seq[i] = j;
				}
			}
		}
		if(heights[i] >= heights[maxHeightIndex])
			maxHeightIndex = i;
	}
	return buildSeq(disks, seq, maxHeightIndex);
}
