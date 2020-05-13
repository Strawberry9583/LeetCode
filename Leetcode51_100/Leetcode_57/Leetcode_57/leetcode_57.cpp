#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		if (intervals.empty()) {
			std::vector<std::vector<int>>result;
			result.emplace_back(std::move(newInterval));
			return result;
		}
		//record the insert position and erased range;
		int insert_pre = -1;
		int insert_cur = 0;
		std::vector<int> newrange{newInterval[0], newInterval[1]};
		for (int cur_idx = 0; cur_idx < intervals.size();) {
			if (intervals[cur_idx][0] <= newrange[0] && newrange[0] <= intervals[cur_idx][1]) {
				newrange[0] = intervals[cur_idx][0];
				if (intervals[cur_idx][1] > newrange[1]) {
					newrange[1] = intervals[cur_idx][1];
				}
				if (insert_pre < 0) {
					insert_pre = cur_idx;
				}
				//cur_idx plus 1; 
				//because the vector.erase function  erase the range [begin,end) not [begin,end]
				insert_cur = cur_idx+1;
				++cur_idx;
			}
			else if (intervals[cur_idx][0] >= newrange[0] && intervals[cur_idx][0] <= newrange[1]) {
				if (newrange[1] < intervals[cur_idx][1]) {
					newrange[1] = intervals[cur_idx][1];
				}
				if (insert_pre < 0) {
					insert_pre = cur_idx;
				}
				insert_cur = cur_idx+1;
				++cur_idx;
			}
			else if(newrange[1]<intervals[cur_idx][0]){
				if (insert_pre < 0) {
					insert_pre = cur_idx;
					insert_cur = cur_idx;
					break;
				}
				else {
					insert_cur = cur_idx;
					break;
				}
			}
			else if (newrange[0] > intervals[cur_idx][1]) {
				++cur_idx;
			}
		}
		//found no insert position; then emplace_back;
		if (insert_pre < 0) {
			intervals.emplace_back(newrange);
		}
		else {
			intervals.erase(intervals.begin() + insert_pre, intervals.begin() + insert_cur );
			intervals.emplace(intervals.begin() + insert_pre, newrange);
		}
		return intervals;
	}
};

int main() {
	Solution sol;
	//std::vector<std::vector<int>> test{ {1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16} };
	//std::vector<int> insert_range{ 4,8 };
	std::vector<std::vector<int>> test{ {1, 5}};
	std::vector<int> insert_range{6,8};
	auto ans = sol.insert(test, insert_range);
	std::cin.get();
	return 0;
}