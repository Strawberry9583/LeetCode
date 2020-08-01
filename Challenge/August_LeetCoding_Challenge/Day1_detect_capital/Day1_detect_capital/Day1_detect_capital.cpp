#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
	bool detectCapitalUse(string word) {
		bool first_capital_flag = true;
		if (word.front() >= 'a'&&word.front() <= 'z') {
			first_capital_flag = false;
		}
		if (first_capital_flag) {
			for (int idx = 2; idx < word.size(); ++idx) {
				if (word[idx] >= 'a'&&word[idx] <= 'z'&&word[1] >= 'a'&&word[1] <= 'z') {
					continue;
				}
				else if (word[idx] >= 'A'&&word[idx] <= 'Z'&&word[1] >= 'A'&&word[1] <= 'Z') {
					continue;
				}
				else {
					return false;
				}
			}
		}
		else {
			for (int idx = 1; idx < word.size(); ++idx) {
				if (word[idx] >= 'a'&&word[idx] <= 'z') {
					continue;
				}
				else {
					return false;
				}
			}
		}
		return true;

	}
};

int main() {
	cin.get();
	return 0;
}