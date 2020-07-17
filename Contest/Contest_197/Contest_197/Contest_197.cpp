#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

// problem1:
// check every pair
// Time complexity: O(n^2); Space complexity:O(1);
class Solution1_1 {
public:
	int numIdenticalPairs(vector<int>& nums) {
		int result = 0;
		for (int left = 0; left < nums.size(); ++left) {
			for (int right = left + 1; right < nums.size(); ++right) {
				if (nums[left] == nums[right]) {
					++result;
				}
			}
		}
		return result;
	}
};

// use hash_map to record the visited ones;
// Time complexity: O(n); Spce complexity: O(n);
class Solution1_2 {
public:
	int numIdenticalPairs(vector<int>& nums) {
		int result = 0;
		std::unordered_map<int, int> num2freq;
		for (int left = 0; left < nums.size(); ++left) {
			auto find_ = num2freq.find(nums[left]);
			if (find_ == num2freq.end()) {
				++num2freq[nums[left]];
			}
			else {
				result += find_->second;
				++num2freq[nums[left]];
			}
		}
		return result;
	}
};

// problem 2: DP
// dp[i] inidicates the number of substring of '1' ended with s[i];
// Time complexity: O(n), Space complexity: O(n);
class Solution2_1 {
public:
	int numSub(string s) {
		std::vector<int> dp(s.size()+1, 0);
		int mod = 1000000007;
		int result = 0;
		for (int idx = 0; idx < s.size(); ++idx) {
			if (s[idx] == '1') {
				dp[idx + 1] = dp[idx]+1;
			}
			result += dp[idx + 1];
			result %= mod;
		}
		return result;
	}
};

// solution2: DP with memory reduction;
// dp indicates the number of previsous substring consiting of '1';
// Time complexity: O(n), Space complexity: O(1);
class Solution2_2 {
public:
	int numSub(string s) {
		
		int dp = 0;
		int mod = 1000000007;
		int result = 0;
		for (int idx = 0; idx < s.size(); ++idx) {
			if (s[idx] == '1') {
				dp= dp + 1;
			}
			else {
				dp = 0;
			}
			result += dp;
			result %= mod;
		}
		return result;
	}
};

// problem 3:
// Solution1:
// BF algrithm + prune;
// Time complexity: O(N*E), Space complexity: O(N)
// N and E is the number of vertices and edges;
class Solution3_1 {
public:
	double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
		std::vector<double> next_max(n, 0.); next_max[start] = 1.0;
		int iter = 0;
		// flag to reduce computation;
		// if preivous iteration didn't update, stop calc.
		bool flag = true;
		while (iter<n-1) {
			flag = false;
			for (int edge_idx = 0; edge_idx < edges.size(); ++edge_idx) {
				// due to the undirected graph, the in-node and out-node both should be checked;
				if (succProb[edge_idx] * next_max[edges[edge_idx][0]] > next_max[edges[edge_idx][1]]) {
					next_max[edges[edge_idx][1]] = succProb[edge_idx] * next_max[edges[edge_idx][0]];
					flag = true;
				}
				// due to the undirected graph, the in-node and out-node both should be checked;
				if (succProb[edge_idx] * next_max[edges[edge_idx][1]] > next_max[edges[edge_idx][0]]) {
					next_max[edges[edge_idx][0]] = succProb[edge_idx] * next_max[edges[edge_idx][1]];
					flag = true;
				}
			}
			++iter;
		}
		return next_max[end];
	}
};

// problem 3:
// Solution2: SPFA algrithm
// Time complexity: O(N*E), Space complexity: O(N)
// N and E is the number of vertices and edges;
class Solution3_2 {
public:
	double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
		//transfer the edge into graph;
		std::vector<std::vector<std::pair<int,double>>> graph(n,std::vector<std::pair<int,double>>());
		for (int node_idx = 0; node_idx < n; ++node_idx) {
			graph[node_idx].emplace_back(node_idx,1.0);
		}
		// add the neighbor node into the link-list graph;
		for (int edge_idx = 0; edge_idx < edges.size(); ++edge_idx) {
			graph[edges[edge_idx][0]].emplace_back(edges[edge_idx][1],succProb[edge_idx]);
			graph[edges[edge_idx][1]].emplace_back(edges[edge_idx][0], succProb[edge_idx]);

		}
		// indicates the current shortest path from start to other nodes;
		std::vector<double> next_max(n, 0.); next_max[start] = 1.0; 
		std::queue<int> que; que.emplace(start);
		// indicat whether the nodes exsits in queue;
		std::vector<int> visited(n, 0); visited[start] = 1;
		while (!que.empty()) {
			// get the updated node;
			int update_node = que.front(); que.pop();
			visited[update_node] = 0;
			// check the neighor of the updated nodes;
			for (int neighbor_idx = 0; neighbor_idx < graph[update_node].size(); ++neighbor_idx) {
				// update for maximum possibility;
				if (next_max[update_node] * graph[update_node][neighbor_idx].second > next_max[graph[update_node][neighbor_idx].first]) {
					que.emplace(graph[update_node][neighbor_idx].first);
					visited[graph[update_node][neighbor_idx].first];
					next_max[graph[update_node][neighbor_idx].first] = next_max[update_node] * graph[update_node][neighbor_idx].second;
				}
			}
		}
		return next_max[end];
	}
};



