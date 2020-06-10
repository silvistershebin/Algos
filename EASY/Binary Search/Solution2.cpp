/****************************************************
Not space efficient
TC: O(log(n))
SC: O(log(n))
Method: Recursive method
*****************************************************/

#include <vector>
using namespace std;

int binarySearchHelper(vector<int> array, int target, int left, int right) {
	int mid = (left + right) / 2;
	if(left > right)
		return -1;
	if (array[mid] == target)
		return mid;
	else if (target > array[mid])
		return binarySearchHelper(array, target, mid + 1, right);
	else return binarySearchHelper(array, target, left, mid - 1);
}

int binarySearch(vector<int> array, int target) {
	return binarySearchHelper(array, target, 0, array.size() - 1);
}
