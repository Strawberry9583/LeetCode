#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		std::vector<std::vector<int>> result;
		std::sort(nums.begin(), nums.end());
		std::vector<int> last_result(3);
		for (int idx1 = 0; idx1 + 2 < nums.size(); ++idx1) {
			last_result[0] = nums[idx1];

			for (int idx2 = idx1 + 1, idx3 = nums.size() - 1; idx2<idx3;) {
				if (nums[idx2] + nums[idx3] == -nums[idx1]) {
					last_result[1] = nums[idx2];
					last_result[2] = nums[idx3];
					result.emplace_back(last_result);
					++idx2; --idx3;
					while (idx2<idx3&&nums[idx2] == nums[idx2 - 1]) {
						++idx2;
					}
					while (idx2<idx3&&nums[idx3] == nums[idx3 + 1]) {
						--idx3;
					}
				}
				else if (nums[idx2] + nums[idx3] < -nums[idx1]) {
					++idx2;
				}
				else {
					--idx3;
				}
			}
			while (idx1 + 2<nums.size() && nums[idx1 + 1] == nums[idx1]) {
				++idx1;
			}
		}
		return result;
	}
};
int main() {
	std::vector<int> test_vec{ -1,0,1,2,-1,-4 };
	Solution().threeSum(test_vec);
	cin.get();
	return 0;
}

