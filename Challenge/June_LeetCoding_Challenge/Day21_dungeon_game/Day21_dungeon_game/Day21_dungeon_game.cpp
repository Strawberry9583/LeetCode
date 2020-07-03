#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

// solution1: binary search+ DFS + prune;
class Solution1 {
	// m_dp[row][col] indicates the minimus requirements when comes to [row,col];
	std::vector<std::vector<int>> m_dp;
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		// firstly, the minimum requirements is >0 when comes to the position of [row,col];
		m_dp = dungeon;
		for (int row = 0; row < m_dp.size(); ++row) {
			for (int col = 0; col<m_dp.front().size(); ++col) {
				//health points should be greater to the abolute of negative points;
				if (m_dp[row][col] < 0) {
					m_dp[row][col] = std::abs(m_dp[row][col]);
				}
				else {
					m_dp[row][col] = 0;
				}
			}
		}
		// binary search method to check the specific health whether to be accesible;
		int left = 1, right = 100000;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (check(dungeon, mid, 0, 0)) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		return left;
	}
	bool check(std::vector<std::vector<int>>& dungeon, int health, int row, int col) {
		bool flag = true;
		// health < the minimum points indicates unvalide;
		if (m_dp[row][col] >= health) { flag=false; }
		else {
			int cur_health = health + dungeon[row][col];
			if (cur_health <= 0) {
				flag=false;
			}
			else if (row == dungeon.size() - 1 && col == dungeon.front().size() - 1) {
				flag=(cur_health > 0);
			}
			else if (row == dungeon.size() - 1) {
				flag=check(dungeon, cur_health, row, col + 1);
			}
			else if (col == dungeon.front().size() - 1) {
				flag=check(dungeon, cur_health, row + 1, col);
			}
			else {
				flag= check(dungeon, cur_health, row + 1, col) || check(dungeon, cur_health, row, col + 1);
			}
			// if unvalide too, update the requirements to higher level.
			if (!flag) { m_dp[row][col] = health; }
		}
		return flag;
	}
};

// solution2 top_down DP: reverse thinking with consideration from the end to the beginning.
// dp[i][j] indicates minimum requirements health points from [i][j] to end state
class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		int rows = dungeon.size(), cols = dungeon[0].size();
		vector<vector<int>> dp(rows, vector<int>(cols, 0));
		for (int i = rows - 1; i >= 0; --i) {
			for (int j = cols - 1; j >= 0; --j) {
				if (i == rows - 1 && j == cols - 1) {
					//only one path, then to satisfy the requirement of [i][j]
					dp[i][j] = dungeon[i][j] > 0 ? 1 : 1-dungeon[i][j];
				}
				else if (i == rows - 1) {
					//only one path, then to satisfy the requirement of [i][j+1]
					dp[i][j] = std::max({ dp[i][j + 1] - dungeon[i][j],1 });
				}
				else if (j == cols - 1) {
					//only one path, then to satisfy the requirement of [i+1][j]
					dp[i][j] = std::max(dp[i + 1][j] - dungeon[i][j], 1);
				}
				else {
					//only one path, then to satisfy the requirement of [i+1][j] or [i][j+1];
					dp[i][j] = std::max(1,std::min(dp[i+1][j]-dungeon[i][j],dp[i][j+1]-dungeon[i][j]));
				}
			}
		}
		return dp[0][0];
	}
};

int main() {
	std::vector<std::vector<int>>test = { {-2,-3,3},{-5,-10,1},{10,30,-5} };
	std::cout << Solution().calculateMinimumHP(test);
	cin.get();
	return 0;
}