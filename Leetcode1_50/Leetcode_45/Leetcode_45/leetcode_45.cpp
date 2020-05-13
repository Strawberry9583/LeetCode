#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution1 {
public:
	int jump(vector<int>& nums) {
		if (nums.size() == 1) {
			return 0;
		}
		int max_reach = 0;
		int last_max_reach = 0;
		int jump_num=0;
		//each loop increas a jump num;
		//calc the max jump distance with certain jump times;
		while (max_reach<nums.size()-1) {
			++jump_num;
			int new_max_reach = std::numeric_limits<int>::lowest();
			//recalc the updated max reach stairs from the last max-reached position;
			for (int stair = last_max_reach; stair <= max_reach; ++stair) {
				new_max_reach = std::max(new_max_reach, stair + nums[stair]);
			}
			last_max_reach = max_reach;
			max_reach = std::max(new_max_reach, max_reach);
		}
		return jump_num;
	}
};


class Solution {
public:
	int jump(vector<int>& nums) {
		if (nums.size() == 1) {
			return 0;
		}
		int max_reach = 0;
		int last_max_reach = 0;
		int jump_num = 0;
		std::vector<int> reach;
		//each loop increas a jump num;
		//calc the max jump distance with certain jump times;
		while (max_reach<nums.size() - 1) {
			++jump_num;
			int new_max_reach = std::numeric_limits<int>::lowest();
			//recalc the updated max reach stairs from the last max-reached position;
			for (int stair = last_max_reach; stair <= max_reach; ++stair) {
				if (stair + nums[stair]>new_max_reach) {
					new_max_reach = stair + nums[stair];
				}
			}
			last_max_reach = max_reach;
			max_reach = new_max_reach;
			//max_reach = std::max(new_max_reach, max_reach);
		}
		return jump_num;
	}
};

int main() {
	Solution sol;
	std::vector<int> test{ 2,3,1,1,4 };
	std::cout << sol.jump(test);
	std::cin.get();
	return 0;
}