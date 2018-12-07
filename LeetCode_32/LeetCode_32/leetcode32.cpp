//Given a string containing just the characters '(' and ')', find the length of the longest valid(well - formed) parentheses substring.
//
//Example 1:
//
//Input: "(()"
//	Output : 2
//	Explanation : The longest valid parentheses substring is "()"
//	Example 2 :
//
//	Input : ")()())"
//	Output : 4
//	Explanation : The longest valid parentheses substring is "()()"


//Solution:
//https://leetcode.com/problems/longest-valid-parentheses/solution/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<stack>


using namespace std;

class Solution {

public:
	//Solution 4: Scan in two direction;
	int scan_onedirection(string s) {
		int result = 0;
		map<char, int> cha_value;
		cha_value.insert(make_pair('(', -1));
		cha_value.insert(make_pair(')', 1));
		if (s.empty()) {
			return result;
		}

		int pre = 0, cur = 0;
		int cur_value = 0;
		while (cur<s.length()) {
			cur_value += cha_value[s[cur]];
			if (cur_value > 0) {
				++cur;
				pre = cur;
				cur_value = 0;
			}
			else if (cur_value < 0) {
				++cur;
			}
			else {
				if (result < (cur - pre + 1)) {
					result = cur - pre + 1;
				}
				++cur;
			}
		}
		return result;

	}
	//Solution using stack;
	int longestValidParentheses2(string s) {
		stack<int> sta;
		sta.push(-1);
		int result = 0;
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] == '(') {
				sta.push(i);
			}
			//if ')',then matched,so pop the top elment;
			else {
				sta.pop();
				if (sta.empty()) {
					sta.push(i);
				}
				//compare the current length with the recorded length;
				if ((i - sta.top()) > result) {
					result = i - sta.top();
				}
			}

		}
		return result;
	}
};


int main() {
	Solution sol;
	int ans = sol.longestValidParentheses2(")()())");
	cout << ans;
	cin.get();
	return 0;
}