#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<unordered_set>
using namespace std;

class Solution {
public:
	string getHint(string secret, string guess) {
		int bull_num = 0;
		std::vector<int> bull_flag(secret.size(), 0);
		unordered_map<char,int> possible_cow;
		for (int idx = 0; idx < secret.size(); ++idx) {
			if (secret[idx] == guess[idx]) {
				++bull_num;
				bull_flag[idx] = 1;
			}
			else {
				++possible_cow[secret[idx]];
			}
		}
		int cow_num = 0;
		for (int idx = 0; idx < guess.size(); ++idx) {
			if (bull_flag[idx] == 0 && possible_cow.find(guess[idx]) != possible_cow.end()) {
				++cow_num;
				--possible_cow[guess[idx]];
				if (possible_cow[guess[idx]] == 0) {
					possible_cow.erase(guess[idx]);
				}
			}
		}
		return std::to_string(bull_num) + "A" + std::to_string(cow_num) + "B";
	}
};

int main() {
	string  secret = "1123", guess = "0111";
	std::cout << Solution().getHint(secret, guess);
	cin.get();
	return 0;
}