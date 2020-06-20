#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<unordered_map>
using namespace std;

// solution 1: topology sorting with queue;
// Judge wether circle exists in the graph;
// Step1: find the node with 0 in-degree and erase its edges;
// Step2: update the in-degree of nodes, then repeat the step1 until the candidate set is empty;
// Space Complexity: O(N); Time Complexity: O(N+E). 
class Solution1 {
private:
	int m_sorted_num=0;
	std::vector<std::vector<int>> m_graph;
	std::vector<int> m_indegree;
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		m_graph.assign(numCourses, std::vector<int>());
		m_indegree.assign(numCourses, 0);
		for (auto & ele : prerequisites) {
			m_graph[ele[0]].emplace_back(ele[1]);
			++m_indegree[ele[1]];
		}
		std::queue<int> que;
		for (int idx = 0; idx < numCourses; ++idx) {
			if (m_indegree[idx] == 0) {
				que.push(idx);
			}
		}
		while (!que.empty()) {
			int top = que.front(); que.pop();
			++m_sorted_num;
			for (auto & neighor : m_graph[top]) {
				--m_indegree[neighor];
				if (m_indegree[neighor] == 0) {
					que.push(neighor);
				}
			}
		}
		if (m_sorted_num == numCourses) {
			return true;
		}
		else {
			return false;
		}
	}
};

// solution2: use DFS to judge whether circle exists;
// Coutious: to distinguish the visited nodes and the nodes in current path, two flag vector
// should be set: m_visited and path respectively.
// Space Complexity: O(N); Time Complexity: O(N+E). 
class Solution2 {
private:
	std::vector<std::vector<int>> m_graph;
	std::vector<int> m_visited;
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		m_graph.assign(numCourses, std::vector<int>());
		for (auto & ele : prerequisites) {
			m_graph[ele[0]].emplace_back(ele[1]);
		}
		m_visited.assign(numCourses, 0);
		for (int idx = 0; idx < numCourses; ++idx) {
			if (m_visited[idx] == 0) {
				std::vector<int> path(numCourses, 0);
				bool if_succeed = dfs(idx, path);
				if (if_succeed) {
					continue;
				}
				else {
					return false;
				}
			}
		}
		int visit_num = 0;
		for (auto & ele : m_visited) {
			if (ele) {
				++visit_num;
			}
		}
		return visit_num == numCourses;
	}
	// path element indicates the experienced nodes in current single search;
	// pass the path vector by value, will cost more momory but without the need
	// to recover the path status. the replacement method is shown in the following which 
	// passes the path vector by reference, reducing the memory need.
	bool dfs(int start_idx, std::vector<int> path) {
		m_visited[start_idx] = 1;
		//current path have visited the start_idx, then circle exists.
		if (path[start_idx] == 1) {
			return false;
		}
		else {
			path[start_idx] = 1;
		}
		for (auto & neighor : m_graph[start_idx]) {
			if (dfs(neighor, path)) {
				continue;
			}
			else {
				return false;
			}
		}
		return true;
	}
};

// solution3: similar to solution2 which uses DFS to judge whether circle exists;
// the only difference btwn the two solution is than the design of DFS function;
// the following pass the path with reference then after recursion the path state has
// to be recoverred. So set the path[start_idx] = 0 in the end of the recursion.
// Space Complexity: O(N); Time Complexity: O(N+E). 
class Solution {
private:
	std::vector<std::vector<int>> m_graph;
	std::vector<int> m_visited;
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		m_graph.assign(numCourses, std::vector<int>());
		for (auto & ele : prerequisites) {
			m_graph[ele[0]].emplace_back(ele[1]);
		}
		m_visited.assign(numCourses, 0);
		for (int idx = 0; idx < numCourses; ++idx) {
			if (m_visited[idx] == 0) {
				std::vector<int> path(numCourses, 0);
				bool if_succeed = dfs(idx, path);
				if (if_succeed) {
					continue;
				}
				else {
					return false;
				}
			}
		}
		int visit_num = 0;
		for (auto & ele : m_visited) {
			if (ele) {
				++visit_num;
			}
		}
		return visit_num == numCourses;
	}
	// path element indicates the experienced nodes in current single search;
	bool dfs(int start_idx, std::vector<int> & path) {
		m_visited[start_idx] = 1;
		//current path have visited the start_idx, then circle exists.
		if (path[start_idx] == 1) {
			return false;
		}
		else {
			path[start_idx] = 1;
		}
		for (auto & neighor : m_graph[start_idx]) {
			if (dfs(neighor, path)) {
				continue;
			}
			else {
				return false;
			}
		}
		// pass by reference then the path vector has to be recovered.
		path[start_idx] = 0;
		return true;
	}
};

int main() {
	std::vector<std::vector<int>> prerequisite{ {1,0},{0,1} };
	int courseNum = 2;
	std::cout << Solution().canFinish(courseNum, prerequisite);
	cin.get();
	return 0;
}