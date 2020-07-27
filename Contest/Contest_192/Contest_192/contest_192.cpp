#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>

using namespace std;


class Solution1 {
public:
	vector<int> getStrongest(vector<int>& arr, int k) {
		std::nth_element(arr.begin(), arr.begin() + arr.size() / 2, arr.end());
		int median =arr[(arr.size()-1) / 2];
		std::nth_element(arr.begin(), arr.begin() + k, arr.end(), [median](const int & rhs1, const int &rhs2)
		{return abs(rhs1 - median) == abs(rhs2 - median) ? rhs1 > rhs2:abs(rhs1 - median) > abs(rhs2 - median); });
		std::vector<int>result; result.reserve(k);
		for (int idx = 0; idx < k; ++idx) {
			result.emplace_back(arr[idx]);
		}
		return result;
	}
};

class Solution {
public:
	vector<int> getStrongest(vector<int>& arr, int k) {
		std::partial_sort(arr.begin(), arr.begin() + arr.size() / 2, arr.end());
		int median = arr[(arr.size() - 1) / 2];
		std::partial_sort(arr.begin(), arr.begin() + k, arr.end(), [median](const int & rhs1, const int &rhs2)
		{return abs(rhs1 - median) == abs(rhs2 - median) ? rhs1 > rhs2:abs(rhs1 - median) > abs(rhs2 - median); });
		std::vector<int>result; result.reserve(k);
		for (int idx = 0; idx < k; ++idx) {
			result.emplace_back(arr[idx]);
		}
		return result;
	}
};

int main() {
	Solution1 sol;
	std::vector<int> test_vec = { 6, 7, 11, 7, 6, 8 };
	int k=5;
	auto ans = sol.getStrongest(test_vec, k);
	for (auto &ele : ans) {
		std::cout << ele << " ";
	}
	cin.get();
	return 0;
}