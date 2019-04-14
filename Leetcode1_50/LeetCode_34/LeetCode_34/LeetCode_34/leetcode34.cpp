//34. Find First and Last Position of Element in Sorted Array
//
//Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
//
//Your algorithm's runtime complexity must be in the order of O(log n).
//
//If the target is not found in the array, return[-1, -1].
//
//Example 1:
//
//Input: nums = [5, 7, 7, 8, 8, 10], target = 8
//	Output : [3, 4]
//	Example 2 :
//
//	Input : nums = [5, 7, 7, 8, 8, 10], target = 6
//	Output : [-1, -1]


//reference 1: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/solution/
//reference 2£ºhttps://blog.csdn.net/dc_726/article/details/52202987
//Approach 2: Binary Search
//Intuition
//
//Because the array is sorted, we can use binary search to locate the left and rightmost indices.
//
//Algorithm
//
//The overall algorithm works fairly similarly to the linear scan approach, except for the subroutine used to find the left and rightmost indices themselves.Here, we use a modified binary search to search a sorted array, with a few minor adjustments.First, because we are locating the leftmost(or rightmost) index containing target(rather than returning true iff we find target), the algorithm does not terminate as soon as we find a match.Instead, we continue to search until lo == hi and they contain some index at which target can be found.
//
//The other change is the introduction of the left parameter, which is a boolean indicating what to do in the event that target == nums[mid]; if left is true, then we "recurse" on the left subarray on ties.Otherwise, we go right.To see why this is correct, consider the situation where we find target at index i.The leftmost target cannot occur at any index greater than i, so we never need to consider the right subarray.The same argument applies to the rightmost index.
//
//The first animation below shows the process for finding the leftmost index, and the second shows the process for finding the index right of the rightmost index.
#include<iostream>
#include<vector>

using namespace std;



class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		if ( (nums.empty()) || (*nums.begin() > target)||(*(nums.end() - 1) < target) ) {
			return vector<int>{-1, -1};
		}
		int left = left_bound(nums, 0, nums.size() - 1, target);
		/*cout << left << endl;*/

		if( left == -1){
			return vector<int>{-1, -1};
		}
		else {
			return vector<int>{left, right_bound(nums, 0, nums.size() - 1, target)};
		}
	}
	int left_bound(vector<int> & nums,int left,int right, int target) {
		if (left > right) {
			if (nums[left] == target) {
				return left;
			}
			else {
				return -1;
			}
		}
		else {
			int mid = left + (right - left) / 2;
			if (nums[mid] >= target) {
				return left_bound(nums, left, mid-1 , target);
				//right = mid - 1;
			}
			//if (nums[mid] < target)
			else{
				return left_bound(nums, mid+1, right, target);
				//left = mid + 1;
			}
			//following condition of == merged with aboving >; 
			//else {
			//	right = mid - 1;
			//}
		}
	}
	int right_bound(vector<int> & nums, int left, int right, int target) {
		if (left > right) {
			if (nums[right] == target) {
				return right;
			}
			else {
				return -1;
			}
		}
		else {
			int mid = left + (right - left) / 2;
			if (nums[mid] > target) {
				return right_bound(nums, left, mid - 1, target);
				//right = mid - 1;
			}
			// if (nums[mid] <= target) 
			else{
				return right_bound(nums, mid+1 , right, target);
				//left = mid + 1;
			}
			//following condition of == merged with aboving >; 
			//else {
			//	left = mid+1;
			//}
		}
	}
};



int main() {


	vector<int> nums = {};
	int target = 8;
	Solution sol;
	auto ans=sol.searchRange(nums, target);
	for (auto & i : ans) {
		cout << i << "  ";
	}
	cin.get();
	return 0;
}