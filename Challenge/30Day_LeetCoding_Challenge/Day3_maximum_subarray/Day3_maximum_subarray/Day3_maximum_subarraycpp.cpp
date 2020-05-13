#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.size() == 1) {
			return nums[0];
		}
		//dp indicate the max_sum of subarray in [0,i] with the last element of nums[i];
		std::vector<int> dp(nums.size());
		dp[0] = nums[0];
		for (int i = 1; i < nums.size(); ++i) {
			dp[i] = std::max(dp[i - 1] + nums[i], nums[i]);
		}
		return *std::max_element(dp.begin(), dp.end());
	}
};

class Solution1 {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.size() == 1) {
			return nums[0];
		}
		//dp indicate the max_sum of subarray in [0,i] with the last element of nums[i];
		std::vector<int> dp(nums.size());
		dp[0] = nums[0];
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i] >= 0) {
				dp[i] = dp[i - 1] + nums[i];
			}
			else {
				dp[i] = nums[i];
			}
			dp[i] = std::max(dp[i - 1] + nums[i], nums[i]);
		}
		return *std::max_element(dp.begin(), dp.end());
	}
};

class Solution2 {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.size() == 1) {
			return nums[0];
		}
		//dp_pre indicate the max_sum of subarray in [0,i] with the last element of nums[i];
		int dp_pre = nums[0];
		int max = dp_pre;
		for (int i = 1; i < nums.size(); ++i) {
			dp_pre = std::max(dp_pre + nums[i], nums[i]);
			if (dp_pre > max) {
				max = dp_pre;
			}
		}
		return max;
	}
};

//Use the DC to divide the problem into small ones.
class Solution3 {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.size() == 1) {
			return nums[0];
		}
		return max_subsequence(nums, 0, nums.size() - 1);
	}
	int max_subsequence( std::vector<int>& nums, int left, int right) {
		if (left == right) {
			return nums[left];
		}
		//calc Maximum subarray sum such that the subarray crosses the midpoint;
		int mid = left + ((right - left) / 2);
		int sum_left_cur = 0;
		int sum_left_max = std::numeric_limits<int>::min();
		//calc the [left,mid] max_subsequence;
		for (int idx = mid; idx >= left;--idx) {
			sum_left_cur += nums[idx];
			if (sum_left_max < sum_left_cur) {
				sum_left_max = sum_left_cur;
			}
		}
		int sum_right_cur = 0;
		int sum_right_max = std::numeric_limits<int>::min();
		//calc the (mid,right] max_subsequence;
		for (int idx = mid+1; idx <= right; ++idx) {
			sum_right_cur += nums[idx];
			if (sum_right_max < sum_right_cur) {
				sum_right_max=sum_right_cur;
			}
		}
		int sum_cross = sum_right_max + sum_left_max;
		//Return maximum of following three possible cases
		//	a) Maximum subarray sum in left half
		//	b) Maximum subarray sum in right half
		//	c) Maximum subarray sum such that the subarray crosses the midpoint
		return std::max({ max_subsequence(nums, left, mid), max_subsequence(nums, mid+1, right),sum_cross });
	}
};

int main() {
	Solution3 sol;
	std::vector<int> vec = { -2,1,-3,4,-1,2,1,-5,4 };
	std::cout << sol.maxSubArray(vec) << std::endl;
	std::cin.get();
	return 0;
}