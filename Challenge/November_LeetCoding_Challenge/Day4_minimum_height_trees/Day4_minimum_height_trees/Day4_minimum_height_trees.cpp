#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
	std::vector<int> m_result;
	int m_cur_min_height;
	std::vector<std::vector<int>> linked_graph;
	std::vector<int> m_cur_max_distance;
public:
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		linked_graph.resize(n);
		m_cur_max_distance.resize(n, 0);
		for (auto & edge : edges) {
			linked_graph[edge.front()].emplace_back(edge.back());
			linked_graph[edge.back()].emplace_back(edge.front());
		}
		m_cur_min_height = 10e5;
		for (int root = 0; root<n; ++root) {
			if (m_cur_max_distance[root] <= m_cur_min_height+1) {
				std::vector<int> visit_flag(n, 0);
				int cur_depth = 0;
				int height = dfs(root, visit_flag, cur_depth);
				if (m_cur_min_height>height) {
					m_cur_min_height = height;
					m_result.clear();
					m_result.emplace_back(root);
				}
				else if (m_cur_min_height == height) {
					m_result.emplace_back(root);
				}
			}
		}
		return m_result;
	}
private:
	int dfs(int cur_node, std::vector<int> & visit_flag, int cur_depth) {
		if (cur_depth>m_cur_min_height) {
			if (m_cur_max_distance[cur_node] < cur_depth) {
				m_cur_max_distance[cur_node] = cur_depth;
			}
			return 10e5;
		}
		if (visit_flag[cur_node] == 1) {
			if (m_cur_max_distance[cur_node] < cur_depth-1) {
				m_cur_max_distance[cur_node] = cur_depth-1;
			}
			return cur_depth;
		}
		else {
			visit_flag[cur_node] = 1;
			int depth = 0;
			for (auto & next : linked_graph[cur_node]) {
				int temp = dfs(next, visit_flag, cur_depth + 1);
				if (temp>depth) {
					depth = temp;
					if (depth>m_cur_min_height) {
						return 10e5;
					}
				}

			}
			if (m_cur_max_distance[cur_node] < depth) {
				m_cur_max_distance[cur_node] = depth;
			}
			return depth;
		}
	}
};



class Solution1 {
	std::vector<int> m_result;
	int m_cur_min_height;
	std::vector<std::vector<int>> linked_graph;
public:
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		linked_graph.resize(n);
		for (auto & edge : edges) {
			linked_graph[edge.front()].emplace_back(edge.back());
			linked_graph[edge.back()].emplace_back(edge.front());
		}
		m_cur_min_height = 10e5;
		for (int root = 0; root<n; ++root) {
			std::vector<int> visit_flag(n, 0);
			int cur_depth = 0;
			int height = dfs(root, visit_flag, cur_depth);
			if (m_cur_min_height>height) {
				m_cur_min_height = height;
				m_result.clear();
				m_result.emplace_back(root);
			}
			else if (m_cur_min_height == height) {
				m_result.emplace_back(root);
			}
		}
		return m_result;
	}
private:
	int dfs(int cur_node, std::vector<int> & visit_flag, int cur_depth) {
		if (cur_depth>m_cur_min_height) {
			return 10e5;
		}
		if (visit_flag[cur_node] == 1) {
			return cur_depth;
		}
		else {
			visit_flag[cur_node] = 1;
			int depth = 0;
			for (auto & next : linked_graph[cur_node]) {
				int temp = dfs(next, visit_flag, cur_depth + 1);
				if (temp>depth) {
					depth = temp;
					if (depth>m_cur_min_height) {
						return 10e5;
					}
				}
			}
			return depth;
		}
	}
};

int main() {
	int n = 5;
	std::vector<std::vector<int>> edges = { {0,1},{0,2},{0,3},{3,4} };
	auto ans = Solution().findMinHeightTrees(n, edges);
	for (auto & ele : ans) {
		std::cout << ele << " ";
	}
	cin.get();
	return 0;
}