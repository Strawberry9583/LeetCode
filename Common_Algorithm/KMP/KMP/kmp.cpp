#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

//KMP Alg. is explained. https://leetcode.com/problems/implement-strstr/discuss/12956/C%2B%2B-Brute-Force-and-KMP
//https://blog.csdn.net/v_july_v/article/details/7041827



class Solution {
public:
	int kmp(const string & s, const string & p) {
		vector<int> next_pos = next(p);
		int match_len = 0;
		for (int i = 0; i < s.size(); ++i) {
			while (match_len>0 && p[match_len] != s[i]) {
				match_len = next_pos[match_len - 1];
			}
			if (p[match_len] == s[i]) {
				++match_len;
			}
			if (match_len == p.size()) {
				return i - p.size() + 1;
			}
		}
		return -1;
	}
	vector<int>  next(const string & p) {
		vector<int> next;
		next.push_back(0);
		int k = 0;
		//next[i] means: before the index k, 
		//there is a same prefix and suffix with the length of next[k] in the string p
		for (int i = 0; i < p.size(); ++i) {
			while (k>0 && p[i] != p[k]) {
				k = next[k - 1];
			}
			if (p[i] == p[k]) {
				++k;
			}
			next.push_back(k);
		}
		return next;
	}
};


int main() {
	Solution sol;
	sol.kmp("stragdgfadg", "agdg");
	cin.get();
	return 0;
}