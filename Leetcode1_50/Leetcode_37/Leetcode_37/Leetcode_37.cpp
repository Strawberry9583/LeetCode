/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
Empty cells are indicated by the character '.'.

Note:

The given board contain only digits 1-9 and the character '.'.
You may assume that the given Sudoku puzzle will have a single unique solution.
The given board size is always 9x9.

*/


#include<iostream>
#include<vector>
#include<set>


using namespace std;



class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		//get the flag of num used for every small rec, every row and every col;
		vector<vector<bool>> rec_flag(9, vector<bool>(9, false));
		vector<vector<bool>> row_flag(9, vector<bool>(9, false));
		vector<vector<bool>> col_flag(9, vector<bool>(9, false));
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] != '.') {
					int num = board[i][j] - 49;
					int rec_idx = (i / 3) * 3 + j / 3;
					rec_flag[rec_idx][num] = true;
					row_flag[i][num] = true;
					col_flag[j][num] = true;
				}
			}
		}
		getSudokuResult(board, rec_flag, row_flag, col_flag, 0);
	}
	bool  getSudokuResult(vector<vector<char>> & cur_board, vector<vector<bool>> & rec_flag, vector<vector<bool>> & row_flag,
		vector<vector<bool>> & col_flag, int  fill_idx) {
		if (fill_idx == 81) {
			return true;
		}
		//calc the row(i) and(j) col of the element;
		int i = fill_idx / 9;
		int j = fill_idx % 9;
		if (cur_board[i][j] == '.') {
			for (int k = 0; k < 9; ++k) {
				int num = k + 1;
				int rec_idx = (i / 3) * 3 + j / 3;
				if (col_flag[j][num - 1] || rec_flag[rec_idx][num - 1] || row_flag[i][num - 1]) {
					continue;
				}
				else {
					rec_flag[rec_idx][num - 1] = true;
					row_flag[i][num - 1] = true;
					col_flag[j][num - 1] = true;
					cur_board[i][j] = num + 48;

					if (getSudokuResult(cur_board, rec_flag, row_flag, col_flag, fill_idx+1)) {
						return true;
					}
					else {
						rec_flag[rec_idx][num - 1] = false;
						row_flag[i][num - 1] = false;
						col_flag[j][num - 1] = false;
						cur_board[i][j] = '.';
					}
				}
			}
			return false;
		}
		return getSudokuResult(cur_board, rec_flag, row_flag, col_flag, fill_idx+1);
	}
};


int main() {
	Solution sol;
	vector<vector<char>> board= {
		    {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
			{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
			{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
			{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
			{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
			{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
			{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
			{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
			{'.', '.', '.', '.', '8', '.', '.', '7', '9'}
	};
	sol.solveSudoku(board);
	for (const auto & i : board) {
		for (const auto & j : i) {
			std::cout << j << " ";
		}
		std::cout << endl;
	}


	cin.get();
	return 0;
}