#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;


class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (matrix.size() < 1) {
			return std::vector<int>();
		}
		//the [0,0] as the original points, then the following points can be constructed;
		vector<int> result(matrix.size()*matrix.begin()->size());
		std::pair<int, int>  right_top(0, matrix.begin()->size()-1), left_bottom(matrix.size()-1,0);
		int row = 0, col = 0;
		int insert_num = 0;
		int edge = 0;
		result[0] = matrix[0][0];
		while (insert_num<result.size()-1) {
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
					edge = 0	;
				}
			}
			++insert_num;
			result[insert_num] = matrix[row][col];
			
		}
		return result;
	}
};

int main() {
	std::vector<std::vector<int>> test{ {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
	//std::vector<std::vector<int>> test{ {1,2,3,4 }, { 5,6,7,8 }, { 9,10,11,12 }, { 13,14,15,16 }};
	//std::vector<std::vector<int>> test{ { 1,2,3 },{4, 5,6 },{ 7,8,9 } };
	auto ans = Solution().spiralOrder(test);
	for (auto &ele : ans) {
		std::cout << ele << " ";
	}

	std::cin.get();
	return 0;
}