#include<iostream>
#include<vector>
#include<string>
#include<algorithm>


using namespace std;

// dfs
class Solution {
	std::vector<std::vector<int>> m_grid;
	std::pair<int, int> m_start;
	std::pair<int, int> m_end;
	int m_requirement_num;
	int m_result;
public:
	int uniquePathsIII(vector<vector<int>>& grid) {
		for (int row = 0; row < grid.size(); ++row) {
			for (int col = 0; col < grid.front().size(); ++col) {
				if (grid[row][col] == 1) {
					m_start.first = row; m_start.second = col;
				}
				else if (grid[row][col] == 2) {
					m_end.first = row; m_end.second = col;
				}
				else if (grid[row][col] == 0) {
					++m_requirement_num;
				}
			}
		}
		int visit_count = 0;
		m_grid = grid;
		//m_grid[m_start.first][m_start.second] = 3;
		dfs(m_start.first,m_start.second,visit_count);
		return m_result;
	}
private:
	void dfs(int cur_x,int cur_y,int visit_count) {
		if (cur_x < 0 || cur_x >= m_grid.size() || cur_y < 0 || cur_y >= m_grid.front().size()) {
			return;
		}
		else if (cur_x == m_end.first&&cur_y == m_end.second) {
			if (visit_count == m_requirement_num) {
				++m_result;
			}
			else {
				return;
			}
		}
		else if (m_grid[cur_x][cur_y] == -1||m_grid[cur_x][cur_y]==3) {
			return;
		}
		else {
			int cur_state = m_grid[cur_x][cur_y];
			if (cur_state == 0) {
				++visit_count;
			}
			m_grid[cur_x][cur_y] = 3;
			dfs(cur_x + 1, cur_y, visit_count);
			dfs(cur_x - 1, cur_y, visit_count);
			dfs(cur_x, cur_y + 1, visit_count);
			dfs(cur_x, cur_y - 1, visit_count);
			if (cur_state == 0) {
				--visit_count;
			}
			m_grid[cur_x][cur_y] = cur_state;
		}
	}
};

int main() {
	std::vector<std::vector<int>> grid = { {0,1},{2,0} };
	std::cout << Solution().uniquePathsIII(grid);
	cin.get();
	return 0;
}