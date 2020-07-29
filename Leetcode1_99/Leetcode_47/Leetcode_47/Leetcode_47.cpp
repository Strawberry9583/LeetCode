#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		std::set<std::vector<int>> result;
		std::vector<std::vector<int>> ans;
		get_unique_permutation(result, nums, 0);
		for (auto & _ele : result) {
			ans.emplace_back(std::move(_ele));
		}
		return ans;
	}
	void get_unique_permutation(std::set<std::vector<int>> & result, std::vector<int> nums, int start) {
		if (start == nums.size() - 1) {
			result.insert(nums);
			return;
		}
		for (int i = start; i < nums.size(); ++i) {
			int temp = nums[start];
			nums[start] = nums[i];
			nums[i] = temp;
			get_unique_permutation(result, nums, start + 1);
			temp = nums[start];
			nums[start] = nums[i];
			nums[i] = temp;
		}
	}
};

class Solution2 {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> vec;
		do {
			vector<int> v = nums;
			vec.push_back(v);
		} while (next_permutation(nums.begin(), nums.end()));

		return vec;
	}
};


int main() {
	Solution sol;
	std::vector<int> vec = { 1,1,2 };
	sol.permuteUnique(vec);
	std::cin.get();
	return 0;
}