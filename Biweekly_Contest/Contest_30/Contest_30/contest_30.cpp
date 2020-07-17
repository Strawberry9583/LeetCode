#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<queue>

using namespace std;

class Solution1 {
public:
	string reformatDate(string date) {
		string day;
		if (date[1] >= '0' && date[1] <= '9') {
			day = date.substr(0, 2);
		}
		else {
			day = "0"+date.substr(0, 1);
		}
		std::unordered_map<string, string> name2result;
		name2result["Jan"] = "01";
		name2result["Feb"] = "02";
		name2result["Mar"] = "03";
		name2result["Apr"] = "04";
		name2result["May"] = "05";
		name2result["Jun"] = "06";
		name2result["Jul"] = "07";
		name2result["Aug"] = "08";
		name2result["Sep"] = "09";
		name2result["Oct"] = "10";
		name2result["Nov"] = "11";
		name2result["Dec"] = "12";
		int first_space = date.find_first_of(' ');
		int second_space = date.find_first_of(first_space + 1, ' ');
		string month = name2result[date.substr(first_space + 1,3)];
		string year(date.end() - 4, date.end());
		return year + "-" + month + "-" + day;
	}
};


class Solution2 {
public:
	int rangeSum(vector<int>& nums, int n, int left, int right) {
		std::vector<int> sum(n+1, 0);
		sum[1] = nums[0];
		int mod = 1000000007;
		for (int idx = 2; idx <= n; ++idx) {
			sum[idx] = (sum[idx - 1] + nums[idx-1])%mod;
		}
		std::vector<int> all_sum(n*(n+1)/2,0);
		int idx = 0;
		for (int start = 0; start < n; ++start) {
			for (int end = start; end < n; ++end) {
				all_sum[idx++] = (sum[end+1] - sum[start])%mod;
			}
		}
		std::sort(all_sum.begin(), all_sum.end());
		int result = 0;
		for (int idx = left - 1; idx < right; ++idx) {
			result += all_sum[idx];
			result %= mod;
		}
		return result;
	}
};

class Solution3 {
public:
	int minDifference(vector<int>& nums) {
		if (nums.size() < 5) {
			return 0;
		}
		int result = std::numeric_limits<int>::max();
		std::sort(nums.begin(), nums.end());
		std::vector<std::vector<int>> method{ {0,0,0},{0,0,1},{0,1,0,},{0,1,1},{1,0,0},
		{1,0,1}, {1,1,0},{1,1,1} };
		for (int method_idx = 0; method_idx < method.size(); ++method_idx) {
			auto temp_num = nums;
			for (int erase_idx = 0; erase_idx < 3; ++erase_idx) {
				if (method[method_idx][erase_idx]) {
					temp_num.erase(temp_num.begin());
				}
				else {
					temp_num.erase(temp_num.end() - 1);
				}
			}
			if (temp_num.back() - temp_num.front() < result) {
				result = temp_num.back() - temp_num.front();
			}
		}
		return result;
	}
};

//dp[i] means the result for n = i.
//
//if there is any k that dp[i - k * k] == false,
//it means we can make the other lose the game,
//so we can win the game an dp[i] = true.
class Solution {
public:
	bool winnerSquareGame(int n) {
		std::deque<bool> dp(n+1);
		for (int i = 0; i <= n; i++) {
			for (int j = 1; j*j <= i; j++) {
				if (!dp[i - j*j]) {
					dp[i] = true;
					break;
				}
			}
		}
		return dp[n];
	}

};

int main() {
	//std::vector<int> test_ve{ 1,2,3,4 };
	//std::cout << Solution().rangeSum(test_ve, 4, 1, 5);

	/*0  1  2   10  14*/

	//std::vector<int> test_vec{ 1,5,0,10,14 };
	//std::cout << Solution().minDifference(test_vec);

	//string date = "20th Oct 2052";
	//std::cout << Solution().reformatDate(date);

	std::cout<<Solution().winnerSquareGame(17);
	cin.get();
	return 0;
}