//35. Search Insert Position
//Given a sorted array and a target value, return the index if the target is found.If not, return the index where it would be if it were inserted in order.
//
//You may assume no duplicates in the array.
//
//Example 1:
//
//Input: [1, 3, 5, 6], 5
//	Output : 2
//	Example 2 :
//
//	Input : [1, 3, 5, 6], 2
//	Output : 1
//	Example 3 :
//
//	Input : [1, 3, 5, 6], 7
//	Output : 4
//	Example 4 :
//
//	Input : [1, 3, 5, 6], 0
//	Output : 0
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		//check if it is possible for target in the sorted vector;
		int left = 0, right = nums.size() - 1;
		if (nums.empty() || (*nums.begin() > target)) {
			return 0;
		}
		else if (*(nums.end() - 1) < target) {
			return nums.size();
		}
		
		else {
			while (left <= right) {
				int mid = left + (right - left) / 2;
				if (nums[mid] > target) {
					right = mid - 1;
				}
				//find the first occurence of the target
				else if (nums[mid] == target) {
					return mid;
				}
				else {
					left = mid + 1;
				}
			}
			// find the first element greater than target;
			return left;
		}

	}
};

int main() {
	Solution sol;
	vector<int> temp = { 1,3,5,6 };
	int target = 5;
	auto ans=sol.searchInsert(temp, target);
	cout << ans << endl;
	cin.get();
	return 0;
}