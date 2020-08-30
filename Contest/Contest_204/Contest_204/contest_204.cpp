#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<functional>


using namespace std;


class Solution1 {
public:
	bool containsPattern(vector<int>& arr, int m, int k) {
		if (m*k > arr.size()) {
			return false;
		}
		string s(arr.size(), ' ');
		for (int idx = 0; idx < arr.size(); ++idx) {
			s[idx] = '1' - 1 + arr[idx];
		}
		for (int start_idx = 0; start_idx+m <= arr.size(); ++start_idx) {
			string targe_s = s.substr(start_idx, m);
			string target;
			for (int idx = 0; idx < k; ++idx) {
				target += targe_s;
			}
			if (s.find(target) != string::npos) {
				return true;
			}
		}
		return false;
	}
};

class Solution2 {
public:
	int getMaxLen(vector<int>& nums) {
		std::vector<pair<int, int>> dp(nums.size(), { 0,0 });
		if (nums[0] > 0) {
			dp[0].first = 1;
		}
		else if (nums[0] < 0) {
			dp[0].second = 1;
		}
		int result = dp[0].first;
		for (int idx = 1; idx < nums.size(); ++idx) {
			if (nums[idx] > 0) {
				dp[idx].first = dp[idx-1].first + 1;
				if (dp[idx - 1].second != 0) {
					dp[idx].second=dp[idx - 1].second + 1;
				}
			}
			else if (nums[idx] < 0) {
				if (dp[idx - 1].second != 0) {
					dp[idx].first = dp[idx - 1].second + 1;
				}
				dp[idx].second = dp[idx-1].first+1;
			}
			if (dp[idx].first > result) {
				result = dp[idx].first;
			}
		}
		return result;
	}
};


class Solution3 {
public:
	int minDays(vector<vector<int>>& grid) {
		return 0;
	}
};

class Solution {
public:
	int numOfWays(vector<int>& nums) {

	}
};

int main() {
	//std::vector<int> test_vec{ -1,2 };
	//std::cout << Solution2().getMaxLen(test_vec);

	//std::vector<int> test_vec{ 1,2,3,1,2 };
	//int m = 2, k = 2;
	//std::cout << Solution1().containsPattern(test_vec, m, k);


	cin.get();
	return 0;
}