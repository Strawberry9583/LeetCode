#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		if (matrix.size() == 1) {
			return;
		}
		for (int row = 0; row < matrix.size()/2; ++row) {
			for (int col = row; row+col < matrix.size()-1; ++col) {
				int tmp = matrix[row][col];
				matrix[row][col] = matrix[matrix.size() - 1 - col][row];
				matrix[matrix.size() - 1 - col][row] = matrix[matrix.size() - 1 - row][matrix.size() - 1 - col];
				matrix[matrix.size() - 1 - row][matrix.size()- 1 - col] = matrix[col][matrix.size() - 1 - row];
				matrix[col][matrix.size() - 1 - row] = tmp;
			}
		}
	}
	//std::pair<int, int> get_idx(int row, int col, int matrix_size) {
	//	int shift_size = matrix_size / 2;
	//	int rotate_size = shift_size;
	//	if (matrix_size & 1 == 1) {
	//		rotate_size += 1;
	//	}
	//	if (row < rotate_size&&col < rotate_size) {
	//		return std::make_pair(col, matrix_size-1-row);
	//	}
	//	else if (row < rotate_size&&col >= rotate_size) {
	//		return std::make_pair(col, matrix_size - 1 - row);
	//	}
	//	else if (row >= rotate_size&&col >= rotate_size) {
	//		return std::make_pair(matrix_size - 1 - col, row);
	//	}
	//	else if(row>=rotate_size&&col<rotate_size){
	//		return std::make_pair(col, matrix_size-1-row);
	//	}
	//}
};

int main() {
	Solution sol;
	std::vector<std::vector<int>> test{
		{ 1,2,3},{4,5,6},{7,8,9} };
	sol.rotate(test);
	for (auto & ele : test) {
		for (auto & _ele : ele) {
			std::cout << _ele << "  ";
		}
		std::cout << endl;
	}
	std::cin.get();
	return 0;
}