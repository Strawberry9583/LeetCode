#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

// dp[i] indicates that the maximum and minimum value ended with the nums[i];
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		if (nums.empty()) {
			return 0;
		}
		std::vector<std::pair<int, int>> dp(nums.size(), { 0,0 });
		if (nums.front() < 0) {
			dp[0].second = nums.front();
		}
		else {
			dp[0].first = nums.front();
		}
		int max_pro = nums.front();
		for (int idx = 1; idx < dp.size(); ++idx) {
			if (nums[idx] > 0) {
				dp[idx].first = std::max(nums[idx]*dp[idx - 1].first, nums[idx]);
				dp[idx].second = nums[idx] * dp[idx-1].second;
			}
			else if(nums[idx]<0){
				dp[idx].first = nums[idx] * dp[idx - 1].second;
				dp[idx].second = std::min(dp[idx - 1].first*nums[idx], nums[idx]);
			}
			if (dp[idx].first > max_pro) {
				max_pro = dp[idx].first;
			}
		}
		return max_pro;
	}
};

int main() {

	std::vector<int> vec{ -2,3,-4 };
	std::cout << Solution().maxProduct(vec);
	cin.get();
	return 0;
}