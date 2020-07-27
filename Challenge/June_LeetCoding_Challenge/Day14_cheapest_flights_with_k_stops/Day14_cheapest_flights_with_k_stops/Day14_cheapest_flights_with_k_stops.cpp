#include<vector>
#include<iostream>
#include<string>
#include<algorithm>

#include<map>
using namespace std;

// solution1: DFS + pruning
class Solution1 {
private:
	std::vector<std::vector<std::pair<int,int>>> m_graph;
	int m_result = std::numeric_limits<int>::max();
	std::vector<int> m_visited;
	std::map<int, int> m;
public:
	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
		m_graph.resize(n, std::vector<std::pair<int,int>>());
		for (auto & flight : flights) {
			m_graph[flight[0]].emplace_back(flight[1], flight[2]);
		}
		int cost = 0;
		m_visited.resize(n, 0);
		m_visited[src] = 1;
		dfs(src, dst, K+1, cost);
		if (m_result == std::numeric_limits<int>::max()) {
			return -1;
		}
		else {
			return m_result;
		}
	}
	void dfs(int src, int dst, int k, int cost) {
		if (src == dst) {
			if (m_result > cost) {
				m_result = cost;
			}
			return;
		}
		else if (m_result < cost || k == 0) {
			return;
		}

		for (int idx = 0; idx < m_graph[src].size(); ++idx) {
			if (m_visited[m_graph[src][idx].first]) {
				continue;
			}
			m_visited[m_graph[src][idx].first] = 1;
			dfs(m_graph[src][idx].first, dst,k-1, m_graph[src][idx].second + cost);
			m_visited[m_graph[src][idx].first] = 0;
		}
	}
};

// Bellman-Ford algorithm
// Time Complexity: O(V*E);
// Relax the path firstly;
// Update the shortest path with intermediate edges;
// Actually the K is the maximum propagation depth;

class Solution {
public:
	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
		std::vector<int> m_inter(n, 1e8);
		m_inter[src] = 0;
		for (int relax_time = 0; relax_time <= K; ++relax_time) {
			// caution: the current relaxation can not use the updated value in this round;
			// so define the temp_inter to store the current relaxation result;
			std::vector<int> temp_inter = m_inter;
			// relaxation one time (propaganda the current shortest one more times)
			for (auto & edge : flights) {
				int inter_distance = m_inter[edge[0]] + edge[2];
				// Caution: campare with lattest shortest path here,
				// to get shortest path in this round or will get the latest shorter path.
				if (inter_distance< temp_inter[edge[1]]) {
					temp_inter[edge[1]] = inter_distance;
				}
			}
			m_inter = temp_inter;
		}
		return m_inter[dst] == 1e8 ? -1 : m_inter[dst];
	}
};


int main() {
	std::vector<std::vector<int>> test_vec{ {0,1,100},{1,2,100},{0,2,500} };
	int src = 0, dst = 2, k = 0;
	std::cout << Solution().findCheapestPrice(test_vec.size(), test_vec, src, dst, k);

	cin.get();
	return 0;
}