#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;


class Solution {
public:
	int longestPalindrome(string s) {
		std::unordered_map<char, int> num2freq;
		for (const auto & ele : s) {
			++num2freq[ele];
		}
		int result = 0;
		bool odd_flag = false;
		for (const auto & ele : num2freq) {
			if (ele.second%2) {
				result += ele.second - 1;
				odd_flag = true;
			}
			else  {
				result += ele.second;

			}
		}
		return odd_flag ? result + 1 : result;
	}
};

int main() {


	cin.get();
	return 0;
}