#include<iostream>
#include<string>
#include<stack>
#include<algorithm>

using namespace std;


//Solution 1: use reccursion to judge the substring but with too many duplicate calc;
class Solution {
public:
	bool checkValidString(string s) {
		if (s.empty()) {
			return true;
		}
		int cur_idx = 0, count = 0;
		return if_valid(s, cur_idx,count);
	}
	bool if_valid(string & s, int cur_idx,int count) {
		if (cur_idx == s.size() ) {
			if (count == 0) {
				return true;
			}
			else {
				return false;
			}
		}
		else if (count < 0) {
			return false;
		}

		if (s[cur_idx] == '(') {
			return if_valid(s, cur_idx + 1, count+1);
		}
		else if (s[cur_idx] == ')') {
			return if_valid(s, cur_idx + 1, count-1);
		}
		else {
			return if_valid(s, cur_idx + 1, count) || if_valid(s, cur_idx + 1, count + 1) || if_valid(s, cur_idx + 1, count - 1);
		}
	}
};

//Solution 2: just record the idx of '*' and '(' with stack;
class Solution {
public:
	bool checkValidString(string s) {
		if (s.empty()) {
			return true;
		}
		bool if_valid = true;
		std::stack<int> left_idx;
		std::stack<int> star_idx;
		int idx = 0;
		while (idx<s.size()) {
			if (s[idx] == '(') {
				left_idx.push(idx);
			}
			else if (s[idx] == ')') {
				if (left_idx.empty()) {
					if (star_idx.empty()) {
						return false;
					}
					else {
						star_idx.pop();
					}
				}
				else {
					left_idx.pop();
				}
			}
			else {
				star_idx.push(idx);
			}
			++idx;
		}
		if (left_idx.empty()) {
			return true;
		}
		else {
			while ((!left_idx.empty()) && (!star_idx.empty())) {
				//the star_idx must greater than left_idx, then the start_idx serving for ')' can be valid;
				//Such as ((***))(((; the star can not served as ')' to assure the validation.
				if (left_idx.top() > star_idx.top()) {
					return false;
				}
				else {
					left_idx.pop();
					star_idx.pop();
				}
			}
		}
		return left_idx.empty();
	}
};



int main() {
	Solution sol;
	std::cout << sol.checkValidString("()");
	std::cin.get();
	return 0;
}