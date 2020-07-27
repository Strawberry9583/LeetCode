#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

// solution 1: BFS
//check whether 'O' is connected with boundary 'O'
class Solution {
	// record the postion whether have been checked;
	std::vector<std::vector<int>> m_visited;
public:
	void solve(vector<vector<char>>& board) {
		m_visited.resize(board.size(), std::vector<int>(board.front().size(), 0));
		for (int row = 0; row < board.size(); ++row) {
			for (int col = 0; col < board.front().size(); ++col) {
				if (board[row][col] == 'O' && !m_visited[row][col]) {
					BFS(row, col, board);
				}
			}
		}
	}
	void BFS(int row, int col, std::vector<std::vector<char>> & board) {
		std::queue<std::pair<int, int>> pos_que; pos_que.emplace(row, col);
		// store the 'O' positions that could be changed according to flag;
		std::vector<std::pair<int, int>> archive; archive.emplace_back(row, col);
		m_visited[row][col] = 1;
		// flag to indicate whether the connected area is connected to the boundary 'O';
		bool flag = false;
		while (!pos_que.empty()) {
			auto pos = pos_que.front(); pos_que.pop();
			if (pos.first == 0 || pos.first == board.size() - 1 || pos.second == 0 || pos.second == board.front().size() - 1) {
				flag = true;
			}
			if (pos.first + 1 < board.size() && !m_visited[pos.first + 1][pos.second]&&board[pos.first+1][pos.second]=='O') {
				m_visited[pos.first + 1][pos.second] = 1;
				pos_que.emplace(pos.first + 1, pos.second);
				archive.emplace_back(pos.first + 1, pos.second);
			}
			if (pos.first - 1 >=0 && !m_visited[pos.first - 1][pos.second] && board[pos.first - 1][pos.second] == 'O') {
				m_visited[pos.first - 1][pos.second] = 1;
				pos_que.emplace(pos.first - 1, pos.second);
				archive.emplace_back(pos.first - 1, pos.second);

			}
			if (pos.second + 1 < board.front().size() && !m_visited[pos.first][pos.second + 1] && board[pos.first][pos.second + 1] == 'O') {
				m_visited[pos.first][pos.second + 1] = 1;
				pos_que.emplace(pos.first, pos.second + 1);
				archive.emplace_back(pos.first, pos.second + 1);
			}
			if (pos.second - 1 >=0 && !m_visited[pos.first][pos.second - 1] && board[pos.first][pos.second - 1] == 'O') {
				m_visited[pos.first][pos.second - 1] = 1;
				pos_que.emplace(pos.first, pos.second - 1);
				archive.emplace_back(pos.first, pos.second - 1);
			}
		}
		if (!flag) {
			for (auto & pos : archive) {
				board[pos.first][pos.second] = 'X';
			}
		}
	}
};

// solution2: DFS
// search all the connected 'O' with boundary 'O', then flag them;
class Solution {
	// record the postion whether have been checked;
	std::vector<std::vector<int>> m_visited;
public:
	//void solve(vector<vector<char>>& board) {
	//	m_visited.resize(board.size(), std::vector<int>(board.front().size(), 0));
	//	for (int row = 0; row < board.size(); ++row) {
	//		if()
	//	}
	//}
	//void BFS(int row, int col, std::vector<std::vector<char>> & board) {
	//	std::queue<std::pair<int, int>> pos_que; pos_que.emplace(row, col);
	//	// store the 'O' positions that could be changed according to flag;
	//	std::vector<std::pair<int, int>> archive; archive.emplace_back(row, col);
	//	m_visited[row][col] = 1;
	//	// flag to indicate whether the connected area is connected to the boundary 'O';
	//	bool flag = false;
	//	while (!pos_que.empty()) {
	//		auto pos = pos_que.front(); pos_que.pop();
	//		if (pos.first == 0 || pos.first == board.size() - 1 || pos.second == 0 || pos.second == board.front().size() - 1) {
	//			flag = true;
	//		}
	//		if (pos.first + 1 < board.size() && !m_visited[pos.first + 1][pos.second] && board[pos.first + 1][pos.second] == 'O') {
	//			m_visited[pos.first + 1][pos.second] = 1;
	//			pos_que.emplace(pos.first + 1, pos.second);
	//			archive.emplace_back(pos.first + 1, pos.second);
	//		}
	//		if (pos.first - 1 >= 0 && !m_visited[pos.first - 1][pos.second] && board[pos.first - 1][pos.second] == 'O') {
	//			m_visited[pos.first - 1][pos.second] = 1;
	//			pos_que.emplace(pos.first - 1, pos.second);
	//			archive.emplace_back(pos.first - 1, pos.second);

	//		}
	//		if (pos.second + 1 < board.front().size() && !m_visited[pos.first][pos.second + 1] && board[pos.first][pos.second + 1] == 'O') {
	//			m_visited[pos.first][pos.second + 1] = 1;
	//			pos_que.emplace(pos.first, pos.second + 1);
	//			archive.emplace_back(pos.first, pos.second + 1);
	//		}
	//		if (pos.second - 1 >= 0 && !m_visited[pos.first][pos.second - 1] && board[pos.first][pos.second - 1] == 'O') {
	//			m_visited[pos.first][pos.second - 1] = 1;
	//			pos_que.emplace(pos.first, pos.second - 1);
	//			archive.emplace_back(pos.first, pos.second - 1);
	//		}
	//	}
	//	if (!flag) {
	//		for (auto & pos : archive) {
	//			board[pos.first][pos.second] = 'X';
	//		}
	//	}
	//}
};

int main() {
	Solution sol;
	std::vector<std::vector<char>> test_vec = { {} };
	sol.solve(test_vec);
	cin.get();
	return 0;
}