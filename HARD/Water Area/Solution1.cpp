/****************************************************
TC: O(N)
SC: O(N)
Method: Basic Logic
*****************************************************/

#include <vector>
using namespace std;

int waterArea(vector<int> heights) {
	vector<int> leftMax, rightMax;
	int t = 0;
	for(int height : heights) {
		leftMax.push_back(t);
		cout << t << "\t";
		t = max(t, height);
	}
	cout << endl;
	t = 0;
	for(int i = heights.size() - 1; i >=0; i--) {
		rightMax.insert(rightMax.begin(), t);
		cout << t << "\t";
		t = max(t, heights[i]);
	}
	cout << endl;
	int water = 0, minHeight;
	for(int i = 0; i < heights.size(); i++) {
		minHeight = min(leftMax[i], rightMax[i]);
		if(heights[i] < minHeight)
			water += (minHeight - heights[i]);
	}
	return water;
}
