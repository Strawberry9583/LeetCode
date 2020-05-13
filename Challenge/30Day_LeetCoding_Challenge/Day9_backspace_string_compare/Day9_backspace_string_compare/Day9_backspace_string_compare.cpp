#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Solution1 {
public:
	bool backspaceCompare(string S, string T) {
		int s_size = 0, t_size = 0;
		for (int idx = 0; idx < S.size(); ++idx) {
			if (S[idx] == '#') {
				s_size = std::max(0, s_size-1);
			}
			else {
				if (s_size != idx) {
					S[s_size] = S[idx];
				}
				++s_size;
			}
		}
		for (int idx = 0; idx < T.size(); ++idx) {
			if (T[idx] == '#') {
				t_size = std::max(0, t_size - 1);
			}
			else {
				if (t_size != idx) {
					T[t_size] = T[idx];
				}
				++t_size;
			}
		}
		return S.substr(0,s_size) == T.substr(0,t_size);
	}
};

//no changes of original S and T;
class Solution2 {
public:
	bool backspaceCompare(string S, string T) {
		int back_s = S.size() - 1, back_t = T.size() - 1, s_pound_cnt = 0, t_pound_cnt = 0;
		while (back_s >= 0 || back_t >= 0) {
			//find the first no-# char from the back of S;
			while (back_s >= 0) {
				if (S[back_s] == '#') {
					++s_pound_cnt;
					--back_s;
				}
				else if (s_pound_cnt > 0) {
					--s_pound_cnt;
					--back_s;
				}
				else {
					break;
				}
			}
			//find the first no-# char from the back of T;
			while (back_t >= 0) {
				if (T[back_t] == '#') {
					++t_pound_cnt;
					--back_t;
				}
				else if (t_pound_cnt > 0) {
					--t_pound_cnt;
					--back_t;
				}
				else {
					break;
				}
			}
			if (back_s < 0 || back_t < 0) {
				break;
			}
			else {
				if (S[back_s] == T[back_t]) {
					--back_s;
					--back_t;
				}
				else {
					return false;
				}
			}
		}
		if (back_s < 0 && back_t < 0) {
			return true;
		}
		else {
			return false;
		}
	}
};

int main() {
	Solution2 sol;
	string s = "nzp#o#g";
	string t= "b#nzp#o#g";
	std::cout << sol.backspaceCompare(s, t);
	std::cin.get();
	return 0;
}