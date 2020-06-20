#include<iostream>
#include<vector>
#include<string>

using namespace std;

// solution 1:
// DP: dp[i][j] indicates whether [s(0),s(i-1)] substring is the subsequence
// of the [t(0),t(j-1)] substring.
// Time complexity: O(s.size*t.size); Space complexity: O(s.size*t.size) (roll array: O(t.size)
class Solution1 {
public:
	bool isSubsequence(string s, string t) {
		std::vector<std::vector<int>> dp(s.size() + 1, std::vector<int>(t.size() + 1, 0));
		for (int idx_s = 0; idx_s <= s.size(); ++idx_s) {
			for (int idx_t = 0; idx_t <= t.size(); ++idx_t) {
				if (idx_s == 0) {
					dp[idx_s][idx_t] =1;
				}
				else if (idx_t == 0) {
					dp[idx_s][idx_t] = 0;
				}
				else {
					if (s[idx_s-1] == t[idx_t-1]) {
						dp[idx_s][idx_t] = (dp[idx_s - 1][idx_t - 1] || dp[idx_s][idx_t - 1]);
					}
					else {
						dp[idx_s][idx_t] = dp[idx_s][idx_t - 1];
					}
				}
			}
		}
		return dp.back().back();
	}
};


// solution 2:
// Two Pointer method
// when s[idx_s]==t[idx_t], then the only need is to find the rest matching from
// (idx_s,s.size) and (idx_t,t.size) range.
// Time complexity: O(t.size); Space complexity: O(1)
class Solution2 {
public:
	bool isSubsequence(string s, string t) {
		if (s.empty()) {
			return true;
		}
		int idx_s = 0, idx_t = 0;
		while (idx_t<t.size()) {
			if (s[idx_s] == t[idx_t]) {
				++idx_s;
				if (idx_s == s.size()) {
					return true;
				}
			}
			++idx_t;
		}
		return false;
	}
};

// solution 3: for follow up solution: binary search + map;
// Follow up:
// If there are lots of incoming S,
// and you want to check one by one to see if 
// T has its subsequence. In this scenario, how would you change your code ?
// Follow - up: O(N) time for pre - processing, O(Mlog ? ) for each S.
// when s[idx_s]==t[idx_t], then the only need is to find the rest matching from
// (idx_s,s.size) and (idx_t,t.size) range.
// Time complexity: O(s.size + t.size); Space complexity: O(1)

// Eg-1. s="abc", t="bahbgdca"
// idx=[a={1,7}, b={0,3}, c={6}]
//  i=0 ('a'): prev=1
//  i=1 ('b'): prev=3
//  i=2 ('c'): prev=6 (return true)
// Eg-2. s="abc", t="bahgdcb"
// idx=[a={1}, b={0,6}, c={5}]
//  i=0 ('a'): prev=1
//  i=1 ('b'): prev=6
//  i=2 ('c'): prev=? (return false)
class Solution {
public:
	bool isSubsequence(string s, string t) {
		//pre-processing:record the the char_idx in increasing order;
		std::vector<std::vector<int>> char2idx(26, std::vector<int>());
		for (int idx = 0; idx < t.size(); ++idx) {
			char2idx[t[idx] - 'a'].emplace_back(idx);
		}
		int idx_s = 0, idx_pre = -1;
		while (idx_s<s.size()) {
			// find first char_idx greater then previous idx;
			int first_greater_idx = find_first_greater(idx_pre, char2idx[s[idx_s] - 'a']);
			if (first_greater_idx == -1) {
				return false;
			}
			else {
				idx_pre = first_greater_idx;
			}
			++idx_s;
		}
		return true;
	}
	// find the first num greater than target or return -1;
	int find_first_greater(int target, const std::vector<int> & nums) {
		int left = 0, right = nums.size();
		while (left<right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] > target) {
				right = mid;
			}
			else if (nums[mid] == target) {
				left = mid + 1;
			}
			else if (nums[mid] < target) {
				left = mid + 1;
			}
		}
		if (left == nums.size()) {
			return -1;
		}
		return nums[left];
	}
};

int main() {
	string s = "acb";
	string t = "ahbgdc";
	std::cout << Solution().isSubsequence(s, t);
	cin.get();
	return 0;
}