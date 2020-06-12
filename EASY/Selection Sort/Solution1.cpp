/****************************************************
Selection Sort
TC: O(n^2)
SC: O(1)
*****************************************************/

#include <vector>
using namespace std;

vector<int> selectionSort(vector<int> array) {
	int smallestIndex;
  for(int i = 0; i < array.size() - 1; i++) {
		int smallest = INT_MAX;
		for(int j = i; j < array.size(); j++) {
			if(array[j] < smallest) {
				smallest = array[j];
				smallestIndex = j;
			}
		}
		swap(array[i], array[smallestIndex]);
	}
  return array;
}
