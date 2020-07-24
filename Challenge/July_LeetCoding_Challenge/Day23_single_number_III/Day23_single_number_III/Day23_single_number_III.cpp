#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


// firsly, get the OXR result of all numbers;
// secondly, divide the numbers into two grow according to whether the bit is 1 
// in lowest 1 bits of OXR result;
// find the number in each group;
class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		
		int twoOXR = 0;
		for (auto & ele : nums) {
			twoOXR ^= ele;
		}
		//get the OXR result of all numbers;
		int lowest_one_bit = twoOXR & ~(twoOXR - 1);
		std::pair<int, int> group1_2{ 0,0 };
		for (auto & ele : nums) {
			if (ele&lowest_one_bit) {
				group1_2.first ^= ele;
			}
			else {
				group1_2.second ^= ele;
			}
		}
		return std::vector<int>{group1_2.first, group1_2.second};
	}
};


int main() {
	std::vector<int> nums{ 1,2,1,3,2,5 };
	Solution().singleNumber(nums);
	cin.get();
	return 0;
}