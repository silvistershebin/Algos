//Iterative
/****************************************************
TC: O(n)
SC: O(1)
Method: use 4 pointers(sC, eC, sR, eR) and 4 for loops
*****************************************************/

using namespace std;

vector<int> spiralTraverse(vector<vector<int>> array) {
  int eC, sC = 0, sR = 0, eR;
	eC = array[0].size() - 1;
	eR = array.size() - 1;
	vector<int> res;
	while(sC < eC && sR < eR) {
		for(int i = sC; i <= eC; i++)
			res.push_back(array[sR][i]);
		for(int i = sR + 1; i <= eR; i++)
			res.push_back(array[i][eC]);
		for(int i = eC - 1; i >= sC; i--)
			res.push_back(array[eR][i]);
		for(int i = eR - 1; i > sR; i--)
			res.push_back(array[i][sC]);
		sC++;
		eC--;
		sR++;
		eR--;
	}
	//handle edge cases
	if(sC == eC) {
		for(int i = sR; i <= eR; i++) 
			res.push_back(array[i][sC]);
	} else if(sR == eR) {
		for(int i = sC; i <= eC; i++)
			res.push_back(array[sR][i]);		
	}
  return res;
}
