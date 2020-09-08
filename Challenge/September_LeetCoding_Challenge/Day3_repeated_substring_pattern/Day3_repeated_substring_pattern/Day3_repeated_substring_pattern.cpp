#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;


class Solution1 {
public:
	bool repeatedSubstringPattern(string s) {
		for (int divide = 1; divide<s.size() ; ++divide) {
			if (s.size() % divide == 0) {
				if (check(s, divide)) {
					return true;
				}
			}
			else {

			}
		}
		return false;
	}
private:
	bool check(const string & s, int length) {
		for (int idx = 0; idx < s.size(); ++idx) {
			if (s[idx] == s[idx%length]) {
				continue;
			}
			else {
				return false;
			}
		}
		return true;
	}
};


class Solution {
public:
	bool repeatedSubstringPattern(string str) {
		int n = str.length();
		for (int i = 1; i <= n / 2; i++)
			if (n % i == 0 && str.substr(i) == str.substr(0, n - i))
				return true;
		return false;
	}
};

int main() {
	string s = "abaccbab";
	std::cout << Solution().repeatedSubstringPattern(s);


	cin.get();
	return 0;
}
