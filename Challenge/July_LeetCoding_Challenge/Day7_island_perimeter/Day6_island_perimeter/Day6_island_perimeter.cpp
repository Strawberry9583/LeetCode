#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int islandPerimeter(vector<vector<int>>& grid) {
		// calc the one grid num and grid adjacent edge num btwn two one grids;
		int one_num = 0, override_num = 0;
		for (int row = 0; row < grid.size(); ++row) {
			for (int col = 0; col < grid.front().size(); ++col) {
				if (grid[row][col]) {
					++one_num;
					if (row + 1 < grid.size()&&grid[row+1][col]) {
						++override_num;
					}
					if (col + 1 < grid.front().size() && grid[row][col + 1]) {
						++override_num;
					}
				}
			}
		}
		return one_num * 4 - override_num * 2;
	}
};

int main() {
	cin.get();
	return 0;
}