#include<iostream>
#include<vector>
#include<algorithm>
#include<string>


using namespace std;

class Solution {
public:
	//non-recursive method;
	int search(vector<int>& nums, int target) {
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

	//recursive method;
	int search1(vector<int>& nums, int target) {
		if (nums.empty()) {
			return -1;
		}
		int ans = binary_search(nums, target, 0, nums.size() - 1);
		return ans;
	}
	int binary_search(vector<int> & nums,int & target, int left, int right) {

		if (left == right) {
			if (target == nums[left]) {
				return left;
			}
			else {
				return -1;
			}
		}
		//Ascending orders, normal binary search;
		if (nums[right]>nums[left]) {
			int middle = (left + right) / 2;
			//target in left;
			if (nums[middle] >= target) {
				right = middle;
				binary_search(nums, target, left, right);
			}
			else {
				left = middle+1;
				binary_search(nums, target, left, right);
			}
		}
		//Pivot in it;
		else {
			int middle = (left + right) / 2;
			//left part is ascending, then right has pivot;
			if (nums[middle] > nums[left]) {
				//target in left;
				if (nums[left] <=target&& nums[middle]>=target) {
					right = middle;
				}
				else {
					left = middle+1;
				}
			}
			//left part has pivot, then right part is normal;
			else {
				//target in right;
				if (nums[right] >=target&&target>=nums[middle]) {
					left = middle;
				}
				else {
					right = middle-1;
				}
			}
			binary_search(nums, target, left, right);
		}
	}
};

int main() {
	Solution sol;
	vector<int> test = {3,1};
	int ans = sol.search1(test,0);
	cout << ans << endl;
	cin.get();
	return 0;
}