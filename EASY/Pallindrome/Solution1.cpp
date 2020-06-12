/****************************************************
TC: O(n^2) : string concat takes n time
SC: O(n)
Method: Check if given string is equal to the reversed string
*****************************************************/

using namespace std;

bool isPalindrome(string str) {
  string reverse = "";
	int len = str.length() - 1;
	while(len >= 0) {
		reverse += str[len];
		len--;
	}
	return str == reverse;
}
