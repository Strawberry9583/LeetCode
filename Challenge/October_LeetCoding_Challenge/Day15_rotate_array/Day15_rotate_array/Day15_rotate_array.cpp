#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

// solution1: move the element from the first element, until meet the first element; then begin the next round to move elements;
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		k %= nums.size();
		if (nums.empty()||k<1) {
			return;
		}
		int idx = 0;
		int cur_idx = k;
		int begin_idx = 0;
		int pre_num = nums[0];
		while (idx<nums.size()) {
			if (cur_idx == begin_idx) {
				nums[cur_idx] = pre_num;
				pre_num = nums[cur_idx + 1];
				++cur_idx;
			}
			else {
				int temp = nums[cur_idx];
				nums[cur_idx] = pre_num;
				pre_num = temp;

			}
			cur_idx += k;
			cur_idx %= nums.size();
			++idx;
		}
	}
};

int main() {
	std::vector<int> test_vec{ 1};
	int k = 1;
	Solution().rotate(test_vec, k);
	for (auto & ele : test_vec) {
		std::cout << ele << " " << std::endl;
	}
	cin.get();
	return 0;
}