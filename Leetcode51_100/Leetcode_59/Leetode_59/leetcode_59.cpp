#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		std::vector<std::vector<int>> result(n, std::vector<int>(n, 0));
		int num = 1;
		int all_num = n*n;
		//record the rectangle area with left_bottom and right top points;
		std::pair<int, int> left_bottom(n - 1, 0);
		std::pair<int, int> right_top(0, n - 1);
		int row = 0, col = 0;
		//indicate four cases with top, right, bottom and left with 0,1,2,3;
		int edge = 0;
		while (num<=all_num) {
			result[row][col] = num;
			if (edge == 0) {
				if (col < right_top.second) {
					++col;
				}
				else {
					++right_top.first;
					row = right_top.first;
					edge = 1;
				}
			}
			else if (edge == 1) {
				if (row < left_bottom.first) {
					++row;
				}
				else {
					--right_top.second;
					col = right_top.second;
					edge = 2;
				}
			}
			else if (edge == 2) {
				if (col > left_bottom.second) {
					--col;
				}
				else {
					--left_bottom.first;
					row = left_bottom.first;
					edge = 3;
				}
			}
			else {
				if (row > right_top.first) {
					--row;
				}
				else {
					++left_bottom.second;
					col = left_bottom.second;
					edge = 0;
				}
			}
			++num;
		}
		return result;
	}
};

int main() {
	Solution sol;
	auto ans = sol.generateMatrix(3);
	std::cin.get();
	return 0;
}