//36. Valid Sudoku
//Medium
//Determine if a 9x9 Sudoku board is valid.Only the filled cells need to be validated according to the following rules :
//
//Each row must contain the digits 1 - 9 without repetition.
//Each column must contain the digits 1 - 9 without repetition.
//Each of the 9 3x3 sub - boxes of the grid must contain the digits 1 - 9 without repetition.
//
//A partially filled sudoku which is valid.
//
//The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
//
//Example 1:
//
//Input:
//[
//	["5", "3", ".", ".", "7", ".", ".", ".", "."],
//	["6", ".", ".", "1", "9", "5", ".", ".", "."],
//	[".", "9", "8", ".", ".", ".", ".", "6", "."],
//	["8", ".", ".", ".", "6", ".", ".", ".", "3"],
//	["4", ".", ".", "8", ".", "3", ".", ".", "1"],
//	["7", ".", ".", ".", "2", ".", ".", ".", "6"],
//	[".", "6", ".", ".", ".", ".", "2", "8", "."],
//	[".", ".", ".", "4", "1", "9", ".", ".", "5"],
//	[".", ".", ".", ".", "8", ".", ".", "7", "9"]
//]
//Output: true
//	Example 2 :
//
//	Input :
//	[
//		["8", "3", ".", ".", "7", ".", ".", ".", "."],
//		["6", ".", ".", "1", "9", "5", ".", ".", "."],
//		[".", "9", "8", ".", ".", ".", ".", "6", "."],
//		["8", ".", ".", ".", "6", ".", ".", ".", "3"],
//		["4", ".", ".", "8", ".", "3", ".", ".", "1"],
//		["7", ".", ".", ".", "2", ".", ".", ".", "6"],
//		[".", "6", ".", ".", ".", ".", "2", "8", "."],
//		[".", ".", ".", "4", "1", "9", ".", ".", "5"],
//		[".", ".", ".", ".", "8", ".", ".", "7", "9"]
//	]
//		Output: false
//			Explanation : Same as Example 1, except with the 5 in the top left corner being
//			modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
//			Note :
//
//			A Sudoku board(partially filled) could be valid but is not necessarily solvable.
//			Only the filled cells need to be validated according to the mentioned rules.
//			The given board contain only digits 1 - 9 and the character '.'.
//			The given board size is always 9x9.

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int char2idx(char c) {
		if (c == '.') {
			return 0;
		}
		else {
			return c - 48;
		}
	}
	bool isValidSudoku(vector<vector<char>>& board) {
		for (int i = 0; i < 9; ++i) {
			vector<bool> isExist (10,false);
			//judge the column condition£»
			for (int j = 0; j < 9; ++j) {
				int idx = char2idx(board[i][j]);
				if (idx == 0) {
					continue;
				}
				else {
					if (!isExist[idx]) {
						isExist[idx] = true;
					}
					else {
						return false;
					}
				}
			}
			//reset the flag vector;
			for (auto i = isExist.begin(); i != isExist.end(); ++i) {
				*i = false;
			}
			//judge the row condition£»
			for (int j = 0; j < 9; ++j) {
				int idx = char2idx(board[j][i]);
				if (idx == 0) {
					continue;
				}
				else {
					if (!isExist[idx]) {
						isExist[idx] = true;
					}
					else {
						return false;
					}
				}
			}
		}
		//judge the small soku of 3 by 3 condition;
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (isValid(board, 3 * i, 3 * j)) {
					continue;
				}
				else {
					return false;
				}
			}
		}
		return true;
	}
	bool isValid(vector<vector<char>> & board, int x, int y) {
		vector<bool> isExist(10, false);
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				int idx = char2idx(board[x + i][y + j]);
				if (idx == 0) {
					continue;
				}
				else {
					if (!isExist[idx]) {
						isExist[idx] = true;
					}
					else {
						return false;
					}
				}
			}
		}
		return true;
	}
};

int main() {

	Solution sol;
	vector<vector<char>> board= {
	{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
			{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
			{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
			{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
			{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
			{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
			{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
			{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
			{'.', '.', '.', '.', '8', '.', '.', '7', '9'}
	};
	if (sol.isValidSudoku(board)) {
		cout << "true;" << endl;
	}
	else {
		cout << "false" << endl;
	}

	cin.get();
	return 0;
}