#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

//time complexity O(n), space complexity O(1);
//use an array to record the occurance num, then slide the window until to the right end;
class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		std::vector<int> char2num(26, 0);
		for (auto & ele : p) {
			++char2num[ele - 'a'];
		}
		vector<int> result;
		vector<int> temp(26, 0);
		for (int idx = 0; idx < s.size(); ++idx) {
			++temp[s[idx] - 'a'];
			if (idx >= p.size()) {
				--temp[s[idx - p.size()] - 'a'];
			}
			if (temp == char2num) {
				result.emplace_back(idx - p.size() + 1);
			}
		}
		return result;
	}
};

int main() {

	cin.get();
	return 0;
}