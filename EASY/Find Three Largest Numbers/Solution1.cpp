/****************************************************
TC: O(n)
SC: O(1)
*****************************************************/

#include <vector>
using namespace std;

void shift(vector<int> *res, int num, int index) {
	for(int i = 0; i <= index; i ++) {
		if(index == i)
			res->at(i) = num;
		else 
			res->at(i) = res->at(i + 1);
	}
}

vector<int> findThreeLargestNumbers(vector<int> array) {
  vector<int> res = {INT_MIN, INT_MIN, INT_MIN};
	for(int i : array) {
		if(i >= res[2] || res[2] == -INT_MAX)
			shift(&res, i, 2);
		else if(i >= res[1] || res[1] == -INT_MAX)
			shift(&res, i, 1);
		else if(i >= res[0] || res[0] == -INT_MAX)
			shift(&res, i, 0);
	}
  return res;
}
