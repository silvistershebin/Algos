/****************************************************
Best method, Space Efficient
TC: O(n)
SC: O(n)
Method: Iterative; store only last two fibonacci values in array to calculate next fibonacci value
*****************************************************/

using namespace std;

int fibHelper(int n, vector<int> v) {
	int fib;
	for(int i = 0; i < n - 1; i++) {
		fib = v[0] + v[1];
		v[0] = v[1];
		v[1] = fib;
	}
	return v[0];
}

int getNthFib(int n) {
	return fibHelper(n, {0, 1});
}
