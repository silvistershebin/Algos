/****************************************************
Best Method
Avoiding string concat else TC would be O(n^2)
int of z is 122
int of a is 96
TC: O(n)
SC: O(n)
*****************************************************/

using namespace std;

char newChar(char letter, int key) {
	int newCode = letter + key;
	return newCode <= 122 ? newCode : 96 + newCode % 122;
}

string caesarCypherEncryptor(string str, int key) {
	key %= 26;
	vector<char> newStr;
  for(int i = 0; i < str.length(); i ++) {
		newStr.push_back(newChar(str[i], key));
	}
  return string(newStr.begin(), newStr.end());
}

