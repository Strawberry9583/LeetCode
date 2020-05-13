/*
Conclusion for the binary search module and its variant.

Author: Xia, Hai
First edition date: 2020.05.12
*/

#include<iostream>
#include<vector>

using namespace std;

int find_ele(std::vector<int> & nums, int target) {
	int left = 0, right = nums.size() - 1;
	while (left<=right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] == target) {
			return mid;
		}
		else if (nums[mid] > target) {
			right = mid - 1;
		}
		else if (nums[mid] < target) {
			left = mid + 1;
		}
	}
	//if no target, then return -1;
	return -1;
}

//find index of the first ele equal to target, otherwise return -1;
//[right, INX_MAX)>= target
int find_first_ele(std::vector<int> & nums, int target) {
	int left = 0, right = nums.size();
	while (left<right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] == target) {
			right = mid;
		}
		else if (nums[mid] > target) {
			right = mid;
		}
		else if (nums[mid] < target) {
			left = mid + 1;
		}
	}
	//if no target, return -1;
	if (left == nums.size())return -1;
	return nums[left] == target ? left : -1;
}

//find index of the last ele equal to target, otherwise return -1;
//[left,mid] < target
int find_last_ele(std::vector<int>& nums, int target) {
	int left = 0, right = nums.size();
	while (left<right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] == target) {
			left = mid+1;
		}
		else if (nums[mid] > target) {
			right = mid;
		}
		else if (nums[mid] < target) {
			left = mid + 1;
		}
	}
	//if no target, return -1;
	if (left == 0)return -1;
	return nums[left - 1] == target ? left - 1 : -1;
}

int main() {

	std::cin.get();
	return 0;
}