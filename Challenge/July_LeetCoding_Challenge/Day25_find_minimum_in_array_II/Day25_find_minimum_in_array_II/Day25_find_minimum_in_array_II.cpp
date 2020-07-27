#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


// problem: Find Minimum in Rotated Sorted Array II
// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
// Duplicate element may exists;
// minimum element must exists in [0,size-1], then then condition set left<right,
// because left==right indicates that minimum is nums[left];
// time complexity: O(lgn), worst complexity: O(n) with all element equal;
class Solution {
public:
	int findMin(vector<int>& nums) {
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
};


int main() {
	std::vector<int> test_vec{ 5,1,3 };
	std::cout << Solution().findMin(test_vec);
	cin.get();
	return 0;
}