#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int zero_idx = 0;
		for (int idx = 0; idx<nums.size(); ++idx) {
			if (nums[idx] != 0) {
				if (idx != zero_idx) {
					std::swap(nums[idx], nums[zero_idx]);
				}
				++zero_idx;
			}
		}
		for (int idx = zero_idx; idx<nums.size(); ++idx) {
			nums[idx] = 0;
		}
	}
};

int main() {
	Solution sol;
	sol.moveZeroes(std::vector<int>({0,1}));


	std::cin.get();
	return 0;
}