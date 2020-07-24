#include<iostream>
#include<vector>
#include<string>

using namespace std;

// solution1: dfs in every position of the board; 
// time complexity: O(row*col*4^word_length)
// space complexity:O(row*col);
class Solution1 {
public:
	bool exist(vector<vector<char>>& board, string word) {
		bool result = false;
		for (int row = 0; row < board.size(); ++row) {
			for (int col = 0; col < board.front().size(); ++col) {

				if (board[row][col] == word[0]) {
					std::vector<std::vector<int>> visited(board.size(), std::vector<int>(board.front().size(), 0));
					if (dfs(visited, 0, word, row, col, board)) {
						result = true;
						return result;
					}
				}

			}
		}
		return result;
	}
	bool dfs(std::vector<std::vector<int>>&visited, int cur_idx, const string & patter, int cur_row, int cur_col, std::vector<std::vector<char>> & board) {
		if (cur_idx == patter.size()) {
			return true;
		}
		else if (cur_row < 0 || cur_row >= board.size() || cur_col < 0 || cur_col >= board.front().size()\
			|| visited[cur_row][cur_col] == 1 || board[cur_row][cur_col] != patter[cur_idx]) {
			return false;
		}
		else {
			visited[cur_row][cur_col] = 1;
			bool flag = dfs(visited, cur_idx + 1, patter, cur_row + 1, cur_col, board) ||
				dfs(visited, cur_idx + 1, patter, cur_row - 1, cur_col, board) ||
				dfs(visited, cur_idx + 1, patter, cur_row, cur_col + 1, board) ||
				dfs(visited, cur_idx + 1, patter, cur_row, cur_col - 1, board);
			visited[cur_row][cur_col] = 0;
			return flag;
		}
	}
};

// Fully use the graph memory but not to allocate new vector to store visited flag, which is
// similar to solution1;
// time complexity: O(row*col*4^word_length) TLE
// space complexity:O(1);
class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		bool result = false;
		for (int row = 0; row < board.size(); ++row) {
			for (int col = 0; col < board.front().size(); ++col) {
				//std::vector<std::vector<int>> visited(board.size(), std::vector<int>(board.front().size(), 0));

				if (dfs( 0, word, row, col, board)) {
					result = true;
					break;
				}
			}
		}
		return result;
	}
	bool dfs(int cur_idx, const string & patter, int cur_row, int cur_col, std::vector<std::vector<char>> & board) {
		if (cur_idx == patter.size()) {
			return true;
		}
		else if (cur_row < 0 || cur_row >= board.size() || cur_col < 0 || cur_col >= board.front().size()\
			||  board[cur_row][cur_col] != patter[cur_idx]) {
			return false;
		}
		else {
			//visited[cur_row][cur_col] = 1;
			auto temp = board[cur_row][cur_col];
			board[cur_row][cur_col] = '#';
			bool flag = dfs(cur_idx + 1, patter, cur_row + 1, cur_col, board) ||
				dfs( cur_idx + 1, patter, cur_row - 1, cur_col, board) ||
				dfs( cur_idx + 1, patter, cur_row, cur_col + 1, board) ||
				dfs( cur_idx + 1, patter, cur_row, cur_col - 1, board);
			//visited[cur_row][cur_col] = 0;
			board[cur_row][cur_col] = temp;
			return flag;
		}
	}
};


int main() {
	std::vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'E', 'S'}, {'A', 'D', 'E', 'E'}};
	string word = "ABCESEEEFS";
	std::cout << Solution().exist(board, word);
	cin.get();
	return 0;
}