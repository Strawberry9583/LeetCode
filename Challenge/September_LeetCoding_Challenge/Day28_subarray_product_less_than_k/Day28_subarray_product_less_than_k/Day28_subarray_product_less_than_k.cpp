#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// for every idx find the left_bound that [left_bound,idx]<k;
// then calc all the idx and sum the numbers;
// meanwhile the max_window maintained with products less than k;
class Solution {
public:
	int numSubarrayProductLessThanK(vector<int>& nums, int k) {
		if (k <= 1) return 0;
		int n = nums.size(), prod = 1, ans = 0, left = 0;
		for (int i = 0; i < n; i++) {
			prod *= nums[i];
			while (prod >= k) prod /= nums[left++];
			ans += i - left + 1;
		}
		return ans;
	}
};

int main() {
	std::vector<int> nums{10, 9, 10, 4, 3, 8, 3, 3, 6, 2, 10, 10, 9, 3};
	int k = 19;
	std::cout << Solution().numSubarrayProductLessThanK(nums, k);
	cin.get();
	return 0;
}