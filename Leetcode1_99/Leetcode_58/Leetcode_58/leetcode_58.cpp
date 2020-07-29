#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		int last_character_idx=s.size()-1;
		int last_word_start_idx;
		for (; last_character_idx >= 0; --last_character_idx) {
			if (s[last_character_idx] != ' ') {
				break;
			}
		}
		if (last_character_idx < 0) {
			return 0;
		}
		for (last_word_start_idx = last_character_idx; last_word_start_idx >= 0; --last_word_start_idx) {
			if (s[last_word_start_idx] == ' ') {
				break;
			}
		}
		return last_character_idx - last_word_start_idx;
	}
};


int main() {
	Solution sol;

	std::cin.get();
	return 0;
}