#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// method1: dp;
class Solution1 {
public:
	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		if (intervals.empty()) {
			return 0;
		}
		int range_min = std::numeric_limits<int>::max(), range_max = std::numeric_limits<int>::lowest();

		for (int idx = 0; idx < intervals.size(); ++idx) {
			if (intervals[idx][0] < range_min) {
				range_min = intervals[idx][0];
			}
			if (intervals[idx][1] > range_max) {
				range_max = intervals[idx][1];
			}
		}
		if (range_min < 0) {
			for (int idx = 0; idx < intervals.size(); ++idx) {
				intervals[idx][0] -= range_min;
				intervals[idx][1] -= range_min;
			}
			range_max -= range_min;
		}
		std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& rhs1, const vector<int>& rhs2)
		{return rhs1[1] == rhs2[1] ? rhs1[0] > rhs1[0]:rhs1[1] < rhs2[1]; });

		std::vector<int> dp(range_max + 1, 0);
		int result = 0, interval_idx = 0;
		for (int pos = 0; pos < dp.size(); ) {
			if (intervals[interval_idx][1] == pos) {
				dp[intervals[interval_idx][1]] = std::max(result, dp[intervals[interval_idx][0]] + 1);
				if (dp[intervals[interval_idx][1]] > result) {
					result = dp[intervals[interval_idx][1]];
				}
				++interval_idx;
				if (interval_idx == intervals.size()) {
					break;
				}
			}
			else {
				dp[pos] = result;
				++pos;
			}

		}
		return intervals.size() - result;
	}
};

// method2: Greedy solution:
//  56 Merge Intervals < -very similar, i did it with just 3 lines different
//	252 Meeting Rooms
//	253 Meeting Rooms II
//	452 Minimum Number of Arrows to Burst Balloons
class Solution {
public:
	int eraseOverlapIntervals(vector<std::vector<int>>& intervals) {
		if (intervals.empty()) {
			return 0;
		}
		auto comp = [](const std::vector<int>& i1, const std::vector<int>& i2) { return i1[1] < i2[1]; };
		sort(intervals.begin(), intervals.end(), comp);
		int result = 1, pre_end = intervals[0][1];
		for (int i = 1; i < intervals.size(); i++) {
			if (intervals[i][0] >= pre_end) {
				++result;
				pre_end = intervals[i][1];
			}
			else {

			}
		}
		return intervals.size()-result;
	}
};

int main() {
	std::vector<std::vector<int>> test_vec = { {1, 100}, {11, 22}, {1, 11}, {2, 12} };
	std::cout << Solution().eraseOverlapIntervals(test_vec);

	cin.get();
	return 0;
}