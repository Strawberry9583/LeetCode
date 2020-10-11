#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left<=right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] < target) {
				left = mid + 1;
			}
			else if(nums[mid]>target) {
				right = mid - 1;
			}
			else {
				return mid;
			}
		}
		return -1;
	}
};

int main() {
	cin.get();
	return 0;
}