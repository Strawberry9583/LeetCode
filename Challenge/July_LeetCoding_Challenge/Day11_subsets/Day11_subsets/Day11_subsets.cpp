#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<bitset>
#include<list>

using namespace std;


// subset problem;
// solution 1: cascading 
// start from empty subset in output list. At each step
// one takes new integer into consideration and generates new subsets from the existing ones.
class Solution1_1 {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		// use list to avoid vector to grow, wasting computation;
		std::list<std::vector<int>> result; result.emplace_back(std::vector<int>());
		for (auto & ele : nums) {
			int cur_size = result.size();
			auto begin = result.begin();
			for (int idx = 0; idx < cur_size; ++idx) {
				auto temp = (*begin); temp.emplace_back(ele);
				++begin;
				result.emplace_back(std::move(temp));
			}
		}
		// transfer the list into vector;
		std::vector<std::vector<int>>ans(result.size(), vector<int>());
		int idx = 0;
		for (auto & ele : result) { ans[idx++] = std::move(ele); }
		return ans;
	}
};

// solutin2: backtracking
// find all possible combinations of all possible lengths, from 0 to n.
class Solution1_2 {
	std::vector<std::vector<int>> result;
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		for (int length = 0; length < nums.size() + 1; ++length) {
			std::vector<int> temp;
			dfs(length,temp,0,nums);
		}
		return result;
	}
	// find the subset of size==lenght;
	void dfs(int length, std::vector<int> & cur_set,int start,std::vector<int> & all_nums) {
		if (length == cur_set.size()) {
			result.emplace_back(cur_set);
			return;
		}
		for (int idx = start; idx < all_nums.size(); ++idx) {
			cur_set.emplace_back(all_nums[idx]);
			dfs(length, cur_set, idx+1, all_nums);
			cur_set.pop_back();
		}
	}
};

// solution3: Lexicographic (Binary Sorted) Subsets
// The idea is that we map each subset to a bitmask of length n, 
// where 1 on the ith position in bitmask means the presence of nums[i] in the subset, 
// and 0 means its absence.
class Solution1_3 {
	std::vector<std::vector<int>> result;
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		int total_num = std::pow(2, nums.size());
		for (int cur_idx = 0; cur_idx < total_num; ++cur_idx) {
			int num = cur_idx;
			std::vector<int>cur_set;
			for (int idx = 0; idx < nums.size(); ++idx) {
				if (num % 2) {
					cur_set.emplace_back(nums[idx]);
				}
				num = num / 2;
			}
			result.emplace_back(std::move(cur_set));
		}
		return result;
	}
};


// subset problem II (with duplicates)
// solutin1: backtracking (similar to solution1_2 but jump the duplicate elements)
// find all possible combinations of all possible lengths, from 0 to n.
class Solution {
	std::vector<std::vector<int>> result;
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		std::sort(nums.begin(), nums.end());
		for (int length = 0; length < nums.size() + 1; ++length) {
			std::vector<int> temp;
			dfs(length, temp, 0, nums);
		}
		return result;
	}
	// find the subset of size==lenght;
	void dfs(int length, std::vector<int> & cur_set, int start, std::vector<int> & all_nums) {
		if (length == cur_set.size()) {
			result.emplace_back(cur_set);
			return;
		}
		for (int idx = start; idx < all_nums.size(); ) {
			cur_set.emplace_back(all_nums[idx]);
			dfs(length, cur_set, idx + 1, all_nums);
			cur_set.pop_back();
			int pre_idx = idx;
			//jump the duplicates;
			while (idx<all_nums.size() && all_nums[pre_idx] == all_nums[idx]) {
				++idx;
			}
		}
	}
};

int main() {
	//std::vector<int> test_vec{ 1,2,2 };
	//auto ans=Solution().subsets(test_vec);
	cin.get();
	return 0;
}