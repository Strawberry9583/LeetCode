#include<iostream>
#include<vector>
#include<string>

using namespace std;

// solution1:
// binary search: find the first num greater than target
class Solution1 {
public:
	int searchInsert(vector<int>& nums, int target) {
		int left = 0, right = nums.size();
		// find the first num greater than target;
		while (left<right) {
			int mid = left + (right - left) / 2;
			if (nums[mid]>target) {
				right = mid;
			}
			else if (nums[mid] == target) {
				left = mid + 1;
			}
			else if (nums[mid]<target) {
				left = mid + 1;
			}
		}
		if (left == 0) {
			return left;
		}
		return nums[left - 1] == target ? left - 1 : left;
	}
};

// solution2:
// binary search£ºfind the first element greater or equal to the target;
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int left = 0, right = nums.size();
		// find the first num greater or equal to target;
		while (left<right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] >= target) {
				right = mid;
			}
			else if (nums[mid]<target) {
				left = mid + 1;
			}
		}
		return left;
	}
};

int main() {
	cin.get();
	return 0;
}