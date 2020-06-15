/****************************************************
TC: O(n)
SC: O(1)
Method: Check if current number is peak. If yes, then find length by iterating backward and forward.
*****************************************************/

using namespace std;

int longestPeak(vector<int> array) {
	bool isPeak = false;
	int maxPeak = INT_MIN;
	int currPeak;
	int size = array.size();
	for(int i = 1; i < size - 1; i++) {
		isPeak = (array[i-1] < array[i]) && (array[i+1] < array[i]);
		if(!isPeak)
			continue;
		currPeak = 1;
		int pointer = i;
		while(array[pointer] > array[pointer - 1] && pointer > 0) {
			currPeak++;
			pointer--;
		}
		pointer = i;
		while(array[pointer] > array[pointer + 1] && pointer < size - 1) {
			currPeak++;
			pointer++;
		}
		cout << endl;
		if(currPeak > maxPeak)
			maxPeak = currPeak;
		i = pointer - 1;
	}
	if(maxPeak == INT_MIN)
		return 0;
  return maxPeak;
}
