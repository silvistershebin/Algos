/****************************************************
TC: O(N*N!)
SC: O(N*N!)
Method: Recursive
*****************************************************/

#include <vector>
using namespace std;

void swap(vector<int> *, int, int);

void getPermutationsHelper(int i, vector<int> *array, vector<vector<int>> *allPerms) {
	if(i == array->size() - 1)
		allPerms->push_back(*array);
	else {
		for(int j = i; j < array->size(); j++) {
			swap(array, i, j);
			getPermutationsHelper(i+1, array, allPerms);
			swap(array, i, j);
		}
	}
}

void swap(vector<int> *array, int i, int j) {
	int tmp = array->at(i);
	array->at(i) = array->at(j);
	array->at(j) = tmp;
}

vector<vector<int>> getPermutations(vector<int> array) {
	vector<vector<int>> permutations;
  getPermutationsHelper(0, &array, &permutations);
  return permutations;
}
