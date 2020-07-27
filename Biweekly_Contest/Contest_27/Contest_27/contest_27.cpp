#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;


// solution1: check the frequency of two array;
class Solution1_1 {
public:
	bool canBeEqual(vector<int>& target, vector<int>& arr) {
		std::unordered_map<int, int> num2freq;
		for (auto & ele : target) {
			++num2freq[ele];
		}
		for (auto & ele : arr) {
			auto  find = num2freq.find(ele);
			if (find == num2freq.end()) {
				return false;
			}
			else {
				--num2freq[ele];
				if (num2freq[ele] == 0) {
					num2freq.erase(find);
				}
			}
		}
		return num2freq.empty();
	}
};

// solution 2: sort + comparing;
class Solution1_2 {
public:
	bool canBeEqual(vector<int>& target, vector<int>& arr) {
		std::sort(target.begin(), target.end());
		std::sort(arr.begin(), arr.end());
		return target == arr;
	}
};

// use hash set to record all occurance of string;
// then check whether the num of different string is equal to 2^k;
// Time compelxity: O(n) where n is the length of the string.
class Solution2_1 {
public:
	bool hasAllCodes(string s, int k) {
		std::unordered_set<string> contain;
		for (int idx = 0; idx + k <= s.size(); ++idx) {
			string temp = s.substr(idx, k);
			if (contain.find(temp) == contain.end()) {
				contain.emplace(temp);
				if (contain.size() == std::pow(2, k)) {
					return true;
				}
			}
			else {
				continue;
			}
		}
		return false;
	}
};

// use hash set to record all occurance of num;
// the comparing is more efficent to campare the num but not string;
class Solution2_2 {
public:
	bool hasAllCodes(string s, int k) {
		unordered_set<int> nums;
		if (s.size() < k) return false;
		int base = 1, num = 0;
		for (int i = 0; i < k; i++) {
			num = num + base * (s[i] - '0');
			base <<= 1;
		}
		nums.insert(num);
		int type_num = pow(2, k);
		for (int i = k; i < s.size(); i++) {
			// minus the first digit; then plus the lowest digit;
			int minus = (s[i - k] - '0') << (k - 1);
			num = (num - minus)<<1 ;
			num += s[i] - '0';
			nums.insert(num);
			if (nums.size() == type_num) {
				return true;
			}
		}
		return false;
	}
};

class Solution3 {
private: 
	std::vector<std::vector<int>> m_graph;
	std::vector<std::vector<int>> m_if_connected;
public:
	vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
		m_graph.assign(n, std::vector<int>());
		for (auto & edge : prerequisites) {
			m_graph[edge[0]].emplace_back(edge[1]);
		}
		std::vector<bool> result;
		for (int idx = 0; idx < queries.size(); ++idx) {
			std::vector<int> path(n,0);
			if (m_if_connected[queries[idx][0]][queries[idx][1]] == 1) {
				result.emplace_back(true);
			}
			else {
				if (bfs(queries[idx][0], queries[idx][1], path)) {
					result.emplace_back(true);
				}
				else {
					result.emplace_back(false);
				}
			}
		}
		return result;
	}
	bool bfs(int start_idx, int target_idx, std::vector<int>&path) {
		std::queue<int> que; que.push(start_idx);
		while (!que.empty()) {
			int cur = que.front(); que.pop();
			path[cur] = 1;
			m_if_connected[start_idx][cur] = 1;
			if (cur == target_idx) {
				return true;
			}
			else {
				for (auto & next : m_graph[cur]) {
					if (path[next] == 0) {
						que.push(next);
					}
				}
			}
		}
		return false;
	}
};


class Solution3_1 {
private:
	std::vector<std::vector<int>> m_graph;
	std::vector<std::vector<int>> m_if_connected;
public:
	vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
		m_graph.assign(n, std::vector<int>());
		m_if_connected.assign(n, std::vector<int>(n, 0));
		for (auto & edge : prerequisites) {
			m_graph[edge[0]].emplace_back(edge[1]);
		}
		std::vector<bool> result;
		std::unordered_set<int> has_searched;
		for (int idx = 0; idx < queries.size(); ++idx) {
			if (has_searched.find(idx) != has_searched.end()) {
				result.emplace_back(m_if_connected[queries[idx][0]][queries[idx][1]] == 1);
			}
			else {
				std::vector<int> path(n, 0);
				bfs(queries[idx][0], path);
				has_searched.emplace(idx);
				result.emplace_back(m_if_connected[queries[idx][0]][queries[idx][1]] == 1);
			}
		}
		return result;
	}
	void bfs(int start_idx, std::vector<int>&path) {
		std::queue<int> que; que.push(start_idx);
		while (!que.empty()) {
			int cur = que.front(); que.pop();
			path[cur] = 1;
			m_if_connected[start_idx][cur] = 1;
			for (auto & next : m_graph[cur]) {
				if (path[next] == 0) {
					que.push(next);
				}
			}
		}
	}
};

// solution 3: BFS + prune;
class Solution {
private:
	std::vector<std::vector<int>> m_graph;
	std::vector<std::vector<int>> m_if_connected;
public:
	vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
		m_graph.assign(n, std::vector<int>());
		m_if_connected.assign(n, std::vector<int>(n, 0));
		for (auto & edge : prerequisites) {
			m_graph[edge[0]].emplace_back(edge[1]);
		}
		std::vector<bool> result;
		for (int idx = 0; idx < queries.size(); ++idx) {
			std::vector<int> path(n, 0);
			// with same start_idx, then use the history informations;
			if (m_if_connected[queries[idx][0]][queries[idx][1]] == 1) {
				result.emplace_back(true);
			}
			else {
				if (bfs(queries[idx][0], queries[idx][1], path)) {
					result.emplace_back(true);
				}
				else {
					result.emplace_back(false);
				}
			}
		}
		return result;
	}
	bool bfs(int start_idx, int target_idx, std::vector<int>&path) {
		std::queue<int> que; que.push(start_idx);
		path[start_idx] = 1;
		while (!que.empty()) {
			int cur = que.front(); que.pop();
			m_if_connected[start_idx][cur] = 1;
			// if the cur node can serve as intermidiate node, 
			// then start_idx to target_idx is connected.
			if (cur == target_idx || m_if_connected[cur][target_idx]) {
				return true;
			}
			else {
				for (auto & next : m_graph[cur]) {
					if (path[next] == 0) {
						que.push(next);
						path[next] = 1;
					}
				}
			}
		}
		return false;
	}
};

int main() {
	Solution2_2 sol;
	string test_string = "00110110";
	std::cout << sol.hasAllCodes(test_string, 2);

	cin.get();
	return 0;
}