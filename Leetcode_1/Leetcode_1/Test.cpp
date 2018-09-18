/*1. Two Sum  QuestionEditorial Solution  My Submissions
Total Accepted: 306324
Total Submissions: 1138858
Difficulty: Easy
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
UPDATE (2016/2/13):
The return format had been changed to zero-based indices. Please read the above updated description carefully.*/




#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>



using namespace std;



class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		map<int, int> maps;
		vector<int> result(2);
		for (int i = 0; i < nums.size(); ++i)
		{
			//Key......Key......Key......Key.....
			//if you check first,you will avoid the situation 
			//where the add of same number is the result; 
			if (maps.count(target - nums[i]))
			{
				result[1] = i;
				result[0] = maps[target - nums[i]];
				break;
			}
			//no nums[i] in maps,then insert into the maps;
			if (maps.count(nums[i]) == 0)
			{
				maps.insert(pair<int,int>(nums[i], i));
			}

		}

		return result;
	}
};


int main()
{
	vector<int> nums = { 2,0,0,4 };
	int target = 0;
	Solution so;
	vector<int>result = so.twoSum(nums, target);
	for (auto rhs : result)
	{
		cout << rhs << endl;
	}
	getchar();
	return 0;
}