// problem 3:
// Solution3: Dijstra algrithm
// Time complexity: O(N^2), Space complexity: O(N)
// N and E is the number of vertices and edges;
class Solution3_3 {
public:
	double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
		//transfer the edge into graph;
		std::vector<std::vector<std::pair<int, double>>> graph(n, std::vector<std::pair<int, double>>());
		for (int node_idx = 0; node_idx < n; ++node_idx) {
			graph[node_idx].emplace_back(node_idx, 1.0);
		}
		// add the neighbor node into the link-list graph;
		for (int edge_idx = 0; edge_idx < edges.size(); ++edge_idx) {
			graph[edges[edge_idx][0]].emplace_back(edges[edge_idx][1], succProb[edge_idx]);
			graph[edges[edge_idx][1]].emplace_back(edges[edge_idx][0], succProb[edge_idx]);

		}
		// indicating the current shortest path from start to other nodes;
		std::vector<double> next_max(n, 0.); next_max[start] = 1.0;
		// indicating whether the nodes exsits in visited set;
		std::vector<int> visited(n, 0);
		//each time get one nodes;
		for (int idx = 0; idx < n; ++idx) {
			//get the nearest (with maximum ratio) unvisited node from start node;
			std::pair<int, double> maxidx_ratio(-1, -0.1);
			for (int node_idx = 0; node_idx < n; ++node_idx) {
				if (!visited[node_idx] && next_max[node_idx] > maxidx_ratio.second) {
					maxidx_ratio.first = node_idx;
					maxidx_ratio.second = next_max[node_idx];
				}
			}
			visited[maxidx_ratio.first] = 1;
			//consider the maxidx.first as intermediate node, update the next_max;
			for (int node_idx = 1; node_idx < graph[maxidx_ratio.first].size(); ++node_idx) {
				if (next_max[graph[maxidx_ratio.first][node_idx].first] < next_max[maxidx_ratio.first] * graph[maxidx_ratio.first][node_idx].second) {
					next_max[graph[maxidx_ratio.first][node_idx].first] = next_max[maxidx_ratio.first] * graph[maxidx_ratio.first][node_idx].second;
				}
			}
		}
		return next_max[end];
	}
};

// problem 3:
// Solution4: modified Dijstra algrithm
// Time complexity: O(N^2), Space complexity: O(N)
// N and E is the number of vertices and edges;
// pick the node with maximum possibility first;
class Solution3_4 {
public:
	double maxProbability(int n, vector<vector<int>>& edges, vector<double>& pro, int start, int end) {
		vector<vector<pair<int, double>>> g(n);
		for (int i = 0; i<edges.size(); i++) {
			g[edges[i][0]].push_back({ edges[i][1], pro[i] });
			g[edges[i][1]].push_back({ edges[i][0], pro[i] });
		}
		vector<int> seen(n, 0);

		priority_queue<pair<double, int>> q;
		q.push({ (double)1.0, start });

		vector<double> mx(n, (double)0.0);
		mx[start] = 1.0;

		while (!q.empty()) {
			auto top = q.top();
			q.pop();
			double proba = top.first;
			int node = top.second;
			if (!seen[node]) {
				seen[node]++;
				for (auto &to : g[node]) {
					if (mx[to.first] < to.second*proba) {
						mx[to.first] = to.second*proba;
						q.push({ mx[to.first], to.first });
					}
				}
			}
		}
		return mx[end];
	}
};

// problem 4:
// zoom-in to get approximate optima solution;
// Search a big area with lower precision, Once get the closest point, we search around this point with higher precision
// first choose one big square,
// then divide it into many smaller ones until meet the precision requirement;
class Solution4 {
public:
	double getMinDistSum(vector<vector<int>>& pos) {
		double left = 100, bottom = 100, right = 0, top = 0;
		for (auto &p : pos) {
			left = min(left, (double)p[0]);
			bottom = min(bottom, (double)p[1]);
			right = max(right, (double)p[0]);
			top = max(top, (double)p[1]);
		}
		double res = DBL_MAX, res_x = 0, res_y = 0;
		for (double delta = 10; delta >= 0.00001; delta /= 10) {
			for (double x = left; x <= right; x += delta)
				for (double y = bottom; y <= top; y += delta) {
					double d = 0;
					for (auto &p : pos)
						d += sqrt((p[0] - x) * (p[0] - x) + (p[1] - y) * (p[1] - y));
					if (res > d) {
						res = d;
						res_x = x;
						res_y = y;
					}
				}
			left = res_x - delta;
			bottom = res_y - delta;
			right = res_x + delta;
			top = res_y + delta;
		}
		return res == DBL_MAX ? 0 : res;
	}
};



int main() {
	//string s = "0110111";
	//std::cout << Solution().numSub(s);


	std::vector<std::vector<int>> edge = { {1, 4}, {2, 4}, {0, 4}, {0, 3}, {0, 2}, {2, 3} };
	std::vector<double> pro = { 0.37, 0.17, 0.93, 0.23, 0.39, 0.04 };
	int n = 5;
	int start = 3, end = 4;
	std::cout << Solution().maxProbability(n, edge, pro, start, end);
	cin.get();
	return 0;
}