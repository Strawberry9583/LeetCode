#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int furthest = 0;
		int next_furthest = nums[0];
		while (furthest<next_furthest && next_furthest<nums.size() - 1) {
			int temp_distance = furthest;
			for (int idx = furthest + 1; idx <= next_furthest; ++idx) {
				if (idx + nums[idx] > temp_distance) {
					temp_distance = idx + nums[idx];
				}
			}
			furthest = next_furthest;
			next_furthest = temp_distance;
		}
		if (next_furthest >= nums.size() - 1) {
			return true;
		}
		else {
			return false;
		}

	}
};

int main() {

	std::cin.get();
	return 0;
}