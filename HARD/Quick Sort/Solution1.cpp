/****************************************************
TC: Worst:O(N^2); Best:O(N(logN)) 
SC: O(N(logN))
Method: Select Pivot Element; Compare and swap the other elements accordingly
*****************************************************/

#include <vector>
using namespace std;

void quickSortHelper(vector<int> &array, int startIdx, int endIdx) {
	if(startIdx >= endIdx)
		return;
	int pivot = startIdx;
	int left = startIdx+1, right = endIdx;
	while(right >= left) {
		if(array[left] > array[pivot] && array[right] < array[pivot])
			swap(array[left], array[right]);
		if(array[left] <= array[pivot])
			left++;
		if(array[right] >= array[pivot])
			right--;
	}
	swap(array[pivot], array[right]);
	quickSortHelper(array, startIdx, right - 1);
	quickSortHelper(array, right + 1, endIdx);
}

vector<int> quickSort(vector<int> array) {
  quickSortHelper(array, 0, array.size() - 1);
	return array;
}
