/****************************************************
TC: (Best: O(N); Worst: O(N^2))
SC: O(log(N)) 
Method: 
	Steps are similar to quicksort
	Additionally, just check if the right index is equal to the position of element to be found
*****************************************************/

#include <vector>
using namespace std;

int quickSortHelper(vector<int> array, int startIdx, int endIdx, int position) {
	if(startIdx > endIdx)
		return -1;
	int pivot = startIdx;
	int left = startIdx + 1, right = endIdx;
	while(left <= right) {
		if(array[left] > array[pivot] && array[right] < array[pivot]) {
			swap(array[left], array[right]);
		}
		if(array[left] <= array[pivot])
			left++;
		if(array[right] >= array[pivot])
			right--;
	}
	swap(array[pivot], array[right]);
	if(right == position)
		return array[right];
	else if(right < position)	//ignore remaining part
		return quickSortHelper(array, right + 1, endIdx, position);
	else
		return quickSortHelper(array, startIdx, right - 1, position);
}

int quickselect(vector<int> array, int k) {
  return quickSortHelper(array, 0, array.size() - 1, k - 1);
}
