#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<functional>

using namespace std;

//prblem 1:
class Solution1 {
public:
	bool canMakeArithmeticProgression(vector<int>& arr) {
		std::sort(arr.begin(), arr.end());
		int gap = arr[0] - arr[1];
		bool flag = true;
		for (int idx = 1; idx + 1<arr.size(); ++idx) {
			if (arr[idx] - arr[idx + 1] != gap) {
				flag = false;
				break;
			}
		}
		return flag;
	}
};

// problem 2:
// Intuition
// When two ants meet at some point,
// they change their directions and continue moving again.
// But you can assume they don't change direction and keep moving.
// (You don't really know the difference of ants between one and the other, do you?)
//	For ants in direction of left, the leaving time is left[i]
//	For ants in direction of right, the leaving time is n - right[i]
// Complexity:	Time O(N),	Space O(1)
class Solution2 {
public:
	int getLastMoment(int n, vector<int>& left, vector<int>& right) {
		//caution: the vector may be empty;
		int last_left_in_left_dir_time = left.empty() ? 0 : *std::max_element(left.begin(), left.end());
		int last_left_in_right_dir_time = n - (right.empty() ? n: *std::max_element(right.begin(), right.end(), [&n](int rhs1, int rhs2) {
			return n - rhs1 < n - rhs2; }));
		return std::max(last_left_in_left_dir_time, last_left_in_right_dir_time);
	}
};

// problem 3: trying all heights row to row_next;
// calc all the possible rectangle matrix in rows;
// Time complexity: O(row*row*col); Space complexity:O(col);
class Solution3_1 {
	int m_result = 0;
public:
	int numSubmat(vector<vector<int>>& mat) {
		for (int row = 0; row < mat.size(); ++row) {
			//dp[i] indicate whether all element are 1 from row to row_next in i_th col;
			std::vector<int> dp(mat.front().size(), 1);
			for (int row_next = row; row_next < mat.size(); ++row_next) {
				for (int col = 0; col < dp.size(); ++col) {
					// indicate whether all elements are 1 in the col_th col;
					dp[col] &= mat[row_next][col];
				}
				calc_row(dp);
			}
		}
		return m_result;
	}
	//calc the current row of possible rectangle;
	void calc_row(const vector<int> & dp_row) {
		int pre_result = 0;
		for (int col = 0; col < dp_row.size(); ++col) {
			if (dp_row[col] == 1) {
				pre_result = pre_result + 1;
			}
			else {
				pre_result = 0;
			}
			m_result += pre_result;
		}
	}
};
//class Solution {
//public:
//	int numSubmat(vector<vector<int>>& mat) {
//		std::vector<std::vector<std::vector<int>>> dp(mat.size(), 
//			std::vector<std::vector<int>>(mat.front.size(), std::vector<int>(3,0)));
//		int result = 0;
//		for (int row = 0; row < mat.size(); ++row) {
//			for (int col = 0; col < mat.front().size(); ++col) {
//				if (row == 0 && col == 0) {
//					if (mat[row][col] == 1) {
//						dp[row][col][0] = 1;
//						dp[row][col][1] = 1;
//						dp[row][col][2] = 1;
//					}
//				}
//				if (row == 0) {
//					if (mat[row][col] == 1) {
//						dp[row][col][0] = 1+dp[row][col-1][0];
//						dp[row][col][1] = 1;
//						dp[row][col][2] = dp[row][col][0];
//					}
//				}
//				else if (col == 0) {
//					if (mat[row][col] == 1) {
//						dp[row][col][0] = 1;
//						dp[row][col][1] = 1+dp[row-1][col][1];
//						dp[row][col][2] = dp[row][col][1];
//					}
//				}
//				else {
//					if (mat[row][col] == 1) {
//						dp[row][col][0] = 1 + dp[row][col - 1][0];
//						dp[row][col][1] = 1 + dp[row - 1][col][1];
//						dp[row][col][2]=
//					}
//				}
//			}
//		}
//
//	}
//};


int main() {
	Solution2 sol;
	std::vector<int> left,right={ 0, 1, 2, 3, 4, 5, 6, 7 };
	int n = 7;
	std::cout << sol.getLastMoment(n, left, right);
	cin.get();
	return 0;
}



int main() {
	int n=5;
	std::vector<int> next{ 2,4,2,3,1 };
	std::cout << calc(n,next) << std::endl;
	std::cin.get();
	//while (cin >> n) {
	//	while (n>0) {
	//		int temp; cin >> temp;
	//		next.emplace_back(temp);
	//		--n;
	//	}
	//	std::cout << calc(n, next) << std::endl;
	//}

}