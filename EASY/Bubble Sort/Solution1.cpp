/****************************************************
Basic Bubble Sort with O(n) for best case
TC: O(n^2)
SC: O(1)
*****************************************************/

#include <vector>
using namespace std;

vector<int> bubbleSort(vector<int> array) {
  bool isSorted = false;
	if(array.empty())
		return {};
	int j = 0;
	while(!isSorted) {
		isSorted = true;
		for(int i = 0; i < array.size() - j - 1; i++) {
			if(array[i] > array[i+1]) {
				int temp = array[i];
				swap(array[i], array[i+1]);
				isSorted = false;
			}
		}
		j++;
	}
	return array;
}
