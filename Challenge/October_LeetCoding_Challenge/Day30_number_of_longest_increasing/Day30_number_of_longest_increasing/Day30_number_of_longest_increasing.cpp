#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

// method1: dp
// dp[i] indicates max_length when the sequncen ends up with nums[i];
// max_length_num[i] indicates the max_length number of the longest increasing subsequence when
// end up with nums[i];
// time complexity: O(n*n); space complexity: O(n);
class Solution {
public:
	int findNumberOfLIS(vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}
		// dp[i] indicates max_length when the sequncen ends up with nums[i];
		std::vector<int> dp(nums.size(), 0);
		// max_length_num[i] indicates the max_length number of the longest increasing subsequence when
		// end up with nums[i];
		std::vector<int> max_length_num(nums.size(), 0);
		dp[0] = 1;
		max_length_num[0] = 1;
		int result = 1;
		int max_length = 1;
		if (nums.size() < 2) {
			return result;
		}
		for (int idx = 1; idx < nums.size(); ++idx) {
			int cur_max_length = 1;
			int cur_max_num = 1;
			for (int pre_idx = 0; pre_idx < idx; ++pre_idx) {
				if (nums[pre_idx] < nums[idx]) {
					int temp_length = dp[pre_idx] + 1;
					if (temp_length < cur_max_length) {
						continue;
					}
					else if (temp_length>cur_max_length) {
						cur_max_length = temp_length;
						cur_max_num = max_length_num[pre_idx];
					}
					else {
						cur_max_num += max_length_num[pre_idx];
					}
				}
			}
			dp[idx] = cur_max_length;
			max_length_num[idx] = cur_max_num;
			if (cur_max_length == max_length) {
				result += cur_max_num;
			}
			else if (cur_max_length < max_length) {

			}
			else if (cur_max_length > max_length) {
				result = cur_max_num;
				max_length = cur_max_length;
			}
		}
		return result;
	}
};


// method2: segment tree + dp;
// time complexity: O(n*lgn), space complexity: O(n);
// https://leetcode.com/problems/number-of-longest-increasing-subsequence/solution/



int main() {
	std::vector<int> vec_test{ 1,2,4,3,5,4,7,2};
	std::cout << Solution().findNumberOfLIS(vec_test);
	cin.get();
	return 0;
}