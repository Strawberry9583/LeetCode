#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<queue>
using namespace std;


// solution1: use BFS based graph search;
// Similar to the problem of setting color to the graph nodes;
// Maintain queue to traverse the graph nodes. Everytime pop the queue front, set the inverse
// flag to the new added node, who is the dislike one the poped node. If colored node conflicted, then judge failure.
// Time Complexity : O(N + E), where E is the length of dislikes,
// Space Complexity : O(N + E).
class Solution1 {
public:
	bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
		if (dislikes.empty()) {
			return true;
		}
		std::vector<int> visited(N + 1, 0);
		//transfer the pairwist into the link-list based graph
		std::vector<std::vector<int>> graph(N + 1, std::vector<int>());
		for (int idx = 0; idx < dislikes.size(); ++idx) {
			graph[dislikes[idx][0]].emplace_back(dislikes[idx][1]);
			graph[dislikes[idx][1]].emplace_back(dislikes[idx][0]);
		}
		for (int idx = 1; idx <= N; ++idx) {
			if (visited[idx]!=0) {
				continue;
			}
			// use BFS to search the graph and set the adjacency list with different flag;
			std::queue<int> que; que.push(idx);
			visited[idx] = 1;
			while (!que.empty()) {
				int erase_ele = que.front(); que.pop();
				for (auto & ele : graph[erase_ele]) {
					if (visited[ele] == 0) {
						//set the 
						visited[ele] = -visited[erase_ele];
						que.emplace(ele);
					}
					else if(visited[ele] == visited[erase_ele]) {
						return false;
					}
				}
			}
		}
		return true;
	}
};

// solution2: use DFS based graph search;
// Similar BFS based graph search;
// For each connected component, we can check whether it is bipartite by just trying to coloring it with two colors. 
// How to do this is as follows: color any node red, then all of it's neighbors blue, then all of those neighbors red, and so on. 
// If we ever color a red node blue (or a blue node red), then we've reached a conflict.
class Solution {
private:
	std::vector<int> m_visited;
	std::vector<std::vector<int>> m_graph;
public:
	bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
		if (dislikes.empty()) {
			return true;
		}
		m_visited.assign(N + 1, 0);
		//transfer the pairwist into the link-list based graph
		m_graph.assign(N + 1, std::vector<int>());
		for (int idx = 0; idx < dislikes.size(); ++idx) {
			m_graph[dislikes[idx][0]].emplace_back(dislikes[idx][1]);
			m_graph[dislikes[idx][1]].emplace_back(dislikes[idx][0]);
		}
		for (int idx = 1; idx <= N; ++idx) {
			if (m_visited[idx] == 0) {
				bool if_conflict = !dfs(idx,1);
				if (if_conflict) {
					return false;
				}
			}
		}
		return true;
	}
	// return whether succeeding in coloring, or return false when conflicts occurred;
	bool dfs(int start_idx,int flag) {
		if (m_visited[start_idx] == 0) {
			//set flag (color), then set inverse flag for its linked nodes;
			m_visited[start_idx] = flag;
		}
		else {
			if (m_visited[start_idx] == flag) {
				return true;
			}
			else {
				return false;
			}
		}
		// then set inverse flag for its linked nodes;
		for (auto & ele : m_graph[start_idx]) {
			if (dfs(ele, (-1)*flag)) {
				continue;
			}
			else {
				return false;
			}
		}
		return true;
	}
};


int main() {
	std::vector<std::vector<int>> test_vec = {{1, 2}, {1,3}, {2,4}};
	int n = 4;
	std::cout << Solution().possibleBipartition(n,test_vec);
	cin.get();
	return 0;
}