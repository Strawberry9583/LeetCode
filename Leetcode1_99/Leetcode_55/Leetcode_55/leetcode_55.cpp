#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		//record the successive reached idx with further and next_furthest;
		int furthest = 0;
		int next_furthest = nums[0];
		while (furthest<next_furthest && next_furthest<nums.size()-1) {
			int temp_distance =furthest;
			for (int idx = furthest + 1; idx <= next_furthest; ++idx) {
				if (idx + nums[idx] > temp_distance) {
					temp_distance = idx + nums[idx];
				}
			}
			furthest = next_furthest;
			next_furthest = temp_distance;
		}
		//can reach the end;
		if (next_furthest >= nums.size() - 1) {
			return true;
		}
		//can not reach the end, in the case that the furthest==next_furthest;
		else {
			return false;
		}
		
	}
};

int main() {
	Solution sol;
	std::cout << sol.canJump(std::vector<int>{2, 3, 1, 1, 4});
	std::cin.get();
	return 0;
}