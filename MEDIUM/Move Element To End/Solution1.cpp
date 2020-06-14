/****************************************************
TC: O(n)
SC: O(1)
Method: Two Pointer method (L and R); swap the values on condition match
*****************************************************/

#include <vector>

using namespace std;

vector<int> moveElementToEnd(vector<int> array, int toMove) {
  int left = 0;
	int right = array.size() - 1;
	while(left < right) {
		if(array[left] == toMove) {
			if(array[right] != toMove) {
				swap(array[left], array[right]);
				left++;
				right--;
			} else right--;
		} else left++;
	}
	return array;
}

