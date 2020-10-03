#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>

using namespace std;

class Solution {
public:
	int findPairs(vector<int>& nums, int k) {
		int result = 0;
		if (k == 0) {
			std::unordered_map<int,int> num2freq;
			for (int idx = 0; idx < nums.size(); ++idx) {
				++num2freq[nums[idx]];
			}
			for (const auto & ele : num2freq) {
				if (ele.second > 1) {
					++result;
				}
			}
			return result;
		}
		std::unordered_map<int, std::pair<int, bool>> num2idxflag;
		for (int idx = 0; idx < nums.size(); ++idx) {
			num2idxflag[nums[idx]].first = idx;
			num2idxflag[nums[idx]].second = false;
		}
		for (int idx = 0; idx < nums.size(); ++idx) {
			if (num2idxflag[nums[idx]].second) {
				continue;
			}
			else {
				num2idxflag[nums[idx]].second = true;
				int target = nums[idx] + k;
				if (num2idxflag.find(target) != num2idxflag.end()) {
					++result;
				}
			}
		}
		return result;
	}
};



int main() {
	std::vector<int> nums{ 1,3,1,5,4 };
	int k = 0;
	std::cout << Solution().findPairs(nums, k);
	cin.get();
	return 0;
}