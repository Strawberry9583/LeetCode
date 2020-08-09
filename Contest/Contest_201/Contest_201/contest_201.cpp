#include<iostream>
#include<cmath>
#include<unordered_map>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<functional>

using namespace std;


class Solution1 {
public:
	string makeGood(string s) {
		for (int pre_idx = 0; pre_idx + 1 < s.size(); ) {
			if (s[pre_idx + 1] - s[pre_idx] == 'A' - 'a'|| s[pre_idx + 1] - s[pre_idx]=='a'-'A') {
				s.erase(s.begin() + pre_idx, s.begin() +pre_idx+ 2);
				if (pre_idx > 0) {
					--pre_idx;
				}
			}
			else {
				++pre_idx;
			}
			
		}
		return s;
	}
};


class Solution2 {
public:
	char findKthBit(int n, int k) {
		return dfs(n, k) ? '1' : '0';
	}
	bool dfs(int n, int k) {
		if (n == 1 && k == 1) {
			return false;
		}
		int half = std::pow(2, n - 1)-1;
		if (k <= half) {
			return dfs(n - 1, k);
		}
		else if (k == half + 1) {
			return true;
		}
		else {
			int rest = std::pow(2, n) - k;
			return !dfs(n - 1, rest);
		}
	}
};


class Solution3 {
public:
	int maxNonOverlapping(vector<int>& nums, int target) {
		std::unordered_map<int, int> sum2idx;
		sum2idx[0] = -1;
		int cur_sum = 0;
		std::vector<int> range_vec(nums.size(), -2);
		for (int idx = 0; idx < nums.size(); ++idx) {
			cur_sum += nums[idx];

			int temp = cur_sum - target;
			if (sum2idx.find(temp) != sum2idx.end()) {
				range_vec[idx] = sum2idx[temp];
			}
			sum2idx[cur_sum] = idx;
		}
		std::vector<int> dp(nums.size()+1, 0);
		int result =0;
		for (int post_idx = 1; post_idx <= range_vec.size(); ++post_idx) {
			if (range_vec[post_idx-1] == -1) {
				dp[post_idx] = std::max(1, result);
			}
			else if (range_vec[post_idx - 1] == -2) {
				dp[post_idx] = result;
			}
			else {
				//if()
				dp[post_idx] = std::max(dp[range_vec[post_idx - 1]+1] + 1,
					result);
			}
			if (result < dp[post_idx]) {
				result = dp[post_idx];
			}
		}
		return result;
	}
};

int main() {

	string s = "leEeetcode";
	std::cout << Solution1().makeGood(s);


	int n = 4, k = 14;
	std::cout << Solution2().findKthBit(n, k);

	std::vector<int>test_vect{ -1,-2,8,-3,8,-5,5,-4,5,4,1 };
	int target = 5;
	std::cout << Solution3().maxNonOverlapping(test_vect, target);

	cin.get();
	return 0;
}