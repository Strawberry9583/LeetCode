#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		int start = 0, end = s.size() - 1;
		while (start < end) {
			while (start < end && !(s[start] >= 'a'&&s[start] <= 'z' || s[start] >= 'A'&&s[start] <= 'Z'||s[start]>='0'&&s[start]<='9')) {
				++start;
			}
			while (start < end && !(s[end] >= 'a'&&s[end] <= 'z' || s[end] >= 'A'&&s[end] <= 'Z'||s[end]>='0'&&s[end]<='9')) {
				--end;
			}
			if (start >= end) {
				return true;
			}
			else if (s[start] >= 'a'&&s[start] <= 'z') {
				if (s[end] != s[start] && (s[end] + 'a' - 'A' != s[start])) {
					return false;
				}
				++start; --end;
			}
			else if(s[start]>='A'&&s[start]<='Z'){
				if (s[end] != s[start] && (s[end] - ('a' - 'A') != s[start])) {
					return false;
				}
				++start; --end;
			}
			else {
				if (s[end] != s[start]) {
					return false;
				}
				++start; --end;
			}
		}
		return true;
	}
};

int main() {
	string s = "0P";
	std::cout << Solution().isPalindrome(s);

	cin.get();
	return 0;
}