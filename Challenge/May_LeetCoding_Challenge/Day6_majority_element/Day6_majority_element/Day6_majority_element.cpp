#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int times = 1, pre = nums.front();
		for (int idx = 1; idx < nums.size(); ++idx) {
			if (nums[idx] == pre) {
				++times;
			}
			else {
				--times;
			}
			if (times < 0) {
				pre = nums[idx];
				times = 1;
			}
		}
		return pre;
	}
};

int main() {
	std::vector<int> test_vec{ 10,9,9,9,10};
	std::cout << Solution().majorityElement(test_vec);
	std::cin.get();
	return 0;
}