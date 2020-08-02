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


class Solution3 {
public:
	int minSwaps(vector<vector<int>>& grid) {
		std::vector<pair<int, int>> idx_zerolenght(grid.size(), std::pair<int, int>(0, 0));
		for (int row = 0; row < grid.size(); ++row) {
			int col = grid.size() - 1;
			for (; col >= 0; --col) {
				if (grid[row][col] == 1) {
					break;
				}
			}
			idx_zerolenght[row].first = row;
			idx_zerolenght[row].second = grid.size() - 1 - col;
		}
		std::vector<std::vector<int>> distance_matrix(grid.size(), std::vector<int>(grid.size(), 40001));
		for (int row_idx = 0; row_idx < grid.size()-1; ++row_idx) {
			int needed_zero = grid.size() - row_idx-1;
			for (int exchange_idx = 0; exchange_idx < grid.size(); ++exchange_idx) {
				if (idx_zerolenght[exchange_idx].second >= needed_zero) {
					distance_matrix[row_idx][exchange_idx] = 1;
				}
			}
		}


		//int size = grid.size();
		//int left = 0, right = (size*(size - 1) / 2)+1;
		//while (left<right) {
		//	int mid = left + (right - left) / 2;
		//	
		//}
	}
};

int main() {
	//std::vector<int> test_vec{ 1,25,35,42,68,70 };
	//int k = 2;
	//std::cout << Solution2().getWinner(test_vec, k);
	cin.get();
	return 0;
}