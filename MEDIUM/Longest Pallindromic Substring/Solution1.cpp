/****************************************************
TC: O(n^2)
SC: O(1)
Method:
	1. Iterate through the string
	2. Check pallindrom by checking opposite characters : 2 cases
		a. Odd length
		b. Even Length
*****************************************************/

using namespace std;

int pallindromeLength(string str, int backP, int frontP) {
	int curL = 1;
	while(backP >= 0 && frontP < str.size()) {
		if(str[backP] == str[frontP])
			curL += 2;
		else break;
		backP--;
		frontP++;
	}	
	return curL;
}

string longestPalindromicSubstring(string str) {
	int largest = 0;
	string largestPal = "";
	int curL = 0;
  for(int i = 0; i < str.size(); i++) {
		curL = pallindromeLength(str, i - 1, i + 1);
		if(curL > largest) {
			largest = curL;
			largestPal = str.substr(i - (largest/2), largest);
		}
		curL = pallindromeLength(str, i - 1, i);
		if(curL > largest) {
			largest = curL;
			largestPal = str.substr(i - (largest/2), largest - 1);
		}
	}
  return largestPal;
}
