#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

// bitset similar method: use nums[idx] to store the idx+1;
// when invalide, swap the nums[idx] to nums[nums[idx]-1];
// until find the nums[nums[idx]-1]==idx+1 and nums[idx]==idx+1;
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int result = -1;
		for (int idx = 0; idx < nums.size(); ++idx) {
			while (nums[idx]!=idx+1) {
				if (nums[nums[idx] - 1] != nums[idx]) {
					std::swap(nums[idx], nums[nums[idx] - 1]);
				}
				else {
					result = nums[idx];
					break;
				}
			}
			if (result != -1) {
				break;
			}
		}
		return result;
	}
};


// https://leetcode.com/problems/find-the-duplicate-number/solution/
// similar to solution1, called  Floyd's Tortoise and Hare
// like the mothod to judge whether circle exists in linked-list, and then find the 
// entrance points of the circle.
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		// Find the intersection point of the two runners.
		int tortoise = nums[0];
		int hare = nums[0];
		do {
			tortoise = nums[tortoise];
			hare = nums[nums[hare]];
		} while (tortoise != hare);

		// Find the "entrance" to the cycle.
		tortoise = nums[0];
		while (tortoise != hare) {
			tortoise = nums[tortoise];
			hare = nums[hare];
		}

		return hare;
	}
};
int main() {
	std::vector<int> test_vec{ 1,3,4,2,2 };
	//std::swap(test_vec[0], test_vec[1]);
	for (auto & ele : test_vec) { std::cout << ele << " "; };
	std::cout << Solution().findDuplicate(test_vec);
	cin.get();
	return 0;
}