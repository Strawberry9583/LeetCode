#include<iostream>
#include<deque>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


class Solution {
	std::unordered_map<string, int> str2idx;
	std::vector<std::vector<pair<int, double>>> graph;
public:
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

		for (int idx = 0; idx < equations.size(); ++idx) {
			if (str2idx.find(equations[idx][1]) == str2idx.end()) {
				str2idx[equations[idx][1]] = str2idx.size();
			}
			if (str2idx.find(equations[idx][0]) == str2idx.end()) {
				str2idx[equations[idx][0]] = str2idx.size();
			}
		}
		graph.resize(str2idx.size());
		for (int idx = 0; idx < equations.size(); ++idx) {
			int start = str2idx[equations[idx][0]], end = str2idx[equations[idx][1]];
			graph[start].emplace_back(end, values[idx]);
			graph[end].emplace_back(start, 1.0alues[idx]);
		}
		std::vector<double> result(queries.size());
		for (int idx = 0; idx < result.size(); ++idx) {
			if (str2idx.find(queries[idx][0]) == str2idx.end() || str2idx.find(queries[idx][1]) == str2idx.end()) {
				result[idx] = -1.0;
				continue;
			}
			int start = str2idx[queries[idx][0]], end = str2idx[queries[idx][1]];
			if (start == end) {
				result[idx] = 1.0;
				continue;
			}
			else {
				std::deque<bool> flag(graph.size(), false);
				flag[start] = true;
				double cur_length = dfs(start, end, flag, start);
				if (cur_length == 0) {
					result[idx] = -1.0;
				}
				else {
					result[idx] = cur_length;
				}
			}
		}
		return result;
	}
private:
	double dfs(int start, int end, std::deque<bool>& flag, int cur_node) {
		if (cur_node == end) {
			return 1.0;
		}
		else {
			for (int idx = 0; idx < graph[cur_node].size(); ++idx) {
				auto next = graph[cur_node][idx];
				if (flag[next.first]) {
					continue;
				}
				else {
					flag[next.first] = true;
					double length = next.second*dfs(start, end, flag, next.first);
					if (length != 0) {
						return length;
					}
					else {
						flag[next.first] = false;
					}
				}
			}
			return 0;
		}
	}
};

int main() {
	std::vector<std::vector<string>>equations = { {"a", "b"} };
	std::vector<double> values = { 0.5 };
	std::vector<std::vector<string>> queries = { {"a", "b"}, {"b", "a"}, {"a", "c"}, {"x", "y"} };
	auto ans = Solution().calcEquation(equations, values, queries);
	for (auto &ele : ans) {
		std::cout << ele << " ";
	}
	cin.get();
	return 0;
}