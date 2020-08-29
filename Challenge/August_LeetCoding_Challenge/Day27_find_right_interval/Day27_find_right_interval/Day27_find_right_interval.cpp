#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
	vector<int> findRightInterval(vector<vector<int>>& intervals) {
		std::vector<std::vector<int>> s_intervals(intervals.size());
		for (int idx = 0; idx < intervals.size(); ++idx) {
			std::vector<int> interv_idx(intervals[idx]);
			interv_idx.emplace_back(idx);
			s_intervals[idx] = std::move(interv_idx);
		}
		std::vector<std::vector<int>> f_intervals(s_intervals);
		std::sort(s_intervals.begin(), s_intervals.end(), [](const vector<int>& rhs1, const std::vector<int>& rhs2) {
			return rhs1[1] < rhs2[1]; });
		std::sort(f_intervals.begin(), f_intervals.end(), [](const std::vector<int>& rhs1, const std::vector<int>& rhs2) {
			return rhs1[0] < rhs2[0]; });
		std::vector<std::pair<int, int>> fidxAndsidx(intervals.size());
		for (int idx = 0; idx < fidxAndsidx.size(); ++idx) {
			fidxAndsidx[f_intervals[idx][2]].first = idx;
			fidxAndsidx[s_intervals[idx][2]].second = idx;
		}
		std::vector<int> sidx2fidx(intervals.size());
		for (auto & ele : fidxAndsidx) {
			sidx2fidx[ele.second] = ele.first;
		}
		std::vector<int> result(intervals.size());
		for (int idx = 0; idx < s_intervals.size(); ++idx) {
			std::vector<int> cur = s_intervals[idx];
			cur[0] = cur[1];
			auto first_eq=std::lower_bound(f_intervals.begin()+sidx2fidx[idx]+1,f_intervals.end(),cur, [](const vector<int>& rhs1, const std::vector<int>& rhs2) {
				return rhs1[0] < rhs2[0]; });
			if (first_eq == f_intervals.end()) {
				result[s_intervals[idx][2]] = -1;
			}
			else {
				result[s_intervals[idx][2]] = (*first_eq)[2];
			}
		}
		return result;
	}
};


int main() {
	std::vector<std::vector<int>> test_vec{ {1,4},{2,3},{3,4} };
	auto ans = Solution().findRightInterval(test_vec);
	for (auto &ele : ans) {
		std::cout << ele << " ";
	}
	cin.get();
	return 0;
}