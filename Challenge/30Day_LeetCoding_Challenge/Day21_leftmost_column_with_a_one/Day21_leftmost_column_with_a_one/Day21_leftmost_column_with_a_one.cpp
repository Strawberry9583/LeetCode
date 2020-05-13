#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


/**
* // This is the BinaryMatrix's API interface.
* // You should not implement it, or speculate about its implementation
* class BinaryMatrix {
*   public:
*     int get(int x, int y);
*     vector<int> dimensions();
* };
*/

class BinaryMatrix {
public:
	int get(int x, int y);
	vector<int> dimensions();
};


class Solution {
public:
	int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
		int result=std::numeric_limits<int>::max();
		for (int row = 0; row < binaryMatrix.dimensions().front(); ++row) {
			int temp = find_one(row, binaryMatrix);
			if (temp !=-1&&temp<result) {
				result = temp;
			}
		}
		return (result==std::numeric_limits<int>::max())?-1:result;
	}
	int find_one(int row, BinaryMatrix & matrix) {
		int left = 0, right = matrix.dimensions().back();
		while (left<right) {
			int mid = left + (right - left) / 2;
			if (matrix.get(row, mid) == 1) {
				right = mid ;
			}
			else {
				left = mid + 1;
			}
		}
		if (left == matrix.dimensions().back()) {
			return -1;
		}
		else {
			return left;
		}
	}
};
//solution 1: transfer to the bianry search; time complexity: O(n*logm)
class Solution1 {
public:
	int leftMostColumnWithOne(std::vector<std::vector<int>> &binaryMatrix) {
		int result = std::numeric_limits<int>::max();
		for (int row = 0; row < binaryMatrix.size(); ++row) {
			int temp = find_one(row, binaryMatrix);
			if (temp != -1 && temp<result) {
				result = temp;
			}
		}
		return (result == std::numeric_limits<int>::max()) ? -1 : result;
	}
	int find_one(int row, std::vector<std::vector<int>> &matrix) {
		int left = 0, right = matrix.front().size();
		while (left<right) {
			int mid = left + (right - left) / 2;
			if (matrix[row][mid] == 1) {
				right = mid;
			}
			else {
				left = mid + 1;
			}
		}
		if (left== matrix.front().size()) {
			return -1;
		}
		else {
			return left;
		}
	}
};

//optimal solution; worst time complexity: O(m+n);
//2. (Optimal Approach) Imagine there is a pointer p(x, y),
//starting from top right corner.p can only move left or down.
//If the value at p is 0, move down.If the value at p is 1, move left.
//Try to figure out the correctness and time complexity of this algorithm.
int main() {
	Solution1 sol;
	std::vector<std::vector<int>> testvec{ {0, 0}, {0, 1} };
	std::cout<<sol.leftMostColumnWithOne(testvec);
	std::cin.get();
	return 0;
}