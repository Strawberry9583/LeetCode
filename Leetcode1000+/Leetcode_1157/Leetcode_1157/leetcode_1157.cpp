#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>


using namespace std;

// Store indexes in increasing order for each unique element. 
// For query, loop through unique elements and check the 
// number of indices between left and right using the binary search.
// or the indexes can be sorted fistly, then visit the element from the largest ones;
class MajorityChecker {
	std::vector<std::pair<int, vector<int>>> num2idxs;
public:
	MajorityChecker(vector<int>& arr) {
		//store the idx in ascend orders;
		std::unordered_map<int, std::vector<int>> temp_num2idxs;
		for (int idx = 0; idx < arr.size(); ++idx) {
			temp_num2idxs[arr[idx]].emplace_back(idx);
		}
		for (auto & ele : temp_num2idxs) {
			num2idxs.emplace_back(std::move(ele));
		}
		std::sort(num2idxs.begin(), num2idxs.end(), [](const pair<int, std::vector<int>>& rhs1, const pair<int, std::vector<int>> & rhs2) {
			return rhs1.second.size()>rhs2.second.size();
		});
	}
	int query(int left, int right, int threshold) {
		for (auto & ele : num2idxs) {
			//auto ele.second = ele.second;
			if (ele.second.size() < threshold) {
				break;
			}
			auto lower_idx = std::lower_bound(ele.second.begin(), ele.second.end(), left);
			auto upper_idx = std::upper_bound(ele.second.begin(), ele.second.end(), right);
			if (upper_idx - lower_idx >= threshold) {
				return ele.first;
			}
			else {
				continue;
			}
		}
		return -1;
	}
};

int main() {
	cin.get();
	return 0;
}