//Given nums = [1, 1, 2],
//
//Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
//
//It doesn't matter what you leave beyond the returned length.
//Example 2:
//
//Given nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4],
//
//Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.
//
//It doesn't matter what values are set beyond the returned length.


#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int> & nums) {
		if (nums.empty()) {
			return 0;
		}
		else if(nums.size() == 1) {
			return 1;
		}
		int result = 1;
		//record the previous num;
		int pre_num = nums[0];
		for (size_t  cur = 1; cur < nums.size(); ) {
			if (pre_num == nums[cur]) {
				++cur;
			}
			else if (pre_num != nums[cur]) {
				pre_num = nums[cur];
				++result;
				nums[result - 1] = nums[cur];
				++cur;
			}
		}
		return result;
	}
};



int main() {
	vector<int> test = { 0,0,1,1,1,2,2,3,3,4 };
	Solution sol;
	auto ans = sol.removeDuplicates(test);
	for (size_t i = 0; i < ans; ++i) {
		cout << test[i] << "  ";
	}

	cin.get();
	return 0;
}