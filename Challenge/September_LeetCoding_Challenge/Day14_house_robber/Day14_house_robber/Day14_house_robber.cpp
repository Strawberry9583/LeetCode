#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}
		std::vector<pair<int, int>> dp(nums.size()+1);
		dp[1].first = nums[0];
		int result = nums[0];
		for (int idx = 2; idx <= nums.size(); ++idx) {
			dp[idx].first = nums[idx-1] + dp[idx - 1].second;
			dp[idx].second = std::max(dp[idx - 1].first, dp[idx - 1].second);
			result = std::max({ result,dp[idx].first,dp[idx].second });
		}
		return result;
	}
};


int main() {
	std::vector<int> nums{ 2,7,9,3,1};
	std::cout << Solution().rob(nums);
	cin.get();
	return 0;
}