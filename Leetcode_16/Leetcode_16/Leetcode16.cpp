/*Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target.Return the sum of the three integers.You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).*/


#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end(), [](int i1, int i2) {return i1 < i2; });
		int result = nums[0] + nums[1] + nums[2];
		for (int i = 0; i < nums.size()-2; ++i)
		{
			int front = i + 1, back = nums.size() - 1;
			while (front<back)
			{
				int total = nums[i] + nums[front] + nums[back];
				if (abs(total-target)<abs(result-target))
				{
					result = total;
				}
				if (total > target)
				{
					--back;
				}
				else if (total<target)
				{
					++front;
				}
				if (total==target)
				{
					return total;
				}
			}
		}
		return result;

	}
};


int main()
{
	Solution sol;
	vector<int> temp = { -1, 2, 1, -4 };
	cout<<sol.threeSumClosest(temp,1);
	cin.get();
	return 0;
}