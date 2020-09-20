#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		if (s.empty()) {
			return 0;
		}
		int last_char_idx = s.find_last_not_of(' ');
		int idx = last_char_idx;
		while (idx>=0) {
			if (s[idx] == ' ') {
				break;
			}
			else {
				--idx;
			}
		}
		if (idx == -1) {
			return last_char_idx + 1;
		}
		else {
			return last_char_idx - idx;
		}
	}
};

int main() {
	string s = "h ";
	std::cout << Solution().lengthOfLastWord(s);
	cin.get();
	return 0;
}