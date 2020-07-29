#include<iostream>
#include<vector>
#include<string>

using namespace std;


class Solution {
public:
	void trim_space(string & s) {
		//trim the space of beginning and end;
		int left = 0, right = s.size() - 1;
		for (; left < s.size(); ++left) {
			if (s[left] == ' ') {
				continue;
			}
			else {
				break;
			}
		}
		for (; right >= 0; --right) {
			if (s[right] == ' ') {
				continue;
			}
			else {
				break;
			}
		}
		if (left > right) {
			s = "";
		}
		else {
			s.assign(s.begin() + left, s.begin() + right + 1);
		}
	}
	bool isNumber(string s) {
		trim_space(s);
		if (s.empty()) {
			return false;
		}
		string pre, pos;
		int idx_e = s.find_first_of('e');
		//divide the str into pre_str and pos_str;
		if (idx_e != string::npos) {
			pre = s.substr(0, idx_e);
			pos = s.substr(idx_e + 1);
		}
		else {
			pre = s;
		}
		if (pre[0] == '+' || pre[0] == '-') {
			pre = pre.substr(1);
		}
		if (pos[0] == '+' || pos[0] == '-') {
			pos = pos.substr(1);
		}
		//if "e" exists, then string need non-empty pre_str and pos_str;
		if (idx_e != string::npos) {
			if (pre.empty() || pos.empty()) {
				return false;
			}
		}
		// judge the validation of exponent;
		for (auto & ele : pos) {
			if (ele < '0' || ele> '9') {
				return false;
			}
		}
		//divide the pre_str with '.'
		int dot_idx = pre.find_first_of('.');
		if (dot_idx != pre.npos) {
			pos = pre.substr(dot_idx + 1);
			pre = pre.substr(0, dot_idx);
			if (pos.empty() && pre.empty()) {
				return false;
			}
		}
		for (auto & ele : pre) {
			if (ele < '0' || ele> '9') {
				return false;
			}
		}
		for (auto & ele : pos) {
			if (ele < '0' || ele> '9' ) {
				return false;
			}
		}

		return true;
	}
};

int main() {
	Solution sol;
	string test = " .1 ";
	std::cout << sol.isNumber(test);

	std::cin.get();
	return 0;
}