/****************************************************
Best, Efficient Method
TC: O(n)
SC: O(1)
Method: Iterative approach - check if opposite chars are same
*****************************************************/

using namespace std;

bool isPalindrome(string str) {
	int last = str.length() - 1;
  for(int i = 0; i < str.length() / 2; i ++)  {
		if(str[i] != str[last])
			return false;
		last--;
	}
  return true;
}
