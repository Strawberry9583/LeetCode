#include<vector>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int low = 1, high = nums.size();
		for (int idx = 0; idx < nums.size(); ++idx) {
			while (nums[idx]>=low&&nums[idx]<=high&&nums[nums[idx]-1]!=nums[idx]) {
				int temp = nums[nums[idx]-1];
				nums[nums[idx]-1] = nums[idx];
				nums[idx] = temp;
			}

		}
		for (int idx = 0; idx < nums.size(); ++idx) {
			if (nums[idx] != idx + 1) {
				return idx + 1;
			}
		}
		return high + 1;
	}
};

int main() {
	std::vector<int> nums{ 7,8,9,10,11,12 };
	std::cout << Solution().firstMissingPositive(nums);
	cin.get();
	return 0;
}