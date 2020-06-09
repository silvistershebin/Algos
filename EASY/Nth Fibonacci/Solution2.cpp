/****************************************************
Better method using STL maps
TC: O(n)
SC: O(n)
Method: Store Fibonacci value in a Map after computation to avoid redundant, unecessary computation
*****************************************************/

using namespace std;

int fibHelper(int n, map<int,int> m) {
	if(m.find(n) != m.end()) {
		return m[n];
	} else {
		m[n] = fibHelper(n - 1, m) + fibHelper(n - 2, m);
		return m[n];
	}
}

int getNthFib(int n) {
	map<int,int> m;
	m[1] = 0;
	m[2] = 1;
  return fibHelper(n, m);
}
