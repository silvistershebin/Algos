/****************************************************
Not Efficient at all
TC: O(2^(N + M)) (N: length of first string; M: length of second string)
SC: O(N + M) 
Method: 
	Recursive calls to check 
	Note: Use memoization to store the already computed results
*****************************************************/

using namespace std;

bool interweavingStringsHelper(string one, string two, string three, int i, int j) {
	int k = i + j;
	if(k == three.size())
		return true;
	if(i < one.size() && one[i] == three[k])
		if(interweavingStringsHelper(one, two, three, i + 1, j))
			return true;
	if(j < two.size() && two[j] == three[k])
		return interweavingStringsHelper(one, two, three, i, j + 1);
	return false;
}

bool interweavingStrings(string one, string two, string three) {
	int onesize = one.size(), twosize = two.size(), threesize = three.size();
	if((onesize + twosize) != threesize)
		return false;
	return interweavingStringsHelper(one, two, three, 0, 0);
}
