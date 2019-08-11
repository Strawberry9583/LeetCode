//Leetcode 41 First missing Positive
//Given an unsorted integer array, find the smallest missing positive integer.
//
//Example 1:
//
//Input: [1, 2, 0]
//	Output : 3
//	Example 2 :
//
//	Input : [3, 4, -1, 1]
//	Output : 2
//	Example 3 :
//
//	Input : [7, 8, 9, 11, 12]
//	Output : 1
//	Note :
//
//	Your algorithm should run in O(n) time and uses constant extra space.
//����������±�i��ʾ1~n(n==nums.size())��n������������鵱�г�����1~n֮���Ԫ����ôһ�α��������Խ���ЩԪ�ط����ڶ�Ӧ��λ�á�
//û�г��ֵ�Ԫ�ض�Ӧλ�õ�ֵһ���Ͳ�����v[i] == i + 1����ô��һ�����ֵľ�����С�ģ�
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		//utilize  the index of the nums to indicate the nums from 1 to nums.size();
		for (int idx = 0; idx < nums.size(); ++idx) {
			//caution if swapped, then compare from the new nums[idx]
			// to ensure the element from 0 to idx has been arranged.
			while (nums[idx] > 0 && nums[idx] <= nums.size()&& nums[idx]!=nums[nums[idx]-1]) {
				std::swap(nums[idx], nums[nums[idx] - 1]);
			}
		}
		//if all element satisfy nums[idx]==idx+1;
		//then result=nums.size();
		int result = nums.size() + 1;
		for (int cur = 0; cur < nums.size(); ++cur) {
			if (nums[cur] != cur + 1) {
				result = cur + 1;
				break;
			}
		}
		return result;
	}
};

int main() {
	Solution sol;
	vector<int> test{ 3,4,-1,1 };
	cout<<sol.firstMissingPositive(test);

	cin.get();
	return 0;
}