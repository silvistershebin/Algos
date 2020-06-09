/****************************************************
Easiest but worst method
TC: O(2^n)
SC: O(n)
Method: Recursion to return fibonacci(n-1) + fibonacci(n-2)
*****************************************************/

using namespace std;

int getNthFib(int n) {
  if(n == 2)
		return 1;
	if(n == 1)
		return 0;
	return getNthFib(n - 1) + getNthFib(n - 2);
	}
