/****************************************************
Best method for binary search
TC: O(log(n))
SC: O(1)
Method: Iterative method
*****************************************************/

#include <vector>
using namespace std;

int binarySearch(vector<int> array, int target) {
	int left = 0;
	int right = array.size() - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if(target == array[mid])
			return mid;
		else if(array[mid] < target) 
			left = mid + 1;
		else right = mid - 1; 
	}
	return -1;
}

