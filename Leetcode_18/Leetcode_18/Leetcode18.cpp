//Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target ? Find all unique quadruplets in the array which gives the sum of target.
//
//Note :
//
//	The solution set must not contain duplicate quadruplets.
//
//	Example :
//
//	Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
//
//	A solution set is :
//[
//	[-1, 0, 0, 1],
//	[-2, -1, 1, 2],
//	[-2, 0, 0, 2]
//]

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;


class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int> > result;
		//the nums_size>=4;
		if (nums.size() < 4) {
			return result;
		}
		sort(nums.begin(), nums.end(), [](const int i1, const int i2) {return i1 < i2; });
		for (int i = 0; i < nums.size() - 3; ++i) {
			vector<int> int_v(4);
			int_v[0] = nums[i];
			for (int j = i + 1; j < nums.size() - 2; ++j) {
				int_v[1] = nums[j];
				int rest_target = target - nums[i] - nums[j];
				int slow = j + 1, fast = nums.size() - 1;
				while (slow<fast){
					if (nums[slow] + nums[fast] == rest_target) {
						int_v[2] = nums[slow++];
						int_v[3] = nums[fast--];
						result.push_back(int_v);
						//filter the duplicate element;
						while (slow < fast&&nums[slow] == nums[slow - 1]) {
							++slow;
						}
						//filter the duplicate element;
						while (slow<fast&& nums[fast]==nums[fast+1]){
							--fast;
						}
					}
					//current number is bigger, so diminish;
					else if (nums[slow] + nums[fast] > rest_target) {
						--fast;
					}
					//current number is small, so largen;
					else {
						++slow;
					}
				}
				//filter the duplicate element;
				while (j<nums.size()-2&&nums[j]==nums[j+1]) {
					++j;
				}
			}
			//filter the duplicate element;
			while (i<nums.size()-1&& nums[i]==nums[i+1]) {
				++i;
			}
		}
		return result;
	}
};



int main() {

	Solution sol;
	vector<int> test = { 1, 0, -1, 0, -2, 2 };
	vector<vector<int> > result = sol.fourSum(test, 0);
	for (auto & i : result) {
		for (auto & j : i) {
			cout << j << " ";
		}
		cout << endl;
	}

	cin.get();
	return 0;
}