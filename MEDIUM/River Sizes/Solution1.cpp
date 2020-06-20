/****************************************************
TC: O(w*h) : (w:width; h:height)
SC: O(w*h)
*****************************************************/

#include <vector>
using namespace std;

vector<vector<int>> unvisitedNeighbors(int i, int j, int colSize, int rowSize, vector<vector<bool>> visited) {
	vector<vector<int>> neighbors;
	if(i > 0 && !visited[i-1][j]) {
		neighbors.push_back({i-1, j});
	}
	if(j > 0 && !visited[i][j-1]) {
		neighbors.push_back({i, j-1});
	}
	if(i < rowSize - 1 && !visited[i+1][j]) {
		neighbors.push_back({i+1, j});
	}
	if(j < colSize - 1 && !visited[i][j+1]) {
		neighbors.push_back({i, j+1});
	}
	return neighbors;
}

void traverseNodes(vector<vector<int>> matrix, vector<vector<bool>> *visited, int i, int j, vector<int> *size) {
	int length = 0;
	vector<vector<int>> nodes = {{i,j}};
	while(nodes.size() > 0) {
		auto currnode = nodes.back();
		nodes.pop_back();
		i = currnode[0];
		j = currnode[1];
		if(visited->at(i)[j])
			continue;
		visited->at(i)[j] = true;
		if(matrix[i][j] == 0)
			continue;
		length++;
		vector<vector<int>> neighbors = unvisitedNeighbors(i, j, matrix[0].size(), matrix.size(), *visited);
		for(auto i : neighbors)
			nodes.push_back(i);
	}
	if(length > 0)
		size->push_back(length);
}

vector<int> riverSizes(vector<vector<int>> matrix) {
  vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));
  vector<int> lake;
	for(int i = 0; i < matrix.size(); i++) {
		for(int j = 0; j < matrix[0].size(); j++) {
			if(!visited[i][j]) {
				traverseNodes(matrix, &visited, i, j, &lake);	
			}
		}
	}
	return lake;
}
