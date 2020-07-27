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
		//��һ�����⣬�Ǿ����ڶ��������У�nums[mid] �� nums[left] ���п�����ȵģ�
		//	��������ֻ���������ֵ�ʱ�򣬱���[3, 1]���Ǹ�ȥȡ��һ���أ�
		//	����ֻ������������ nums[mid] ������ target��target ֻ�п������Ұ�߳��֡�
		//	��õķ������������޷��������Σ�����Ҫ����������ģ�
		//	��������һ���޷�ͬʱ���� nums[left] <= target && nums[mid] > target��
		//	��Ϊ nums[left] �� nums[mid] ��ȣ�ͬһ������ô����ͬʱ���ڵ��� target��
		//	��С�� target������������������㣬��ֱ�ӽ����Ұ�μ����������ɣ�
		//	���Ե��ڵ����Ҫ�ӵ� nums[mid] > nums[left] ������У���ɴ��ڵ��ڣ��μ��������£�
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