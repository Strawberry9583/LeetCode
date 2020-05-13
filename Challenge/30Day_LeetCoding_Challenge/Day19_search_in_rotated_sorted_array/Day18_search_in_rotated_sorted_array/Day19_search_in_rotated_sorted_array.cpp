#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

class Solution1 {
public:
	int search(vector<int>& nums, int target) {
		if (nums.empty()) {
			return -1;
		}
		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (target == nums[mid]) {
				return mid;
			}
			if (nums[left] >= nums[right]) {
				if (target < nums[mid]) {
					if (nums[left]<nums[mid]) {
						if (target > nums[right]) {
							right = mid - 1;
						}
						else if (target == nums[right]) {
							return right;
						}
						else {
							left = mid + 1;
						}
					}
					else if (nums[left] == nums[mid]) {
						left = mid + 1;
					}
					else {
						right = mid - 1;
					}
				}
				else {
					if (nums[left] < nums[mid]) {
						left = mid + 1;
					}
					else if (nums[left] == nums[mid]) {
						left = mid + 1;
					}
					else {
						if (target > nums[right]) {
							right = mid - 1;
						}
						else if (target == nums[right]) {
							return right;
						}
						else {
							left = mid + 1;
						}
					}
				}
			}
			else {
				if (target> nums[mid]) {
					left = mid + 1;
				}
				else {
					right = mid - 1;
				}
			}
		}
		return -1;
	}
};


class Solution {
public:
	int search(vector<int>& nums, int target) {
		//int left = 0, right = nums.size();
		//while (left <= right) {
		//	int mid = left + (right - left) / 2;
		//	if (target == nums[mid]) {
		//		return mid;
		//	}
		//	else if (target>nums[mid]) {
		//		//nums[mid] <= nums[left], if nums[mid]=nums[left], then target> nums[left] then left can be ignored with left=mid+1;
		//		//target<= nums[right], if nums[right]==target, then change the left_bound or the right=mid-1, then the nums[mid] will be missed;
		//		if (nums[mid] <= nums[right] && target <= nums[right]) {
		//			left = mid + 1;
		//		}
		//		else {
		//			right = mid - 1;
		//		}
		//	}
		//	else if(target<nums[mid]) {
		//		//if nums[mid]>= nums[left], or when nums[mid]==nums[left], then left=mid+1, the nums[mid] will be missed;
		//		//if nums[left]==target, then nums[left]<num[mid], then right=mid-1 can miss the nums[mid], which is approriate;
		//		if (nums[mid] >= nums[left] && nums[left] <= target) {
		//			right = mid - 1;
		//		}
		//		else {
		//			left = mid + 1;
		//		}
		//	}
		//}
		//有一个问题，那就是在二分搜索中，nums[mid] 和 nums[left] 还有可能相等的，
		//	当数组中只有两个数字的时候，比如[3, 1]，那该去取那一边呢？
		//	由于只有两个数字且 nums[mid] 不等于 target，target 只有可能在右半边出现。
		//	最好的方法就是让其无法进入左半段，就需要左半段是有序的，
		//	而且由于一定无法同时满足 nums[left] <= target && nums[mid] > target，
		//	因为 nums[left] 和 nums[mid] 相等，同一个数怎么可能同时大于等于 target，
		//	又小于 target。由于这个条件不满足，则直接进入右半段继续搜索即可，
		//	所以等于的情况要加到 nums[mid] > nums[left] 的情况中，变成大于等于，参见代码如下：
		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] == target) return mid;
			if (nums[mid] >= nums[left]) {
				if (nums[left] <= target && nums[mid] > target) right = mid - 1;
				else left = mid + 1;
			}
			else {
				if (nums[mid] < target && nums[right] >= target) left = mid + 1;
				else right = mid - 1;
			}
		}
		return -1;

	}
};

int main() {
	Solution sol;
	std::vector<int> test{4,5,6,7,0,1,2};
	std::cout << sol.search(test,2);
	std::cin.get();
	return 0;
}