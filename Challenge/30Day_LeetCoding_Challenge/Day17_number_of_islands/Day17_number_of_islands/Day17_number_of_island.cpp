#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

//solution 1: use queue to store the promising position and then expand;
//Similar to BFS of the graph;
//First search the start position with depth of 0, then 1,2,3...
//Until no land position in the queue;
class Solution1 {
public:
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty()) {
			return 0;
		}
		std::vector<std::vector<int>> visit_flag(grid.size(), std::vector<int>(grid.begin()->size(), 0));
		int result = 0;
		for (int row = 0; row < grid.size(); ++row) {
			for (int col = 0; col<grid.begin()->size(); ++col) {
				if (grid[row][col] == '1' && visit_flag[row][col] == 0) {
					set_visit(row, col, grid, visit_flag);
					++result;
				}
			}
		}
		return result;
	}
	void set_visit(int start_row, int start_col, std::vector<std::vector<char>> & grid, std::vector<std::vector<int>> & visit_flag) {
		std::queue<std::pair<int, int>> visit_que;
		visit_que.emplace(start_row, start_col);
		visit_flag[start_row][start_col] = 1;
		while (!visit_que.empty()) {
			auto pos = visit_que.front();
			visit_que.pop();
			if (pos.first - 1 >= 0 && pos.first - 1 < grid.size() && pos.second >= 0 && pos.second < grid.begin()->size() && \
				!visit_flag[pos.first - 1][pos.second] && grid[pos.first - 1][pos.second] == '1') {
				visit_que.emplace(pos.first - 1, pos.second);
				visit_flag[pos.first - 1][pos.second] = 1;
			}
			if (pos.first + 1 >= 0 && pos.first + 1 < grid.size() && pos.second >= 0 && pos.second < grid.begin()->size() && \
				!visit_flag[pos.first + 1][pos.second] && grid[pos.first + 1][pos.second] == '1') {
				visit_que.emplace(pos.first + 1, pos.second);
				visit_flag[pos.first + 1][pos.second] = 1;
			}
			if (pos.first >= 0 && pos.first < grid.size() && pos.second - 1 >= 0 && pos.second - 1 < grid.begin()->size() && \
				!visit_flag[pos.first][pos.second - 1] && grid[pos.first][pos.second - 1] == '1') {
				visit_que.emplace(pos.first, pos.second - 1);
				visit_flag[pos.first][pos.second - 1] = 1;
			}
			if (pos.first >= 0 && pos.first < grid.size() && pos.second + 1 >= 0 && pos.second + 1 < grid.begin()->size() && \
				!visit_flag[pos.first][pos.second + 1] && grid[pos.first][pos.second + 1] == '1') {
				visit_que.emplace(pos.first, pos.second + 1);
				visit_flag[pos.first][pos.second + 1] = 1;
			}
		}
	}
};

//solution 2: use recursion to implement DFS;
class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty()) {
			return 0;
		}
		std::vector<std::vector<int>> visit_flag(grid.size(), std::vector<int>(grid.begin()->size(), 0));
		int result = 0;
		for (int row = 0; row < grid.size(); ++row) {
			for (int col = 0; col<grid.begin()->size(); ++col) {
				if (grid[row][col] == '1' && visit_flag[row][col] == 0) {
					set_visit(row, col, grid, visit_flag);
					++result;
				}
			}
		}
		return result;
	}
	void set_visit(int start_row, int start_col, std::vector<std::vector<char>> & grid, std::vector<std::vector<int>> & visit_flag) {
		visit_flag[start_row][start_col] = 1;

		if (start_row - 1 >= 0 && start_row - 1 < grid.size() && start_col >= 0 && start_col < grid.begin()->size() && \
			!visit_flag[start_row - 1][start_col] && grid[start_row - 1][start_col] == '1') {
			set_visit(start_row - 1, start_col, grid, visit_flag);
		}
		if (start_row + 1 >= 0 && start_row + 1 < grid.size() && start_col >= 0 && start_col < grid.begin()->size() && \
			!visit_flag[start_row + 1][start_col] && grid[start_row + 1][start_col] == '1') {
			set_visit(start_row + 1, start_col, grid, visit_flag);
		}
		if (start_row >= 0 && start_row < grid.size() && start_col - 1 >= 0 && start_col - 1 < grid.begin()->size() && \
			!visit_flag[start_row][start_col - 1] && grid[start_row][start_col - 1] == '1') {
			set_visit(start_row, start_col - 1, grid, visit_flag);
		}
		if (start_row >= 0 && start_row < grid.size() && start_col + 1 >= 0 && start_col + 1 < grid.begin()->size() && \
			!visit_flag[start_row][start_col + 1] && grid[start_row][start_col + 1] == '1') {
			set_visit(start_row, start_col + 1, grid, visit_flag);
		}

	}
};

int main() {
	Solution sol;
	char c = '1';
	std::vector<std::vector<char>> test_grid{{'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};
	std::cout << sol.numIslands(test_grid);
	std::cin.get();
	return 0;
}