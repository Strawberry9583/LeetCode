#include<iostream>
#include<bitset>
#include<vector>
#include<algorithm>
using namespace std;

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
			dp[i] = std::max(dp[i - 1] + nums[i], nums[i]);
		}
		return *std::max_element(dp.begin(), dp.end());
	}
};

//DC method to solve;
class Solution2 {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.size() == 1) {
			return nums[0];
		}
		return max_subsequence(nums, 0, nums.size() - 1);
	}
	int max_subsequence(std::vector<int>& nums, int left, int right) {
		if (left == right) {
			return nums[left];
		}
		//calc Maximum subarray sum such that the subarray crosses the midpoint;
		int mid = left + ((right - left) / 2);
		int sum_left_cur = 0;
		int sum_left_max = std::numeric_limits<int>::min();
		//calc the [left,mid] max_subsequence;
		for (int idx = mid; idx >= left; --idx) {
			sum_left_cur += nums[idx];
			if (sum_left_max < sum_left_cur) {
				sum_left_max = sum_left_cur;
			}
		}
		int sum_right_cur = 0;
		int sum_right_max = std::numeric_limits<int>::min();
		//calc the (mid,right] max_subsequence;
		for (int idx = mid + 1; idx <= right; ++idx) {
			sum_right_cur += nums[idx];
			if (sum_right_max < sum_right_cur) {
				sum_right_max = sum_right_cur;
			}
		}
		int sum_cross = sum_right_max + sum_left_max;
		//Return maximum of following three possible cases
		//	a) Maximum subarray sum in left half
		//	b) Maximum subarray sum in right half
		//	c) Maximum subarray sum such that the subarray crosses the midpoint
		return std::max({ max_subsequence(nums, left, mid), max_subsequence(nums, mid + 1, right),sum_cross });
	}
};

int main() {


	std::cin.get();
	return 0;
}