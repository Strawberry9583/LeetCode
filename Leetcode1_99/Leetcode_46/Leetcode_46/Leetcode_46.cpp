#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		std::vector<std::vector<int>> result;

		get_permutation(result, nums,0);
		return result;
	}
	void get_permutation(vector<vector<int>>& result, vector<int> & nums,int start) {
		if (start == nums.size() - 1) {
			result.emplace_back(nums);
			return;
		}
		for (int i = start; i < nums.size(); ++i) {
			int temp = nums[start];
			nums[start] = nums[i];
			nums[i] = temp;
			get_permutation(result, nums,start + 1);
			temp = nums[start];
			nums[start] = nums[i];
			nums[i] = temp;
		}
	}
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


int main() {
	Solution sol;
	std::vector<int> vec = { 1,1,2 };
	sol.permuteUnique(vec);
	std::cin.get();
	return 0;
}