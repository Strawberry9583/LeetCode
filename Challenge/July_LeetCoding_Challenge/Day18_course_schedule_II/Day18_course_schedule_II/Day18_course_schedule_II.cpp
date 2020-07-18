#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

// topology sorting:
// find the node whose indegree num is zero;
// erase the node before erasing all nodes;
// Time complexity: O(N^2), Spce complexity: O(n) exclude the storage of graph;
class Solution1 {
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		std::vector<std::vector<int>> node2indegreenode(numCourses, std::vector<int>());
		std::vector<int>indegreenum(numCourses, 0);
		for (auto & ele : prerequisites) {
			node2indegreenode[ele[1]].emplace_back(ele[0]);
			++indegreenum[ele[0]];
		}
		std::vector<int> result;
		while (true) {
			int zero_node = -1;
			for (int node = 0; node < indegreenum.size(); ++node) {
				if (indegreenum[node] == 0) {
					indegreenum[node] = -1;
					zero_node = node;
					break;
				}
			}
			if (zero_node == -1) {
				break;
			}
			else {
				result.emplace_back(zero_node);
				for (auto & next : node2indegreenode[zero_node]) {
					--indegreenum[next];
				}
			}
		}
		return result.size() == numCourses ? result : std::vector<int>();
	}
};


// BFS topology sorting with queue;
// Time complexity: O(N + E), Spce complexity: O(n) exclude the storage of graph;
class Solution2 {
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		std::vector<std::vector<int>> node2indegreenode(numCourses, std::vector<int>());
		std::vector<int>indegreenum(numCourses, 0);
		for (auto & ele : prerequisites) {
			node2indegreenode[ele[1]].emplace_back(ele[0]);
			++indegreenum[ele[0]];
		}
		// store the unvisited nodes with zero indegree;
		std::queue<int> que_zeroin;
		for (int start = 0; start < numCourses; ++start) {
			if (indegreenum[start] == 0) {
				que_zeroin.emplace(start);
			}
		}
		std::vector<int> result;
		while (!que_zeroin.empty()) {
			int zero_node = que_zeroin.front(); que_zeroin.pop();
			result.emplace_back(zero_node);
			for (auto & next : node2indegreenode[zero_node]) {
				--indegreenum[next];
				// store new nodes with zero indegree;
				if (indegreenum[next] == 0) {
					que_zeroin.emplace(next);
				}
			}
		}
		return result.size() == numCourses ? result : std::vector<int>();
	}
};


class Solution2 {
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		std::vector<std::vector<int>> node2indegreenode(numCourses, std::vector<int>());
		std::vector<int>indegreenum(numCourses, 0);
		for (auto & ele : prerequisites) {
			node2indegreenode[ele[1]].emplace_back(ele[0]);
			++indegreenum[ele[0]];
		}
		// store the unvisited nodes with zero indegree;
		std::queue<int> que_zeroin;
		for (int start = 0; start < numCourses; ++start) {
			if (indegreenum[start] == 0) {
				que_zeroin.emplace(start);
			}
		}
		std::vector<int> result;
		while (!que_zeroin.empty()) {
			int zero_node = que_zeroin.front(); que_zeroin.pop();
			result.emplace_back(zero_node);
			for (auto & next : node2indegreenode[zero_node]) {
				--indegreenum[next];
				// store new nodes with zero indegree;
				if (indegreenum[next] == 0) {
					que_zeroin.emplace(next);
				}
			}
		}
		return result.size() == numCourses ? result : std::vector<int>();
	}
};

// topology sorting with DFS
// with reserve thinking, find whether circle exists from the node;
// when find the node without relying nodes, then push it into the result;
class Solution {
public:
	bool findCycle(vector<vector<int>> &g, deque<bool> &visited, deque<bool> &currStack, int curr, vector<int> &ans) {
		// find  circle existing;
		if (currStack[curr]) return true;
		// find the node without relying nodes;
		if (visited[curr]) return false;
		currStack[curr] = true; visited[curr] = true;
		for (int i = 0; i<g[curr].size(); i++) {
			int v = g[curr][i];
			if (findCycle(g, visited, currStack, v, ans)) return true;
		}
		ans.push_back(curr);
		currStack[curr] = false;
		return false;
	}
	vector<int> findOrder(int n, vector<vector<int>>& A) {
		vector<vector<int>> g(n);
		for (int i = 0; i<A.size(); i++)
			g[A[i][0]].push_back(A[i][1]);
		deque<bool> currStack(n);
		deque<bool> visited(n);
		vector<int> ans;
		for (int i = 0; i<n; i++) {
			if (findCycle(g, visited, currStack, i, ans))
				return {};
		}
		return ans;
	}
};

int main() {

	cin.get();
	return 0;
}