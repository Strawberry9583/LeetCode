#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
	char findTheDifference(string s, string t) {
		std::vector<int> char2freq1(26, 0), char2freq2(26, 0);
		for (int idx = 0; idx < s.size(); ++idx) {
			++char2freq1[s[idx] - 'a'];
			++char2freq2[t[idx] - 'a'];
		}
		++char2freq2[t.back() - 'a'];
		int idx = 0;
		for (idx = 0; idx < 26; ++idx) {
			if (char2freq1[idx] != char2freq2[idx]) {
				break;
			}
		}
		return 'a' + idx;
	}
};

int main() {
	cin.get();
	return 0;
}