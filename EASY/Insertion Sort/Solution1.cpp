/****************************************************
TC: O(n^2)
SC: O(1)
*****************************************************/

#include <vector>
using namespace std;

vector<int> insertionSort(vector<int> array) {
	int j = 0;
	int temp1, temp2;
  for(int i = 1; i < array.size(); i++) {
		temp1 = j;
		temp2 = i;
		while(array[temp1] > array[temp2] && temp1 >= 0) {
			swap(array[temp1], array[temp2]);
			temp2 = temp1;
			temp1--;
		}
		j++;
	}
  return array;
}
