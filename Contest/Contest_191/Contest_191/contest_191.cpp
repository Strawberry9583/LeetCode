#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_set>
#include<queue>

using namespace std;


class Solution1 {
public:
	int maxProduct(vector<int>& nums) {
		int max1 = nums[0], max2 = nums[1];
		if (max1 < max2) {
			std::swap(max1, max2);
		}
		for (int idx = 2; idx < nums.size(); ++idx) {
			if (nums[idx] > max1) {
				max2 = max1;
				max1 = nums[idx];
			}
			else if (nums[idx] > max2) {
				max2 = nums[idx];
			}
		}
		return (max1 - 1)*(max2 - 1);
	}
};

// solution1: sort the cut position and then find the maximum gap.
class Solution2_1 {
public:
	int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
		std::sort(horizontalCuts.begin(), horizontalCuts.end(), [](const int & rhs1, const int& rhs2) {return rhs1 < rhs2; });
		std::sort(verticalCuts.begin(),verticalCuts.end(), [](const int & rhs1, const int& rhs2) {return rhs1 < rhs2; });
		horizontalCuts.insert(horizontalCuts.begin(), 0); horizontalCuts.insert(horizontalCuts.end(), h);
		verticalCuts.insert(verticalCuts.begin(), 0); verticalCuts.insert(verticalCuts.end(), w);
		std::vector<int> gap_h, gap_w;
		gap_h.reserve(horizontalCuts.size()); gap_w.reserve(verticalCuts.size());
		for (int idx = 1; idx < horizontalCuts.size(); ++idx) {
			gap_h.emplace_back(horizontalCuts[idx] - horizontalCuts[idx - 1]);
		}
		for (int idx = 1; idx < verticalCuts.size(); ++idx) {
			gap_w.emplace_back(verticalCuts[idx] - verticalCuts[idx - 1]);
		}
		long long int max_area = (*std::max_element(gap_h.begin(), gap_h.end()))*(*max_element(gap_w.begin(), gap_w.end()));
		return max_area % (long int)(pow(10, 9) + 7);
	}
};


// solution1: BFS
// firsly, transfer the tree into graph with negative and positive num to indicate different directions;
// then just traverse the tree from the node, when encounter the negative num increase the counter;
class Solution3_1 {
	std::vector<std::vector<int>> m_graph;
	std::vector<int> m_visited;
	int m_result = 0;
public:
	int minReorder(int n, vector<vector<int>>& connections) {
		m_graph.assign(n+1, std::vector<int>());
		m_visited.assign(n+1, 0);
		// positive means correct direction, negative means inverse directions;
		for (auto & ele : connections) {
			m_graph[ele[1]+1].emplace_back(ele[0]+1);
			m_graph[ele[0]+1].emplace_back(-1*(ele[1]+1));
		}
		bfs(1);
		return m_result;
	}
	void bfs(int start_idx) {
		std::queue<int> next_que; next_que.push(start_idx); m_visited[start_idx] = 1;
		while (!next_que.empty()) {
			int cur = next_que.front(); next_que.pop();
			for (auto & next : m_graph[cur]) {
				if (m_visited[std::abs(next)] == 0) {
					next_que.push(std::abs(next));
					m_visited[std::abs(next)] = 1;
					if (next < 0) {
						++m_result;
					}
				}
			}
		}

	}
};


// solution1: dfs
// firsly, transfer the tree into graph with negative and positive num to indicate different directions;
// then just traverse the tree from the node, when encounter the negative num increase the counter;
class Solution3_2 {
	std::vector<std::vector<int>> m_graph;
	std::vector<int> m_visited;
	int m_result = 0;
public:
	int minReorder(int n, vector<vector<int>>& connections) {
		m_graph.assign(n + 1, std::vector<int>());
		m_visited.assign(n + 1, 0);
		// positive means correct direction, negative means inverse directions;
		for (auto & ele : connections) {
			m_graph[ele[1] + 1].emplace_back(ele[0] + 1);
			m_graph[ele[0] + 1].emplace_back(-1 * (ele[1] + 1));
		}
		dfs(1);
		return m_result;
	}
	void dfs(int start_idx) {
		if (m_visited[start_idx] == 0) {
			m_visited[start_idx] = 1;
		}
		else {
			return;
		}
		for (auto & next : m_graph[start_idx]) {
			if (m_visited[abs(next)]==0) {
				if (next < 0) {
					++m_result;
				}
				dfs(abs(next));
			}
		}

	}
};
int main() {
	std::vector<std::vector<int>> test_vec = {{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}};
	int n = 6;
	std::cout << Solution3_2().minReorder(n, test_vec);
	cin.get();
	return 0;
}