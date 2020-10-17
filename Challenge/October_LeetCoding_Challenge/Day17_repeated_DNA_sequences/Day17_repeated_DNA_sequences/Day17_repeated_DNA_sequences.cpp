#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
#include<string>
#include<unordered_set>
#include<unordered_map>
using namespace std;


class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		std::vector<string> result;
		std::unordered_map<string, int> string_freq;
		for (int idx = 0; idx + 9 < s.size(); ++idx) {
			auto sub_s = s.substr(idx, 10);
			++string_freq[sub_s];
			if (string_freq[sub_s] == 2) {
				result.emplace_back(std::move(sub_s));
			}
		}
		return result;
	}
};

int main() {
	cin.get();
	return 0;
}