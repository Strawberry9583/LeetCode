#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

class Solution1 {
public:
	int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
		int max_overlap = 0;
		for (int h_shift = -1*A.front().size(); h_shift <= (int)A.front().size(); ++h_shift) {
			for (int v_shift = -1*A.size(); v_shift <= (int)A.size(); ++v_shift) {
				int temp_overlap = overlap(A, B, h_shift, v_shift);
				if (temp_overlap > max_overlap) {
					max_overlap = temp_overlap;
				}
			}
		}
		return max_overlap;
	}
private:
	int overlap(std::vector < std::vector<int>>& A, std::vector<std::vector<int>> & B, int h_shift, int v_shift) {
		int ans = 0;
		for (int row = 0; row+v_shift>=0&&row + v_shift<(int)A.size()&& row < A.size(); ++row) {
			for (int col = 0;col+h_shift>=0&& col + h_shift<(int)A.front().size()&& col < A.front().size(); ++col) {
				int shift_row = row + v_shift;
				int shift_col = col + h_shift;
				if (A[row][col] == B[shift_row][shift_col] && A[row][col] == 1) {
					++ans;
				}
			}
		}
		return ans;
	}
};
//
//O(N ^ 4) solution
//Let B[0][0] always be in position x = 0, y = 0.
//In order to move A, A[0][0]'s position can be from x = 1-n, y = 1-n to x = n-1, y = n-1. This is the first and the second loop.
//the third and the forth loops calculate the actual overlap.
class Solution {
public:
	int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
		if (A.empty() || A[0].empty()) {
			return 0;
		}

		int n = A.size();
		int res = 0;
		for (int i = 1 - n; i <= n - 1; i++) {
			for (int j = 1 - n; j <= n - 1; j++) {
				int cur = 0;
				for (int k = max(i, 0); k < min(i + n, n); k++) {
					for (int l = max(j, 0); l < min(j + n, n); l++) {
						if (A[k - i][l - j] == 1 && B[k][l] == 1) {
							cur++;
						}
					}
				}
				res = max(res, cur);
			}
		}
		return res;
	}
};

int main() {
	std::vector<std::vector<int>> A = { {1, 1, 0},
		{0, 1, 0},
		{0, 1, 0} },
		B = { {0, 0, 0},
		{0, 1, 1},
		{0, 0, 1} };
	std::cout << Solution().largestOverlap(A, B);
	cin.get();
	return 0;
}