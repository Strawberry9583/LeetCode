#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

class Solution1 {
public:
	int minCount(vector<int>& coins) {
		int result = 0;
		for (auto & ele : coins) {
			int num = ele / 2;
			if (ele & 1 == 1) {
				++num;
			}
			result += num;
		}
		return result;
	}
};


class Solution2 {
public:
	int numWays(int n, vector<vector<int>>& relation, int k) {
		std::vector<std::vector<int>> neighor_matrix(n, std::vector<int>(n, 0));
		for (auto & pair_ele : relation) {
			neighor_matrix[pair_ele.front()][pair_ele.back()] = 1;
		}
		return dfs(0, k, neighor_matrix);
	}
	int dfs(int start, int depth, std::vector<std::vector<int>> & matrix) {
		if (depth == 0) {
			if (start == matrix.size() - 1) {
				return 1;
			}
			else {
				return 0;
			}
		}
		int result = 0;
		for (int idx = 0; idx < matrix[start].size(); ++idx) {
			if (matrix[start][idx] == 1) {
				result+=dfs(idx, depth - 1, matrix);
			}
		}
		return result;
	}
};

class Solution {
public:
	vector<int> getTriggerTime(vector<vector<int>>& increase, vector<vector<int>>& requirements) {
		std::vector<std::vector<int>> time2value(increase.begin()->size(), std::vector<int>(increase.size(), 0));
		for (int time = 0; time < increase.size(); ++time) {
			if (time == 0) {
				time2value[0][time] = increase[time][0];
				time2value[1][time] = increase[time][1];
				time2value[2][time] = increase[time][2];
			}
			else {
				time2value[0][time] = increase[time][0]+ time2value[0][time-1];
				time2value[1][time] = increase[time][1]+ time2value[1][time-1];
				time2value[2][time] = increase[time][2]+ time2value[2][time-1];
			}
		}
		std::vector<int> result(requirements.size(), 0);
		for (int idx = 0; idx < result.size(); ++idx) {
			result[idx] = get_requirement_idx(requirements[idx], time2value);
		}
		return result;
	}
	int get_requirement_idx(std::vector<int>& requirement, std::vector < std::vector<int>> & time2value) {
		std::vector<int>idx(3,0);
		idx[0] = first_greater_binary_seach(requirement[0], 0, time2value.begin()->size(), time2value[0]);
		idx[1] = first_greater_binary_seach(requirement[1], 0, time2value.begin()->size(), time2value[1]);
		idx[2] = first_greater_binary_seach(requirement[2], 0, time2value.begin()->size(), time2value[2]);
		for (auto &ele : idx) {
			if (ele == time2value.begin()->size()) {
				return -1;
			}
		}
		return *std::max_element(idx.begin(), idx.end());
	}
	//search range [left,right);
	int first_greater_binary_seach(int ele, int left,int right,std::vector<int> & sequence) {
		while (left<right) {
			int mid = left + (right - left) / 2;
			if (ele <= sequence[mid]) {
				right = mid;
			}
			else if (ele > sequence[mid]) {
				left = mid+1;
			}
		}
		return left;
	}
};

int main() {
	//Solution sol;
	//std::vector<std::vector<int>>relation = {{0, 2}, { 2, 1 }};
	//int n = 3, k = 2;
	//std::cout << sol.numWays(n, relation, k);
	Solution sol;
	std::vector<std::vector<int>> increase = { {0, 4, 5}, {4, 8, 8}, {8, 6, 1}, {10, 10, 0} };
	std::vector<std::vector<int>> requirements = { {12, 11, 16}, {20, 2, 6}, {9, 2, 6}, {10, 18, 3}, {8, 14, 9} };
	auto ans=sol.getTriggerTime(increase, requirements);
	std::cin.get();
	return 0;
}