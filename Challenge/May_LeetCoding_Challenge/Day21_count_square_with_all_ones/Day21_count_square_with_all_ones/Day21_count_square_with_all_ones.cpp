#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

// solution 1: use DP to find the largest possible square edge of all points;
// Time complexity: O(n*n); Space complexity: O(n*n);
// solution 2: similar to solution1, however the rolling array can be used to reduce the 
// the space complexity to O(n). The dp[i][j] is only related to the dp of (i-1)th row  
// and dp[i][j-1];
class Solution {
public:
	int countSquares(vector<vector<int>>& matrix) {
		//ios::sync_with_stdio(false); cin.tie(0); 
		//dp[i][j] indicates the largest edge of [i,j] serving as the right bottom point of the square;
		std::vector<std::vector<int>> dp(matrix.size(), std::vector<int>(matrix[0].size(), 0));
		for (int row = 0; row < matrix.size(); ++row) {
			for (int col = 0; col < matrix[0].size(); ++col) {
				if (row == 0|| col==0) {
					dp[row][col] = matrix[row][col] == 1 ? 1 : 0;
				}
				else{
					if (matrix[row][col] == 1) {
						dp[row][col] = std::min({ dp[row - 1][col - 1],dp[row - 1][col],dp[row][col - 1] })+1;
					}
				}
			}
		}
		//sum up all the possible solution;
		int result = 0;
		for (auto & row : dp) {
			for (auto & ele : row) {
				result += ele;
			}
		}
		return result;
	}
};

int main() {
	Solution sol;
	std::vector<std::vector<int>>test_vec = { {0,1,1,1},{1,1,1,1},{0,1,1,1} };
	std::cout << sol.countSquares(test_vec);
	cin.get();
	return 0;
}