#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<algorithm>
#include<functional>



using namespace std;


class Solution1 {
public:
	int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
		int i, j, k;
		int result = 0;
		for (i = 0; i < arr.size() - 2; ++i) {
			for (j = i + 1; j < arr.size() - 1; ++j) {
				for (k = j + 1; k < arr.size(); ++k) {
					if (abs(arr[i] - arr[j]) <= a&&abs(arr[j] - arr[k]) <= b&&abs(arr[i] - arr[k]) <= c) {
						++result;
					}
				}
			}
		}
		return result;
	}
};

class Solution2 {
public:
	int getWinner(vector<int>& arr, int k) {
		std::vector<int> cur_max(arr.size(), 0);
		int temp_max = arr.front(); cur_max[0] = arr.front();
		for (int idx = 1; idx < arr.size(); ++idx) {
			if (temp_max < arr[idx]) {
				temp_max = arr[idx];
			}
			cur_max[idx] = temp_max;
		}
		int result = 0;
		for (int idx = 0; idx < arr.size(); ++idx) {
			if (idx == 0) {
				int comp_idx = k;
				if (comp_idx >= arr.size()) {
					result = cur_max.back();
					break;
				}
				else if (arr[idx] == cur_max[k]) {
					result= arr[idx];
					break;
				}
			}
			else {
				int comp_idx = idx+k-1;
				if (comp_idx >= arr.size()) {
					result = cur_max.back();
					break;
				}
				else if (arr[idx] == cur_max[idx] && arr[idx] == cur_max[idx + k-1]) {
					result= arr[idx];
					break;
				}
			}
		}
		return result;
	}
};

// calc the number of zero in the leftmost of each rows;
// then find swap with row by row until find the row with enough leftmost zeros;
class Solution3 {
public:
	int minSwaps(vector<vector<int>>& grid) {
		std::vector<int> idx_zerolength(grid.size(), 0);
		for (int row = 0; row < grid.size(); ++row) {
			int col = grid.size() - 1;
			for (; col >= 0; --col) {
				if (grid[row][col] == 1) {
					break;
				}
			}
			idx_zerolength[row] = grid.size() - 1 - col;
		}
		int result = 0;
		for (int row_idx = 0; row_idx < grid.size() - 1; ++row_idx) {
			int needed_zero = grid.size() - row_idx - 1;
			int exchange_idx = row_idx + 1;
			for (; exchange_idx < grid.size()&& idx_zerolength[row_idx] < needed_zero; ++exchange_idx) {
				std::swap(idx_zerolength[row_idx], idx_zerolength[exchange_idx]);
				++result;
			}
			if (idx_zerolength[row_idx] < needed_zero) {
				result = -1;
				break;
			}

		}
		return result;
	}
};

int main() {
	//std::vector<int> test_vec{ 1,25,35,42,68,70 };
	//int k = 2;
	//std::cout << Solution2().getWinner(test_vec, k);

	std::vector<std::vector<int>> grid = {{0, 0, 1}, {1, 1, 0}, {1, 0, 0}};
	std::cout << Solution3().minSwaps(grid);

	cin.get();
	return 0;
}