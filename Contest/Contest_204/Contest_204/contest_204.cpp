#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<functional>


using namespace std;


class Solution1 {
public:
	bool containsPattern(vector<int>& arr, int m, int k) {
		if (m*k > arr.size()) {
			return false;
		}
		string s(arr.size(), ' ');
		for (int idx = 0; idx < arr.size(); ++idx) {
			s[idx] = '1' - 1 + arr[idx];
		}
		for (int start_idx = 0; start_idx+m <= arr.size(); ++start_idx) {
			string targe_s = s.substr(start_idx, m);
			string target;
			for (int idx = 0; idx < k; ++idx) {
				target += targe_s;
			}
			if (s.find(target) != string::npos) {
				return true;
			}
		}
		return false;
	}
};

// method: DP;
// dp[i].first indicates the maximum  length of positive number with ending of nums[i];
// dp[i].second indicates the maximum length of negative number with ending of nums[i];

class Solution2 {
public:
	int getMaxLen(vector<int>& nums) {
		std::vector<pair<int, int>> dp(nums.size(), { 0,0 });
		if (nums[0] > 0) {
			dp[0].first = 1;
		}
		else if (nums[0] < 0) {
			dp[0].second = 1;
		}
		int result = dp[0].first;
		for (int idx = 1; idx < nums.size(); ++idx) {
			if (nums[idx] > 0) {
				dp[idx].first = dp[idx-1].first + 1;
				if (dp[idx - 1].second != 0) {
					dp[idx].second=dp[idx - 1].second + 1;
				}
			}
			else if (nums[idx] < 0) {
				if (dp[idx - 1].second != 0) {
					dp[idx].first = dp[idx - 1].second + 1;
				}
				dp[idx].second = dp[idx-1].first+1;
			}
			if (dp[idx].first > result) {
				result = dp[idx].first;
			}
		}
		return result;
	}
};

// method: bfs
// only three possible answers: 0, 1, 2.
class Solution3_1 {
public:
	int minDays(vector<vector<int>>& grid) {
		int one_num = 0;
		for (int row = 0; row < grid.size(); ++row) {
			for (int col = 0; col < grid.front().size(); ++col) {
				if (grid[row][col] == 1) {
					++one_num;
				}
			}
		}
		if (one_num != bfs(grid)) {
			return 0;
		}
		for (int row = 0; row < grid.size(); ++row) {
			for (int col = 0; col < grid.front().size(); ++col) {
				if (grid[row][col] == 1) {
					grid[row][col] = 0;
					if (bfs(grid)!=one_num-1) {
						return 1;
					}
					else {
						grid[row][col] = 1;
					}
				}

			}
		}
		return 2;
	}
private:
	int bfs(std::vector<std::vector<int>> & grid) {
		int row=0,col = 0;
		bool if_found = false;
		for (row = 0; row < grid.size(); ++row) {
			for (col = 0; col < grid.front().size(); ++col) {
				if ((!if_found)&&(grid[row][col] == 1)) {
					if_found = true;
					break;
				}
			}
			if (if_found) {
				break;
			}
		}
		if (!if_found) {
			return 0;
		}
		//if (row == grid.size() || col == grid.front().size()) {
		//	return 0;
		//}
		std::queue<pair<int, int>> bfs_que;
		std::vector<vector<int>> visit(grid.size(), std::vector<int>(grid.front().size(), 0));
		bfs_que.emplace(row, col);
		visit[row][col] = 1;
		int cur_one = 0;
		while (!bfs_que.empty()) {
			auto cur_pos = bfs_que.front(); bfs_que.pop();
			++cur_one;
			if (cur_pos.first-1 >= 0 &&grid[cur_pos.first-1][cur_pos.second]==1&&
				visit[cur_pos.first-1][cur_pos.second]==0) {
				bfs_que.emplace(cur_pos.first - 1, cur_pos.second);
				visit[cur_pos.first - 1][cur_pos.second] = 1;
			}
			if (cur_pos.first+1 < grid.size() && grid[cur_pos.first + 1][cur_pos.second ]==1 &&
				visit[cur_pos.first + 1][cur_pos.second]==0) {
				bfs_que.emplace(cur_pos.first + 1, cur_pos.second);
				visit[cur_pos.first + 1][cur_pos.second] = 1;
			}
			if (cur_pos.second-1>=0 && grid[cur_pos.first][cur_pos.second - 1] == 1 &&
				visit[cur_pos.first][cur_pos.second - 1]==0) {
				bfs_que.emplace(cur_pos.first, cur_pos.second - 1);
				visit[cur_pos.first][cur_pos.second - 1] = 1;
			}
			if (cur_pos.second+1 < grid.front().size()  && grid[cur_pos.first ][cur_pos.second + 1] == 1 &&
				visit[cur_pos.first][cur_pos.second + 1]==0) {
				bfs_que.emplace(cur_pos.first, cur_pos.second + 1);
				visit[cur_pos.first][cur_pos.second + 1] = 1;
			}
		}
		return cur_one;
	}
};



// method: dfs;
class Solution3_2 {
public:
	vector<int> dx = { 1, -1, 0, 0 };
	vector<int> dy = { 0, 0, 1, -1 };
	void dfs(int x, int y, vector<vector<int>> &grid, vector<vector<int>> & vis) {
		int n = grid.size();
		int m = grid[0].size();
		vis[x][y] = 1;
		for (int a = 0; a < 4; a++) {
			int nx = x + dx[a];
			int ny = y + dy[a];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny] && grid[nx][ny]) {
				dfs(nx, ny, grid, vis);
			}
		}
	}
	int count_islands(vector<vector<int>> & grid) {
		int islands = 0;
		int n = grid.size();
		int m = grid[0].size();
		vector<vector<int>> vis(n, vector<int>(m, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!vis[i][j] && grid[i][j]) {
					dfs(i, j, grid, vis);
					islands++;
				}
			}
		}
		return islands;
	}
	int minDays(vector<vector<int>>& grid) {
		int islands = count_islands(grid);
		int n = grid.size();
		int m = grid[0].size();
		// check for 0 ans
		if (islands > 1 || islands == 0) {
			return 0;
		}
		else {
			// check for 1 ans
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (grid[i][j]) {
						grid[i][j] = 0;
						// remove this block
						islands = count_islands(grid);
						// add back the block
						grid[i][j] = 1;
						if (islands > 1 || islands == 0)
							return 1;
					}

				}
			}
		}
		// else
		return 2;
	}
};
class Solution {
public:
	int numOfWays(vector<int>& nums) {

	}
};

int main() {
	//std::vector<int> test_vec{ -1,2 };
	//std::cout << Solution2().getMaxLen(test_vec);

	//std::vector<int> test_vec{ 1,2,3,1,2 };
	//int m = 2, k = 2;
	//std::cout << Solution1().containsPattern(test_vec, m, k);

	std::vector<std::vector<int>> test_vec={{1, 1, 0, 1, 1},
		{1, 1, 1, 1, 1},
		{1, 1, 0, 1, 1},
		{1, 1, 0, 1, 1}};
	std::cout << Solution3_1().minDays(test_vec);
	cin.get();
	return 0;
}