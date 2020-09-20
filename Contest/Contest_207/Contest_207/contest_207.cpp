#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<functional>
#include<sstream>

using namespace std;

class Solution1 {
public:
	string reorderSpaces(string text) {
		int space_count = 0;
		for (int idx = 0; idx < text.size(); ++idx) {
			if (text[idx] == ' ') {
				++space_count;
			}
		}

		stringstream s(text);
		std::vector<string> all_string;
		string temp;
		while (s>>temp) {
			all_string.emplace_back(temp);
		}
		if (all_string.size() == 0) {
			return text;
		}
		else if (all_string.size() == 1) {
			return all_string.front() + string(space_count, ' ');
		}
		int gap_space = space_count / (all_string.size() - 1);
		int rest_space = space_count - gap_space*(all_string.size() - 1);
		string result;
		for (auto &word : all_string) {
			result += word + string(gap_space, ' ');
		}
		for (int idx = 0; idx < gap_space; ++idx) {
			result.pop_back();
		}
		result += string(rest_space, ' ');
		return result;
	}
};

class Solution2 {
	int m_result = 0;
	string m_origin;
public:
	int maxUniqueSplit(string s) {
		m_origin = s;
		int last_split_idx = -1;
		int cur_idx = 0;
		std::unordered_set<string> occurred_str;
		dfs(cur_idx, last_split_idx, occurred_str);
		return m_result;
	}
private:
	void dfs(int cur_idx, int last_split_idx, std::unordered_set<string>& occurred_str) {
		if (cur_idx == m_origin.size()-1) {
			string cur_string = m_origin.substr(last_split_idx + 1, cur_idx - last_split_idx);
			if (occurred_str.find(cur_string) == occurred_str.end()) {
				occurred_str.emplace(cur_string);
				if (occurred_str.size() > m_result) {
					m_result = occurred_str.size();
				}
				occurred_str.erase(cur_string);
			}
			return;
		}
		string cur_string = m_origin.substr(last_split_idx + 1, cur_idx - last_split_idx);
		if (occurred_str.find(cur_string) == occurred_str.end()) {
			occurred_str.emplace(cur_string);
			dfs(cur_idx + 1, cur_idx, occurred_str);
			occurred_str.erase(cur_string);
			dfs(cur_idx + 1, last_split_idx, occurred_str);
		}
		else {
			dfs(cur_idx + 1, last_split_idx, occurred_str);
		}
		
	}
};


class Solution {
public:
	int maxProductPath(vector<vector<int>>& grid) {
		long long int mod = (1e9) + 7;
		bool if_have_zero = false;
		std::vector<std::vector<pair<long long int, long long int>>> dp(grid.size(), std::vector<pair<long long int, long long int>>(grid.front().size()));
		for (long long int row = 0; row < grid.size(); ++row) {
			for (long long int col = 0; col < grid.front().size(); ++col) {
				if (grid[row][col] == 0) {
					if_have_zero = true;
				}
				if (row == 0 && col == 0) {
					if (grid[row][col] > 0) {
						dp[row][col].first = grid[row][col];
					}
					else {
						dp[row][col].second = grid[row][col];
					}
				}
				else if (row == 0) {
					if (grid[row][col] > 0) {
						dp[row][col].first = dp[row][col - 1].first*grid[row][col];
						dp[row][col].second = dp[row][col - 1].second*grid[row][col];
					}
					else {
						dp[row][col].first = dp[row][col - 1].second*grid[row][col];
						dp[row][col].second = dp[row][col - 1].first*grid[row][col];
					}
				}
				else if (col == 0) {
					if (grid[row][col] > 0) {
						dp[row][col].first = dp[row - 1][col].first*grid[row][col];
						dp[row][col].second = dp[row - 1][col].second*grid[row][col];
					}
					else {
						dp[row][col].first = dp[row - 1][col].second*grid[row][col];
						dp[row][col].second = dp[row - 1][col].first*grid[row][col];
					}
				}
				else {
					if (grid[row][col] > 0) {
						dp[row][col].first = std::max({ dp[row - 1][col].first,dp[row][col - 1].first })*grid[row][col];
						dp[row][col].second = std::min({ dp[row - 1][col].second,dp[row][col - 1].second })*grid[row][col];
					}
					else {
						dp[row][col].first = std::min({ dp[row - 1][col].second,dp[row][col - 1].second })*grid[row][col];
						dp[row][col].second = std::max({ dp[row - 1][col].first,dp[row][col - 1].first })*grid[row][col];
					}
				}
				
			}
		}
		dp.back().back().first%= mod;
		if (if_have_zero) {
			return dp.back().back().first;
		}
		else {
			if (dp.back().back().first == 0) {
				return -1;
			}
			else {
				return dp.back().back().first;
			}
		}
	}
};


int main() {

	//std::string s = "  hello";
	//std::cout << Solution1().reorderSpaces(s);

	//string  s = "aa";
	//std::cout << Solution2().maxUniqueSplit(s);

	std::vector<std::vector<int>> grid = {{1, -1, 0, -3, 4, 3, -3, 3, -1, 3, 0, 0, -4, 2}, {2, -2, -3, -4, 0, -2, -3, 3, 1, 4, 1, -3, -1, -4}, {-4, 4, -4, -4, 2, -4, 3, 0, -2, -4, 3, 4, -1, 0}, {-3, 3, -4, -4, 3, 4, 4, 1, -1, -1, 0, 3, 4, 1}, {1, 3, -4, 2, 2, -3, 1, -3, -4, -4, -1, -4, -4, 4}, {1, 1, -1, 1, -1, -1, 3, -4, -1, 2, -2, 3, -4, 0}, {1, 0, 3, 3, 1, 4, 1, 1, -4, -1, -3, 4, -4, 4}, {4, 3, 2, 3, 0, -1, 2, -4, 1, 0, 0, 1, 3, 4}, {-4, 4, -4, -4, 2, -2, 2, -1, 0, -2, 2, 4, -2, -1}, {-2, 3, 4, -4, 3, 3, -2, -1, 0, -3, 4, -2, -1, -4}, {4, 3, 3, 3, -3, 1, 2, -4, -1, 4, -3, -3, 2, 0}, {3, 3, 0, 1, -4, -4, -3, 3, -2, -4, 2, 4, -3, 3}, {-3, 0, 1, 3, 0, 0, 0, -4, -1, 4, -1, -3, 1, 1}, {-1, 4, 0, -3, 1, -3, -1, 2, 1, -3, -1, -4, 4, 1}};
	std::cout << Solution().maxProductPath(grid);
	cin.get();
	return 0;
}