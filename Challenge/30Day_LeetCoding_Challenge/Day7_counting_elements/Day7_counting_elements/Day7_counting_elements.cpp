#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<array>

using namespace std;


class Solution1 {
public:
	int countElements(vector<int>& arr) {
		if (arr.size() < 2) {
			return 0;
		}
		int cur_idx = 1;
		int result = 0;
		int same_num = 1;
		std::sort(arr.begin(), arr.end());
		for (; cur_idx < arr.size(); ++cur_idx) {
			if (arr[cur_idx-1] == arr[cur_idx]) {
				++same_num;
			}
			else if (arr[cur_idx-1] + 1 == arr[cur_idx]) {
				result+=same_num;
				same_num = 1;
				//pre_idx = cur_idx;
			}
			else {
				same_num = 1;
			}
		}
		return result;
	}
};

class Solution2 {
public:
	int countElements(vector<int>& arr) {
		if (arr.size() < 2) {
			return 0;
		}
		int result = 0;
		//use array to record the occurance of nums;
		std::array<int, 1001> num_counts{};
		num_counts.fill(0);
		for (auto & ele : arr) {
			++num_counts[ele];
		}
		for (int idx = 1; idx < num_counts.size(); ++idx) {
			if (num_counts[idx] != 0) {
				result += num_counts[idx - 1];
			}
		}
		return result;
	}
};

class Solution3 {
public:
	int countElements(vector<int>& arr) {
		if (arr.size() < 2) {
			return 0;
		}
		int result = 0;
		//use hash_map to record the occurance of nums;
		std::unordered_map<int, int> num_counts;
		for (auto & ele : arr) {
			++num_counts[ele];
		}
		for (auto & ele : num_counts) {
			if (num_counts.find(ele.first-1) != num_counts.end()) {
				result += num_counts[ele.first - 1];
			}
			
		}
		return result;
	}
};

int main() {
	Solution3 sol;
	std::vector<int> test{ 1,1,2,2};
	std::cout << sol.countElements(test);

	std::cin.get();
	return 0;
}