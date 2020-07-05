/****************************************************
TC: O(logN)
SC: O(logN)
Method: Recursive 
	1. Use Simple Binary Search twice
	2. In first iteration, if number is found, move to the left if the prev elem is also target element (check IOoB) else set the beginning of range.
	3. Second: if number is found, move to the right if next element is also target (check IOoB) else set the end of the range.
*****************************************************/

#include <vector>
using namespace std;

void alteredBinarySearch(vector<int> array, int target, int left, int right, vector<int> &finalRange, bool goLeft) {
	if(left > right)
		return;
	int mid = (left + right) / 2;
	if(array[mid] < target)
		alteredBinarySearch(array, target, mid + 1, right, finalRange, goLeft);	
	else if(array[mid] > target)
		alteredBinarySearch(array, target, left, mid - 1, finalRange, goLeft);
	else {
		if(goLeft) {
			if(mid == 0 || array[mid - 1] != target) 
				finalRange[0] = mid;
			else
				alteredBinarySearch(array, target, left, mid - 1, finalRange, goLeft);	
		} else {
			if(mid == array.size() - 1 || array[mid + 1] != target)
				finalRange[1] = mid;
			else
				alteredBinarySearch(array, target, mid + 1, right, finalRange, goLeft);	
		}
	}
}

vector<int> searchForRange(vector<int> array, int target) {
  vector<int> finalRange = {-1, -1};
	alteredBinarySearch(array, target, 0, array.size() - 1, finalRange, true);
	alteredBinarySearch(array, target, 0, array.size() - 1, finalRange, false);
  return finalRange;
}
