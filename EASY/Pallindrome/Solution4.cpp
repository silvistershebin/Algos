/****************************************************
Improvement in TC in comparison with Solution1
TC: O(n)
SC: O(n)
Method: string concatenation takes n time; thus store the reverse string char by char into vector and convert it into a string
*****************************************************/

using namespace std;

bool isPalindrome(string str) {
  vector<char> rev;
	for(int i = str.length() - 1; i >= 0; i--) {
		rev.push_back(str[i]);
	}
	return str == string(rev.begin(), rev.end());
}
