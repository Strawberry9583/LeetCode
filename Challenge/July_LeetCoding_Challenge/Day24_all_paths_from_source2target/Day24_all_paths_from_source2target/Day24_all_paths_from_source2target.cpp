#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

// Method: Backtrack;
// traverse the adjacent nodes of cur_nodes before finding the target nodes;
// then record the path and continue to search the path;
// Maximum time complexity: O(2^n), every nodes in the path result will be the worst case.
class Solution {
	std::vector<vector<int>> m_all_paths;
public:
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		int cur_node = 0;
		std::vector<int> cur_path;
		cur_path.emplace_back(cur_node);
		dfs(cur_node, graph,cur_path);
	}
	void dfs(int cur_node, const std::vector<std::vector<int>> & graph, std::vector<int> & cur_path) {
		if (cur_node == graph.size() - 1) {
			m_all_paths.emplace_back(cur_path);
			return;
		}
		else if(cur_path.size() >= graph.size()) {
			return;
		}
		for (const auto & next : graph[cur_node]) {
			// visit the adjacent next node;
			cur_path.emplace_back(next);
			dfs(next, graph, cur_path);
			// restore the status;
			cur_path.pop_back();
		}
	}
};

int main() {
	cin.get();
	return 0;
}