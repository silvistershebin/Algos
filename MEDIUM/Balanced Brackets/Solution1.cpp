/****************************************************
TC: O(n)
SC: O(n)
Method:
	1. Push opening bracket into stack
	2. If Closing bracket, then check if matches with top of stack; if stack empty, return false
	3. If do not match, return false
*****************************************************/

#include <stack>
using namespace std;

bool balancedBrackets(string str) {
  string opening = "([{";
	string closing = ")]}";
	map<char,char> matching = {{'(',')'},{'[',']'},{'{','}'}};
	stack<char> s;
	for(char c : str) {
		if(opening.find(c) != string::npos)
			s.push(c);
		else if(closing.find(c) != string::npos) {
			if(s.empty())
				return false;
			if(matching[s.top()] == c)
				s.pop();
			else
				return false;
		}
	}
	return s.empty();
}
