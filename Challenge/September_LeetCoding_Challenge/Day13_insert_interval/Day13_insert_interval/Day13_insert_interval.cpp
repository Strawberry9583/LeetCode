#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

// firstly, put the non-overlap range in the left;
// secondly, merge the range;
// thirdly, put the non-overlap range in the right;
class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		std::vector < std::vector<int>> result;
		int pre_idx = 0;
		for (; pre_idx < intervals.size()&& intervals[pre_idx][1] < newInterval[0]; ++pre_idx) {
			result.emplace_back(intervals[pre_idx]);
		}
		int post_idx = pre_idx ;
		for (; post_idx <intervals.size()&&newInterval[1]>=intervals[post_idx][0]; ++post_idx) {
			newInterval[0] = std::min(newInterval[0], intervals[post_idx][0]);
			newInterval[1] = std::max(newInterval[1], intervals[post_idx][1]);
		}
		result.emplace_back(newInterval);
		for (; post_idx < intervals.size(); ++post_idx) {
			result.emplace_back(intervals[post_idx]);
		}
		return result;
	}
};

int main() {
	std::vector<std::vector<int>> intervals = {{1, 3},{6,9}};
	std::vector<int> newIntervals = { 2,5 };
	auto ans = Solution().insert(intervals, newIntervals);
	for (auto& inter : ans) {
		for (auto & ele : inter) {
			std::cout << ele << " ";
		}
		std::cout << std::endl;
	}
	cin.get();
	return 0;
}