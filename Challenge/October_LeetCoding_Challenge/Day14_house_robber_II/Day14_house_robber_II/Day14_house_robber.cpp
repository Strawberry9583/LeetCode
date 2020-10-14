#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

// case1: do not rob house0;
// case2: rob house0;
class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 1) {
			return nums.front();
		}
		std::vector<std::pair<int,int>> dp_1(nums.size()+1, std::pair<int,int>(0,0));
		/*dp_1[1].first = nums[0];*/
		int result = 0;
		for (int idx = 1; idx < nums.size(); ++idx) {
			dp_1[idx + 1].first = nums[idx] + dp_1[idx].second;
			dp_1[idx + 1].second = std::max(dp_1[idx].first, dp_1[idx].second);
			if (result < dp_1[idx + 1].first) {
				result = dp_1[idx + 1].first;
			}
			if (result < dp_1[idx + 1].second) {
				result = dp_1[idx + 1].second;
			}
		}
		// rob the first one;
		std::vector<std::pair<int, int>> dp_2(nums.size() + 1, std::pair<int, int>(0, 0));
		dp_2[1].first = nums[0];
		if (dp_2[1].first > result) {
			result = dp_2[1].first;
		}
		for (int idx = 1; idx < nums.size(); ++idx) {
			if (idx == 1) {
				dp_2[idx + 1].first = 0;
				dp_2[idx + 1].second = dp_2[idx].first;
			}
			else if(idx==nums.size()-1){
				dp_2[idx + 1].second = std::max(dp_2[idx].first, dp_2[idx].second);
			}
			else {
				dp_2[idx + 1].first = nums[idx] + dp_2[idx].second;
				dp_2[idx + 1].second = std::max(dp_2[idx].first,dp_2[idx].second);
			}
			if (dp_2[idx + 1].first > result) {
				result = dp_2[idx + 1].first;
			}
			if (dp_2[idx + 1].second > result) {
				result = dp_2[idx + 1].second;
			}
		}
		return result;
	}
};


//Suppose there are n houses, since house 0 and n - 1 are now neighbors, we cannot rob them together and thus the solution is now the maximum of
//
//Rob houses 0 to n - 2;
//Rob houses 1 to n - 1.
//The code is as follows.Some edge cases(n < 2) are handled explicitly.

class Solution1 {
public:
	int rob(vector<int>& nums) {
		int n = nums.size();
		if (n < 2) return n ? nums[0] : 0;
		return max(robber(nums, 0, n - 2), robber(nums, 1, n - 1));
	}
private:
	int robber(vector<int>& nums, int l, int r) {
		int pre = 0, cur = 0;
		for (int i = l; i <= r; i++) {
			int temp = max(pre + nums[i], cur);
			pre = cur;
			cur = temp;
		}
		return cur;
	}
};

int main() {
	std::vector<int> test_vec{2,3,2};
	std::cout << Solution().rob(test_vec);
	cin.get();
	return 0;
}