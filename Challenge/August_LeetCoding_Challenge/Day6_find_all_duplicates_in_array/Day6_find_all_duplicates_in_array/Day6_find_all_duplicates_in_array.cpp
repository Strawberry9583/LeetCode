#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


// solution1 hashmap to count the freq;
// time compleity: O(n); space complexity: O(n);
class Solution1 {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		std::unordered_map<int, int> num2freq;
		for (const auto & ele : nums) {
			++num2freq[ele];
		}
		std::vector<int> result;
		for (const auto & pa : num2freq) {
			if (pa.second > 1) {
				result.emplace_back(pa.first);
			}
		}
		return result;
	}
};

// solution2: use element itself to indicate idx;
class Solution2 {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		for (int idx = 0; idx < nums.size(); ++idx) {
			while (nums[idx]!=idx+1&&nums[nums[idx]-1]!=nums[idx]) {
				std::swap(nums[idx], nums[nums[idx] - 1]);
			}
		}
		std::vector<int> result;
		for (int idx = 0; idx < nums.size();++idx) {
			if (nums[idx] != idx + 1) {
				result.emplace_back(nums[idx]);
			}
		}
		return result;
	}
};

// solution3: use element itself to indicate idx, besides,
// nums[idx] <0, then nums[idx]+1 occurred once;
// nums[idx] >0, then nums[idx]+1 hasn't occurred .

class Solution {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		vector<int> Ret = {};
		for (int i = 0; i < nums.size(); i++) {
			if (nums[abs(nums[i]) - 1] > 0)
				nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
			else {
				nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
				Ret.push_back(abs(nums[i]));
			}
		}
		return Ret;
	}
};


int main() {
	cin.get();
	return 0;
}