#include<vector>
#include<string>
#include<iostream>


using namespace std;


class Solution_1 {
public:
	int singleNonDuplicate(vector<int>& nums) {
		int left = 0, right = nums.size() - 1;
		int result = 0;
		while (left<right) {
			int mid = left + (right - left) / 2;
			if (left == 0) {
				if (nums[left] != nums[left + 1]) {
					return nums[left];
				}
				else {
					left = left + 2;
				}
			}
			else {
				if (nums[left] == nums[left - 1]) {
					left = left + 1;
				}
				else if (nums[left] == nums[left + 1]) {
					left = left + 2;
				}
				else {
					return nums[left];
				}
			}
			if (mid == nums.size() - 1) {
				if (nums[mid] == nums[mid - 1]) {
					mid = mid - 2;
				}
				else {
					return nums[mid];
				}
			}
			else {
				if (nums[mid] == nums[mid - 1]) {
					mid = mid;
				}
				else if (nums[mid] == nums[mid + 1]) {
					mid = mid+1;
				}
				else {
					return nums[mid];
				}
			}
			if ((mid - left) & 1) {
				left = mid + 1;
			}
			else {
				right = mid;
			}
		}
		return nums[left];
	}
};


class Solution {
public:
	int singleNonDuplicate(vector<int>& nums) {
		int left = 0, right = nums.size() - 1;
		while (left<right) {
			int mid = left + (right - left) / 2;
			int dis = mid - left;
			//[0,mid] extixts even number;
			if (dis & 1) {
				if (nums[mid] == nums[mid + 1]) {
					right = mid - 1;
				}
				else if (nums[mid] == nums[mid - 1]) {
					left = mid + 1;
				}
				else {
					return nums[mid];
				}
			}
			//[0,mid] extixts odd number;
			else {
				if (nums[mid] == nums[mid + 1]) {
					left = mid + 2;
				}
				else if (nums[mid] == nums[mid - 1]) {
					right = mid - 2;
				}
				else {
					return nums[mid];
				}
			}
		}
		return nums[left];
	}
};

int main() {
	std::cout << Solution().singleNonDuplicate(std::vector<int>{1, 1, 2});
	std::cin.get();
	return 0;
}