#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//use every point with start points then check the square;
//hint: check the square with bfs;
//check sequence: 1-----> 1 1 ------> 1 1 1
//                        1 1         1 1 1
//                                    1 1 1
// following n is the size of matrix;
//time complexity: O(n^4)
//space complexity: O(1);
class Solution1 {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		int result = 0;
		for (int row = 0; row < matrix.size(); ++row) {
			for (int col = 0; col < matrix[row].size(); ++col) {
				if (matrix[row][col] == '1') {
					int temp = max_depth(matrix, row, col);
					if (result < temp) {
						result = temp;
					}
				}
			}
		}
		//return the area;
		return result*result;;
	}
	int max_depth(std::vector<std::vector<char>>& matrix, int row, int col) {
		int idx = 0;
		bool flag = true;
		for (idx = 0; row + idx < matrix.size() && col + idx < matrix.begin()->size(); ++idx) {
			int judge_num = (1 + idx) * 2 - 1;
			for (int judge_idx = 0; judge_idx < judge_num; ++judge_idx) {
				if (judge_idx <= idx) {
					if (matrix[row + idx][col+judge_idx] == '0') {
						flag = false;
						break;
					}
				}
				else {
					if (matrix[row+ 2 * idx - judge_idx][col + idx] == '0') {
						flag = false;
						break;
					}
				}
			}
			if (!flag) {
				break;
			}
		}
		return idx;
	}
};

//solution 2: 
//follow the previous, then prune the algorithm;
// following n is the size of matrix;
//time complexity: O(n^4)
//space complexity: O(1);
class Solution2 {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		int result = 0;
		for (int row = 0; row < matrix.size(); ++row) {
			for (int col = 0; col < matrix[row].size(); ++col) {
				//prune the algorithm: if the matrix exceeded, aborted;
				if (matrix[row][col] == '1' && row+result<matrix.size()
					&& col+result<matrix.begin()->size()) {
					int temp = max_depth(matrix, row, col);
					if (result < temp) {
						result = temp;
					}
				}
			}
		}
		return result*result;
	}
	int max_depth(std::vector<std::vector<char>>& matrix, int row, int col) {
		int idx = 0;
		bool flag = true;
		for (idx = 0; row + idx < matrix.size() && col + idx < matrix.begin()->size(); ++idx) {
			int judge_num = (1 + idx) * 2 - 1;
			for (int judge_idx = 0; judge_idx < judge_num; ++judge_idx) {
				if (judge_idx <= idx) {
					if (matrix[row + idx][col + judge_idx] == '0') {
						flag = false;
						break;
					}
				}
				else {
					if (matrix[row + 2 * idx - judge_idx][col + idx] == '0') {
						flag = false;
						break;
					}
				}
			}
			if (!flag) {
				break;
			}
		}
		return idx;
	}
};


//solution 3: DP:
//dp[i][j] indicate: with end point matrix[i][j], max edge of square is dp[i][j];
//time complexity: O(n^2);
//space complexity: O(n^2);
//Explanation links: https://leetcode.com/articles/maximal-square/ ;
class Solution{
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
		vector<vector<int>> dp(matrix.size(), std::vector<int>(matrix.begin()->size(),0));
		int ans = 0;
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[i].size(); j++) {
				if (matrix[i][j] == '1') {
					if (i > 0 && j > 0) {
						dp[i][j] = 1 + min({ dp[i - 1][j],
							dp[i][j - 1],
							dp[i - 1][j - 1] });
					}
					else {
						dp[i][j] = 1;
					}
					ans = max(ans, dp[i][j]);
				}
			}
		}
		return ans * ans;
	}
};

int main() {


	std::cin.get();
	return 0;
}