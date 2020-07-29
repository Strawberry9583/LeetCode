#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		if (intervals.size() < 2) {
			return intervals;
		}
		std::sort(intervals.begin(), intervals.end(), \
			[](const std::vector<int> & rhs1, const std::vector<int>& rhs2)-> bool {return rhs1[0] == rhs2[0] ? rhs1[1] < rhs2[1] : rhs1[0] < rhs2[0];	});
		std::vector<std::vector<int>> result;
		int pre_idx = 0, cur_idx = 1;
		std::pair<int, int> pre_range(intervals[pre_idx][0], intervals[pre_idx][1]);

		for (; cur_idx < intervals.size(); ++cur_idx) {
			std::pair<int, int> cur_range(intervals[cur_idx][0], intervals[cur_idx][1]);
			if (pre_range.second >= cur_range.first) {
				//combine the two into one;
				if (pre_range.second < cur_range.second) {
					pre_range.second = cur_range.second;
				}
			}
			else {
				result.emplace_back(std::move(std::vector<int>{pre_range.first, pre_range.second}));
				pre_range = cur_range;
			}
			//++cur_idx;
			//cur_range.first = intervals[cur_idx][0];
			//cur_range.second = intervals[cur_idx][1];
		}
		result.emplace_back(std::move(std::vector<int>{pre_range.first, pre_range.second}));
		return result;
	}
};


int main() {
	Solution sol;
	std::vector<std::vector<int>> test{ {1,3},{2,6},{8,10},{15,18} };
	auto ans = sol.merge(test);
	std::cin.get();
	return 0;
}