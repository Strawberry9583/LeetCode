#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<functional>
#include<algorithm>
#include<set>

using namespace std;


class Solution1 {
public:
	vector<int> finalPrices(vector<int>& prices) {
		std::vector<int> discount(prices.size(), 0);
		for (int idx = 0; idx < discount.size(); ++idx) {
			for (int idx1 = idx + 1; idx1 < discount.size(); ++idx1) {
				if (prices[idx1] <= prices[idx]) {
					discount[idx] = prices[idx1];
					break;
				}
			}
		}
		for (int idx = 0; idx < discount.size(); ++idx) {
			prices[idx] -= discount[idx];
		}
		return prices;
	}
};

class SubrectangleQueries {
	std::vector<std::vector<int>> m_data;
public:
	SubrectangleQueries(vector<vector<int>>& rectangle):m_data(rectangle) {
		
	}

	void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
		for (int idx = row1; idx <= row2; ++idx) {
			for (int idx1 = col1; idx1 <= col2; ++idx1) {
				m_data[idx][idx1] = newValue;
			}
		}
	}

	int getValue(int row, int col) {
		return m_data[row][col];
	}
};

// TLE
// firstly, find all range whose sum is target;
// then select the two  range  with minimization length;
class Solution3_1 {

public:
	int minSumOfLengths(vector<int>& arr, int target) {
		std::unordered_map<int, std::vector<int>> sum2idx;
		sum2idx[0].emplace_back(-1);
		std::set<std::vector<int>> gap_set;
		int sum = 0;
		for (int idx = 0; idx < arr.size(); ++idx) {
			sum += arr[idx];
			int find = sum - target;
			auto find_vec = sum2idx.find(find);
			if (find_vec != sum2idx.end()) {
				for (auto & idx_pre : find_vec->second) {
					gap_set.emplace(std::vector<int>{ idx_pre, idx });
				}
				gap_set.emplace(std::vector<int>{ find_vec->second.back(), idx });
			}
			sum2idx[sum].emplace_back(idx);
		}
		std::vector<std::vector<int>> gap_vec; gap_vec.reserve(gap_set.size());
		for (auto & ele : gap_set) {
			gap_vec.emplace_back(ele);
		}
		if (gap_vec.size() < 2) {
			return -1;
		}
		std::sort(gap_vec.begin(), gap_vec.end(), [](const vector<int>&rhs1, const vector<int> &rhs2)
		{return rhs1[1] - rhs1[0] < rhs2[1] - rhs2[0]; });
		for (int back_idx = 1; back_idx < gap_vec.size(); ++back_idx) {
			for (int front_idx = 0; front_idx < back_idx; ++front_idx) {
				if (gap_vec[front_idx][1]<= gap_vec[back_idx][0] || gap_vec[back_idx][1] <= gap_vec[front_idx][0]) {
					return gap_vec[front_idx][1] - gap_vec[front_idx][0] + gap_vec[back_idx][1] - gap_vec[back_idx][0];
				}
			}
		}
		return -1;
	}
};


class Solution {

public:
	int minSumOfLengths(vector<int>& arr, int target) {
		ios::sync_with_stdio(false);
		cin.tie(0);
		std::unordered_map<int, int> sum2idx;
		sum2idx[0]=-1;
		std::vector<std::vector<int>> gap_set;
		int sum = 0;
		for (int idx = 0; idx < arr.size(); ++idx) {
			sum += arr[idx];
			int find = sum - target;
			auto find_idx = sum2idx.find(find);
			if (find_idx != sum2idx.end()) {
				gap_set.emplace_back(std::vector<int>{ find_idx->second, idx });
			}
			sum2idx[sum]=idx;
		}
		std::vector<std::vector<int>> gap_vec; gap_vec.reserve(gap_set.size());
		for (auto & ele : gap_set) {
			gap_vec.emplace_back(ele);
		}
		if (gap_vec.size() < 2) {
			return -1;
		}
		std::sort(gap_vec.begin(), gap_vec.end(), [](const vector<int>&rhs1, const vector<int> &rhs2)
		{return rhs1[1] - rhs1[0] < rhs2[1] - rhs2[0]; });
		for (int back_idx = 1; back_idx < gap_vec.size(); ++back_idx) {
			for (int front_idx = 0; front_idx < back_idx; ++front_idx) {
				if (gap_vec[front_idx][1] <= gap_vec[back_idx][0] || gap_vec[back_idx][1] <= gap_vec[front_idx][0]) {
					return gap_vec[front_idx][1] - gap_vec[front_idx][0] + gap_vec[back_idx][1] - gap_vec[back_idx][0];
				}
			}
		}
		return -1;
	}
};
int main() {
	std::vector<int> test_vec{ 7,3,4,7 };
	int target = 7;
	std::cout << Solution().minSumOfLengths(test_vec, target);
	cin.get();
	return 0;
}