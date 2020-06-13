/****************************************************
TC: O(nlogn + mlogm) : time taken to sort the arrays
SC: O(1)
Method: Sort the arrays and use 2 pointers, pointing to the start of each array.
		Find the smallest pair accordingly.
*****************************************************/

#include <bits/stdc++.h>
using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
  sort(arrayOne.begin(), arrayOne.end());
	sort(arrayTwo.begin(), arrayTwo.end());
	int a1 = 0, a2 = 0;
	int diff = INT_MAX;
	int s1, s2;
	while(a1 < arrayOne.size() && a2 < arrayTwo.size()) {
		if(abs(arrayOne[a1] - arrayTwo[a2]) == 0)
			return {arrayOne[a1], arrayTwo[a2]};
		else if(abs(arrayOne[a1] - arrayTwo[a2]) < diff) {
			diff = abs(arrayOne[a1] - arrayTwo[a2]);
			s1 = arrayOne[a1];
			s2 = arrayTwo[a2];
			if(s1 > s2)
				a2++;
			else a1++;
		} else {
			if(arrayOne[a1] > arrayTwo[a2])
				a2++;
			else a1++;
		}
	}
  return {s1, s2};
}
