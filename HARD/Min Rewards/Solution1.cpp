/****************************************************
TC: O(N)
SC: O(N)
Method:
	Simple iterative logical solution: iterate once from left to right and then from right to left
*****************************************************/

#include <vector>
using namespace std;

int minRewards(vector<int> scores) {
	vector<int> rewards(scores.size(), 1);
	int sum = 0;
	for(int i = 1; i < scores.size(); i++) {
		if(scores[i] > scores[i-1])
			rewards[i] = rewards[i-1] + 1;
		cout << rewards[i] << " ";
	}
	for(int i = scores.size() - 2; i >= 0; i--) {
		if(scores[i] > scores[i + 1])
			rewards[i] = max(rewards[i], rewards[i+1] + 1);
		sum += rewards[i];
	} 
	return accumulate(rewards.begin(), rewards.end(), 0); //sum of values in vector with 0
}
