#include<vector>
#include<string>
#include<iostream>

using namespace std;



// similar to partition method;
// [0, i):  0
// [i, j):  1
// [j, k] : unsorted
// (k, array.length - 1] :  2
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int i = 0, j = 0, k = nums.size() - 1;
		while (j<=k) {
			if (nums[j] == 0) {
				std::swap(nums[i], nums[j]);
				++i;
				++j;
			}
			else if (nums[j] == 1) {
				++j;
			}
			else if (nums[j] == 2) {
				std::swap(nums[j], nums[k]);
				--k;
			}
		}
	}
};

int main() {
	std::vector<int> test_vec{ 1,2,0,1,2,0,1,1,2,2 };
	Solution().sortColors(test_vec);
	for (auto & ele : test_vec) {
		std::cout << ele;
	}
	cin.get();
	return 0;
}