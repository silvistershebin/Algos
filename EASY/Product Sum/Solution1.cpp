/****************************************************
TC: O(n) where n is the total number of integer elements in all lists
SC: O(d) where d is the maximum depth
Method: Recursive; Tricky Part: 1. check if vector; 2. type cast 'any' type to 'vector<any>' or 'int' using any_case 
*****************************************************/

#include <any>
#include <vector>

using namespace std;

int productSum(vector<any> array, int depth = 1) {
	int sum = 0;
  for(auto i : array) {
		if(i.type() == typeid(vector<any>))
			sum += productSum(any_cast<vector<any>>(i), depth + 1);
		else 
			sum += any_cast<int>(i);
	}
  return sum * depth;
}
