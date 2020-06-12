/****************************************************
TC: O(n)
SC: O(n) : call stack
Method: Using Recursion find if first char equal to last char
*****************************************************/

using namespace std;

bool isPalHelper(string str, int first, int last) {
	if(first > last)
		return true;
	if(str[first] == str[last])
			return isPalHelper(str, ++first, --last);
	else return false;
}

bool isPalindrome(string str) {
  return isPalHelper(str, 0, str.length() - 1);
}
