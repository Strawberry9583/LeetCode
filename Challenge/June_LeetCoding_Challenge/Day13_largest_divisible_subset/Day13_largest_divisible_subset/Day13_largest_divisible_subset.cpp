#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;


// use idx2depthAndRoot to track the longest set and its corresponding idx;
// the i_th pair's first indicates the longest length of sets in range [0,i] when including
// nums[i] element;
// the i_th pair's second indicates the longest set's corresponding root's idx;
class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		if (nums.empty()) {
			return std::vector<int>();
		}
		std::sort(nums.begin(), nums.end(), [](const int &rhs1, const int &rhs2)->bool {return rhs1 > rhs2; });
		// track max Set and pre index
		std::vector<std::pair<int, int>> idx2depthAndRoot(nums.size(), std::pair<int, int>(-1,-1));
		idx2depthAndRoot[0].first = 1;
		idx2depthAndRoot[0].second = -1;
		for (int cur_idx = 1; cur_idx < nums.size(); ++cur_idx) {
			std::pair<int, int> temp{ 0,-1 };
			for (int pre_idx = 0; pre_idx < cur_idx; ++pre_idx) {
				if (nums[pre_idx]%nums[cur_idx]== 0) {
					if (temp.first < idx2depthAndRoot[pre_idx].first) {
						temp.first = idx2depthAndRoot[pre_idx].first;
						temp.second = pre_idx;
					}
				}
			}
			idx2depthAndRoot[cur_idx].first = temp.first + 1;
			idx2depthAndRoot[cur_idx].second = temp.second;
		}
		auto max_depth=std::max_element(idx2depthAndRoot.begin(),idx2depthAndRoot.end(),
			[](const std::pair<int, int> & rhs1, const std::pair<int, int> &rhs2) {return rhs1.first < rhs2.first; });
		std::vector<int> result;
		int start_idx = std::distance(idx2depthAndRoot.begin(), max_depth);
		while (idx2depthAndRoot[start_idx].second!=-1) {
			result.emplace_back(nums[start_idx]);
			start_idx = idx2depthAndRoot[start_idx].second;
		}
		result.emplace_back(nums[start_idx]);
		return result;
	}
};


int main() {
	std::vector<int> test{ 2,3,4,9,8};
	auto ans = Solution().largestDivisibleSubset(test);
	for (auto & ele : ans) {
		cout << ele << " ";
	}
	cin.get();
	return 0;
}