/****************************************************
Recursive Approach
TC: O(n)
SC: O(n) : Call stack
*****************************************************/

using namespace std;

vector<int> spiralTraverseHelper(vector<vector<int>> array, int sC, int eC, int sR, int eR) {
	vector<int> res;
	if(sC > eC || sR > eR)
		return res;
	else if(sC == eC) {
		for(int i = sR; i <= eR; i++) 
			res.push_back(array[i][sC]);
		return res;
	} else if(sR == eR) {
		for(int i = sC; i <= eC; i++)
			res.push_back(array[sR][i]);
		return res;
	}
	for(int i = sC; i <= eC; i++)
		res.push_back(array[sR][i]);
	for(int i = sR + 1; i <= eR; i++)
		res.push_back(array[i][eC]);
	for(int i = eC - 1; i >= sC; i--)
		res.push_back(array[eR][i]);
	for(int i = eR - 1; i > sR; i--)
		res.push_back(array[i][sC]);
	vector<int> rec = spiralTraverseHelper(array, ++sC, --eC, ++sR, --eR);
	res.insert(res.end(), rec.begin(), rec.end());
	return res;
}

vector<int> spiralTraverse(vector<vector<int>> array) {
  return spiralTraverseHelper(array, 0, array[0].size()-1, 0, array.size()-1);
}
