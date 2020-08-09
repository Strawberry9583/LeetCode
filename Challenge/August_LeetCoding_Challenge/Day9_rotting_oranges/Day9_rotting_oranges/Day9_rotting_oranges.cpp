#include<vector>
#include<iostream>
#include<queue>
#include<set>

using namespace std;


// method1: simulation;
// in each day, rot the fresh ones around the rotten ones;
// h == grid.size(), w = grid.front().size();
// Time complexity: O(h * w * (h + w)); 
// Space complexity: O(max(h,w));
class Solution1 {
public:
	int orangesRotting(vector<vector<int>>& grid) {

		int time = 0;
		for (time = 1; time <= 20; ++time) {
			//std::vector<std::vector<int>> rot_flag(grid.size(),std::vector<int>(grid.front().size(),0));
			set<pair<int, int>> rot_set;
			for (int row = 0; row < grid.size(); ++row) {
				for (int col = 0; col < grid.front().size(); ++col) {
					if (grid[row][col] == 2) {
						if (row + 1 < grid.size() &&grid[row + 1][col] == 1) {
							rot_set.emplace(row + 1, col);
						}
						if (row - 1 >= 0 && grid[row - 1][col] == 1 ) {
							rot_set.emplace(row - 1, col);
						}
						if (col + 1 < grid.front().size() &&grid[row][col + 1] == 1 ) {
							rot_set.emplace(row, col + 1);
						}
						if (col - 1 >= 0 && grid[row][col - 1] == 1 ) {
							rot_set.emplace(row, col - 1);
						}
					}
				}
			}
			for (auto & pos : rot_set) {
				grid[pos.first][pos.second] = 2;
			}
			if (rot_set.empty()) {
				break;
			}
		}
		for (int row = 0; row < grid.size(); ++row) {
			for (int col = 0; col < grid.front().size(); ++col) {
				if (grid[row][col] == 1) {
					return -1;
				}
			}
		}
		return time;
	}

};

// method2: BFS
// https://leetcode.com/problems/rotting-oranges/discuss/238579/C%2B%2BJava-with-picture-BFS
// Time compelxity: O(h * w * (h + w));
// Space complexity: O(1).
class Solution {
public:
	int rot(vector<vector<int>>& g, int i, int j, int d) {
		if (i < 0 || j < 0 || i >= g.size() || j >= g[i].size() || g[i][j] != 1) return 0;
		g[i][j] = d + 3;
		return 1;
	}
	int orangesRotting(vector<vector<int>>& g, int d = 0, int fresh = 0) {
		for (auto i = 0; i < g.size(); ++i)
			fresh += count_if(begin(g[i]), end(g[i]), [](int j) { return j == 1; });
		for (auto old_fresh = fresh; fresh > 0; ++d) {
			for (auto i = 0; i < g.size(); ++i)
				for (auto j = 0; j < g[i].size(); ++j)
					if (g[i][j] == d + 2)
						fresh -= rot(g, i + 1, j, d) + rot(g, i - 1, j, d) + rot(g, i, j + 1, d) + rot(g, i, j - 1, d);
			if (fresh == exchange(old_fresh, fresh)) return -1;
		}
		return d;
	}
};

int main() {
	cin.get();
	return 0;
}