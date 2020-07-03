#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;



// solutino1: DFS
class Solution {
	// map from the current city to neighbor city 
	// int inidicating whether the city is visited;
	std::unordered_map<string, std::vector<pair<string, int>>> m_name2next;
	// requirement for visiting every node;
	int m_reuired_path_length;
	// result path;
	std::vector<string> m_result;
public:
	vector<string> findItinerary(vector<vector<string>>& tickets) {
		// store the graph;
		for (auto & pair_wise : tickets) {
			m_name2next[pair_wise[0]].emplace_back(pair_wise[1],0);
		}
		// sort the neighbor with lexilogical orders;
		for (auto & all_next : m_name2next) {
			std::sort(all_next.second.begin(), all_next.second.end(),
				[](const pair<string, int>& city1, const pair<string, int>& city2) {return city1.first < city2.first; });
		}
		string start_node = "JFK";
		m_result.emplace_back(start_node);
		m_reuired_path_length = tickets.size() + 1;
		dfs(start_node);
		return m_result;
	}
	bool dfs(string start_node) {
		if (m_result.size() == m_reuired_path_length) {
			return true;
		}
		for (auto & next : m_name2next[start_node]) {
			if (next.second == 0) {
				next.second = 1;
				m_result.emplace_back(next.first);
				if (dfs(next.first)) {
					return true;
				}
				//restore the privious status;
				else {
					next.second = 0;
					m_result.pop_back();
				}
			}
		}
		return false;
	}
};

int main() {
	std::vector<std::vector<string>> test_vec{ {"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"} };
	auto ans = Solution().findItinerary(test_vec);
	for (auto & node : ans) {
		std::cout << node << "->";
	}
	cin.get();
	return 0;
}