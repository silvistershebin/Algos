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
