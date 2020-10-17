#include<iostream>
#include<deque>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

// Binary search
// time complexity: O(n+lgm);
// space complexity: O(1);
class Solution1 {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix.front().empty()) {
			return false;
		}
		int first_ge = 0;
		for (first_ge = 0; first_ge < matrix.size(); ++first_ge) {
			if (matrix[first_ge].back() >= target) {
				break;
			}
		}
		auto ele = std::lower_bound(matrix[first_ge].begin(), matrix[first_ge].end(), target);
		if (ele != matrix[first_ge].end() && (*ele) == target) {
			return true;
		}
		return false;
	}
};

// binary search
// time complexity: O(lgm*n)=O(lgm+lgn);
// space complexity: O(1);
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m = matrix.size();
		if (m == 0) return false;
		int n = matrix[0].size();
		if (n == 0) return false;

		int l = 0, r = m * n - 1, mid;
		while (l < r) {
			mid = l + (r - l) / 2;
			if (matrix[mid / n][mid%n] == target) return true;
			if (matrix[mid / n][mid%n] > target) r = mid - 1;
			else l = mid + 1;
		}

		if (matrix[l / n][l%n] == target) return true;
		else return false;
	}
};




int main() {
	std::vector<std::vector<int>> test_matrix{ {1,3} };
	int target = 3;
	std::cout << Solution().searchMatrix(test_matrix, target);

	cin.get();
	return 0;
}

