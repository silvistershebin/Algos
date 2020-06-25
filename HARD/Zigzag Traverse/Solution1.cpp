/****************************************************
TC: O(N) : (N: number of elements)
SC: O(1)
Method:
	1. If else Logic
	2. Track if goingUp or goingDown
	3. Update the pointers accordingly
*****************************************************/

#include <vector>

using namespace std;

bool outOfBounds(int height, int width, int row, int col) {
	return row < 0 || row > height || col < 0 || col > width;
}

vector<int> zigzagTraverse(vector<vector<int>> array) {
  vector<int> res;
	int height = array.size() - 1;
	int width = array[0].size() - 1;
	bool goingDown = true;
	int row = 0, col = 0;
	while(!outOfBounds(height, width, row, col)) {
		res.push_back(array[row][col]);
		if(goingDown) {
			if(col == 0 || row == height) {
				goingDown = false;
				if(row == height)
					col++;
				else row++;
			} else {
				row++;
				col--;
			}
		} else {
			if(row == 0 || col == width) {
				goingDown = true;
				if(col == width)
					row++;
				else col++;
			} else {
				row--;
				col++;
			}
		}
	}
  return res;
}
