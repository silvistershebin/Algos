/****************************************************
Best and Compact Solution
TC: O(n)
SC: O(1)
*****************************************************/

using namespace std;

bool isMonotonic(vector<int> array) {
	bool isDecreasing = true;
	bool isIncreasing = true;
	for(int i = 1; i < array.size(); i++) {
		if(array[i] < array[i - 1])
			isDecreasing = false;
		if(array[i] > array[i - 1])
			isIncreasing = false;
	}
	return isIncreasing || isDecreasing;
}
