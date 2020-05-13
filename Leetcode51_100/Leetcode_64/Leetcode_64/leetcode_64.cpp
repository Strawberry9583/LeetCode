#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


//solution 1: use dp[i][j] indicate the shortest path for (i,j) to (0,0);
//State transition formulation: dp[row][col] = std::min(dp[row - 1][col], dp[row][col-1]) + grid[row][col];
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.empty()) {
			return 0;
		}
		std::vector<std::vector<int>> dp(grid.size(), std::vector<int>(grid.begin()->size(), 0));
		dp[0][0] = grid[0][0];
		for (int row = 0; row < dp.size(); ++row) {
			for (int col = 0; col < dp.begin()->size(); ++col) {
				if (row == 0&&col==0) {
					continue;
				}
				else if (row == 0) {
					dp[row][col] = dp[row][col - 1] + grid[row][col];
				}
				else if (col == 0) {
					dp[row][col] = dp[row - 1][col] + grid[row][col];
				}
				else {
					dp[row][col] = std::min(dp[row - 1][col], dp[row][col-1]) + grid[row][col];
				}
			}
		}
		return dp[grid.size() - 1][grid.begin()->size() - 1];
	}
};



//solution 2: reduce the space complexity to O(min(m,n)) with DP;
//Caution: dp record the shorter edge;
//Outer looper is the longer edge;
//Inner looper is the shoreter edge;
class Solution1 {
public:
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.empty()) {
			return 0;
		}
		//record the shorter edge .
		std::vector<int> dp(std::min(grid.size(), grid.begin()->size()), 0);
		//if col nums > row nums;
		bool if_wide = true;
		if (grid.size() > grid.begin()->size()) {
			if_wide = false;
		}
		dp[0] = grid[0][0];
		//dp.back = grid[0][0];
		for (int idx = 1; idx < (if_wide ? grid.size() : grid.begin()->size()); ++idx) {
			dp[idx] =dp[idx-1]+( if_wide ? grid[idx][0] : grid[0][idx]);
		}
		//Outer looper is the longer edge;
		for (int idx = 1; idx < (if_wide ? grid.begin()->size() : grid.size()); ++idx) {
			dp[0] += if_wide ? grid[0][idx] : grid[idx][0];
			//Inner looper is the shoreter edge;
			for (int shorter_idx = 1; shorter_idx < (if_wide ? grid.size() : grid.begin()->size()); ++shorter_idx) {
				//matrix is wider;
				if (if_wide) {
					dp[shorter_idx] = std::min(dp[shorter_idx - 1] + grid[shorter_idx][idx],
						dp[shorter_idx] + grid[shorter_idx][idx]);
				}
				//matrix is higher;
				else {
					dp[shorter_idx] = std::min(dp[shorter_idx - 1] + grid[idx][shorter_idx],
						dp[shorter_idx] + grid[idx][shorter_idx]);
				}
			}
		}
		//caution: can not return the dp.back();
		//because the back() returned the reference of the last element; however, the dp is local variables;
		return *dp.rbegin();
	}
};




int main() {
	Solution1 sol;
	std::vector<std::vector<int>> test_grid{ {1, 3, 1}, {1, 5, 1}, {4, 2, 1} };
	std::cout << sol.minPathSum(test_grid);
	std::cin.get();
	return 0;
}