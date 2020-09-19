#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>

using namespace std;

// find all possible numbers in [0,10^9) in ascending order;
// use binary search to find the bound;
class Solution {
public:
	vector<int> sequentialDigits(int low, int high) {
		std::vector<int> all_possible_num;
		for (int digit_num = 2; digit_num <= 9; ++digit_num) {
			for (int start_num = 1; start_num + digit_num-1 <= 9; ++start_num) {
				int num = 0;
				for (int idx = 0; idx < digit_num; ++idx) {
					num *= 10;
					num += start_num + idx;
				}
				all_possible_num.emplace_back(num);
			}
		}
		auto first_eg = std::lower_bound(all_possible_num.begin(), all_possible_num.end(), low);
		auto last_eg = std::upper_bound(all_possible_num.begin(), all_possible_num.end(),high);
		std::vector<int> result(first_eg, last_eg);
		return result;
	}
};

int main() {
	int low = 1000, high = 13000;
	auto ans = Solution().sequentialDigits(low, high);
	for (auto & ele : ans) {
		std::cout << ele << " ";
	}
	cin.get();
	return 0;
}