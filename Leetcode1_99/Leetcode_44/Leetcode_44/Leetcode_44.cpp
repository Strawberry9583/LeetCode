#include<iostream>
#include<vector>
#include<string>


using namespace std;


class Solution {
private:
	//std::vector<std::vector<int>> 
public:
	//DP method
	bool isMatch(string s, string p) {
		//s = "#" + s;
		//p = "#" + p;
		//return ismatched(s, p, 0, 0);
		std::vector<std::vector<bool>> dp(s.size() + 1, std::vector<bool>(p.size() + 1, false));
		dp[0][0] = true;
		for (int idx = 1; idx <= p.size(); ++idx) {
			if (p[idx-1] == '*') {
				dp[0][idx] = dp[0][idx - 1];
			}
		}
		for (int i = 1; i <= s.size(); ++i) {
			for (int j = 1; j <= p.size(); ++j) {
				if (p[j-1] == '*') {
					//match none,
					//dp[i][j] = dp[i][j - 1];
					//bool flag = false;
					//for (int idx = 0; idx<=i; ++idx) {
					//	flag = flag || dp[idx][j - 1]||dp[idx][j];
					//}
					dp[i][j] = dp[i-1][j]||dp[i][j-1];
					//dp[i][j]=dp[i][j-1]||
				}
				else if (p[j-1] == '?'||p[j-1]==s[i-1]) {
					dp[i][j] = dp[i - 1][j-1];
				}
			}
		}
		return dp[s.size()][p.size()];
	}
	//Pure recurrsive: Limted Time Exceeded;
	bool isMatched(const string & s, const string & p, int cur_s, int cur_p) {
		if (cur_s == s.size() && cur_p == p.size()) {
			return true;
		}
		else if (cur_p == p.size() && cur_s != s.size()) {
			return false;
		}
		else if (cur_p != p.size() && cur_s == s.size()) {
			while (cur_p<p.size()) {
				if (p[cur_p++] != '*') {
					return false;
				}
			}
			return true;
		}
		else {
			if (s[cur_s] == p[cur_p] || p[cur_p] == '?') {
				return isMatched(s, p, cur_s + 1, cur_p + 1);
			}
			else if (p[cur_p] == '*') {
				return isMatched(s, p, cur_s + 1, cur_p) \
					|| isMatched(s, p, cur_s + 1, cur_p + 1)\
					|| isMatched(s, p, cur_s, cur_p + 1);
			}
			else {
				return false;
			}
			//else {
			//	return false;
			//}
			//if (p[cur_p + 1] == '*') {
			//	if (s[cur_s] == p[cur_p] || p[cur_p] == '?') {
			//		return isMatched(s, p, cur_s + 1, cur_p) \
			//			|| isMatched(s, p, cur_s + 1, cur_p + 2)\
			//			|| isMatched(s, p, cur_s, cur_p + 2);
			//	}
			//	else {
			//		return isMatched(s, p, cur_s + 1, cur_p + 2);
			//	}
			//}
			//else {
			//	if (s[cur_s] == p[cur_p] || p[cur_p] == '?') {
			//		return isMatched(s, p, cur_s + 1, cur_p + 1);
			//	}
			//	else {
			//		return false;
			//	}
			//}
		}
	}
	//Prunning for recurssive: Limited Time Exceeded;
	bool ismatched(const string & s, const string & p, int cur_s, int cur_p) {
		if (cur_s == s.size() && cur_p == p.size()) {
			return true;
		}
		else if (cur_p == p.size() && cur_s != s.size()) {
			return false;
		}
		else if (cur_p != p.size() && cur_s == s.size()) {
			while (cur_p<p.size()) {
				if (p[cur_p++] != '*') {
					return false;
				}
			}
			return true;
		}
		if (p[cur_p] == s[cur_s] || p[cur_p] == '?') {
			return ismatched(s, p, cur_s + 1, cur_p + 1);
		}
		else if (p[cur_p] == '*') {
			while (p[cur_p] == '*') {
				++cur_p;
			}
			bool flag = false;
			std::vector<int> next;
			for (int idx = cur_s; idx <= s.size(); ++idx) {
				if (s[idx] == p[cur_p] || p[cur_p] == '?') {
					flag = flag || ismatched(s, p, idx, cur_p);
				}
			}
			return flag;
		}
		return false;
	}
};

int main() {
	Solution sol;
	
		
	//string s = "acdcb";
	//string p = "a*c?b";
	//string s = "aaabababaaabaababbbaaaabbbbbbabbbbabbbabbaabbababab";
	//string p = "*ab***ba**b*b*aaab*b";
	//string s = "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb";
	//string p = "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb";
	string s = "adceb";
	string p = "*a*b";
	if (sol.isMatch(s, p)) {
		std::cout << "true" << std::endl;
	}
	else {
		std::cout << "false" << std::endl;
	}

	std::cin.get();
	return 0;
}