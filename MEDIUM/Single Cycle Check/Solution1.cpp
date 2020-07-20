/****************************************************
TC: O(N)
SC: O(1)
Method: Modulo
*****************************************************/

using namespace std;

int getIndex(int currentIndex, vector<int> array) {
	int j = array[currentIndex];
	int next = (j + currentIndex) % (int)array.size();
	if(next >= 0)
		return next;
	return next + array.size();
}

bool hasSingleCycle(vector<int> array) {
	int currentIndex = 0, elementsVisited = 0;
	while(elementsVisited < array.size()) {
		if(currentIndex == 0 && elementsVisited > 0) 
			return false;
		currentIndex = getIndex(currentIndex, array);
		elementsVisited++;
	}
	if(currentIndex == 0)
		return true;
	return false;
}
