/*
Conclusion for the binary search module and its variant.

Author: Xia, Hai
First edition date: 2020.05.12
Latest modify date: 2020.07.25
*/

#include<iostream>
#include<vector>

using namespace std;

// problem: find target in the sorted array, if there is not, return -1;
// time complexity: O(lgn);
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

// problem: find index of the first ele equal to target, otherwise return -1; (lower_bound)
// [right, INX_MAX)>= target
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

//problem: find index of the last ele equal to target, otherwise return -1; (upper_bound)
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

// problem: find target element in Rotated Sorted Array (RSA);
// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
// You may assume no duplicate exists in the array.
int find_ele_in_RSA(vector<int>& nums, int target) {
	int len = nums.size(), left = 0, right = len - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (nums[mid] == target) return mid;
		if (nums[mid] >= nums[0]) {
			if (target < nums[mid] && target >= nums[0]) right = mid - 1;
			else left = mid + 1;
		}
		else {
			if (target > nums[mid] && target < nums[0]) left = mid + 1;
			else right = mid - 1;
		}
	}
	return -1;
}

// problem: find target element in Rotated Sorted Array (RSA);
// You may assume there are duplicates.
// The idea is the same as the previous one without duplicates
// 1) everytime check if targe == nums[mid], if so, we find it.
// 2) otherwise, we check if the first half is in order(i.e.nums[left] <= nums[mid])
// and if so, go to step 3), otherwise, the second half is in order, go to step 4)
// 3) check if target in the range of[left, mid - 1](i.e.nums[left] <= target < nums[mid]), 
//  if so, do search in the first half, i.e.right = mid - 1; otherwise, search in the second half left = mid + 1;
// 4)  check if target in the range of[mid + 1, right](i.e.nums[mid]<target <= nums[right]), 
//  if so, do search in the second half, i.e.left = mid + 1; otherwise search in the first half right = mid - 1;
int find_ele_in_RSAII(vector<int>& nums, int target) {
	int left = 0, right = nums.size() - 1, mid;

	while (left <= right) {
		mid = left+(right-left)/2;
		if (nums[mid] == target) return mid;

		// the only difference from the first one, trickly case, just updat left and right
		if ((nums[left] == nums[mid]) && (nums[right] == nums[mid])) { ++left; --right; }

		else if (nums[left] <= nums[mid]) {
			if ((nums[left] <= target) && (nums[mid] > target)) right = mid - 1;
			else left = mid + 1;
		}
		else {
			if ((nums[mid] < target) && (nums[right] >= target)) left = mid + 1;
			else right = mid - 1;
		}
	}
	return -1;
}

// problem: Find Minimum in Rotated Sorted Array
// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
// Duplicate element may not exists;
// minimum element must exists in [0,size-1], then break loop condition set left<right,
// Time complexity: O(lgn)
int findMinimumI(vector<int>& nums) {
	int left = 0, right = nums.size()-1;
	while (left<right) {
		if (nums[left] < nums[right]) {
			break;
		}
		int mid = left + (right - left) / 2;
		if (nums[mid] < nums[right]) {
			right = mid;
		}
		else if (nums[mid] > nums[right]) {
			left = mid + 1;
		}
		else if(nums[mid]==nums[right]){
			// may not happen;
		}
	}
	return nums[left];
}

// problem: Find Minimum in Rotated Sorted Array II
// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
// Duplicate element may exists;
// minimum element must exists in [0,size-1], then break loop condition set left<right,
// because left==right indicates that minimum is nums[left];
// time complexity: O(lgn), worst complexity: O(n) with all element equal;
int findMinimumII(vector<int>& nums) {
	int left = 0, right = nums.size() - 1;
	while (left<right) {
		// if sorted array without pivot, then result the minimum element directly;
		if (nums[left] < nums[right]) {
			break;
		}

		int mid = left + (right - left) / 2;
		//minimum element exists in [left,mid]
		if (nums[mid] < nums[right]) {
			right = mid;
		}
		//minimum element exists in [mid+1,right]
		else if (nums[mid]>nums[right]) {
			left = mid + 1;
		}
		//minimum element exists in [left,right-1]
		else if (nums[mid] == nums[right]) {
			--right;
		}
	}
	return nums[left];
}


int main() {

	std::cin.get();
	return 0;
}