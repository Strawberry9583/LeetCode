#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<cmath>
#include<vector>
#include<unordered_set>

using namespace std;

//search from the leaf node, then set flag for visited edge and nodes (apple);
class Solution3_1 {
public:
	int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
		//tansfer the edge reversely to search from the leaf node;
		std::vector<int> pre_node(n, -1);
		int result = 0;
		for (const auto & ele : edges) {
			pre_node[ele[1]] = ele[0];
		}
		//indicate whether the edge is visited;
		std::vector<int> edge_visit_flag(n, 0);
		//indicate the idx  of apple to collect;
		std::unordered_set<int> apple_idx;
		for (int idx = 0; idx < hasApple.size(); ++idx) {
			if (hasApple[idx]) {
				apple_idx.emplace(idx);
			}
		}
		while (!apple_idx.empty()) {
			int collect_idx = *apple_idx.begin();
			apple_idx.erase(collect_idx);
			while (collect_idx!=0) {
				if (edge_visit_flag[collect_idx]) {
					break;
				}
				else {
					++result;
					edge_visit_flag[collect_idx] = 1;
					int pre = pre_node[collect_idx];
					if (apple_idx.find(pre) != apple_idx.end()) {
						apple_idx.erase(pre);
					}
					collect_idx = pre;
				}
			}
		}
		return result * 2;
	}
};


class Solution3_2 {
public:
	int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
		//tansfer the edge reversely to search from the leaf node;
		std::vector<int> pre_node(n, -1);
		int result = 0;
		for (const auto & ele : edges) {
			pre_node[ele[1]] = ele[0];
		}
		//indicate whether the edge is visited;
		std::vector<int> edge_visit_flag(n, 0);
		for (int idx = hasApple.size() - 1; idx >= 0; --idx) {
			int collect_idx = idx;
			if (!hasApple[idx]) {
				continue;
			}
			hasApple[idx] = false;
			while (collect_idx != 0) {
				if (edge_visit_flag[collect_idx]) {
					break;
				}
				else {
					++result;
					edge_visit_flag[collect_idx] = 1;
					int pre = pre_node[collect_idx];
					if (hasApple[pre]) {
						hasApple[pre] = false;
					}
					collect_idx = pre;
				}
			}
		}
		return result * 2;
	}
};
int main() {
	vector<bool> c{ false, true, false, true, false };
	bool b = c[0];
	auto d = c[0];
	d = true;
	for (auto i : c)
		cout << i << " ";
	cout << endl;
	Solution3_1 sol;
	Solution3_2 sol2;
	std::vector<std::vector<int>> edges = { {0, 1}, {0, 2}, {1, 4}, {1, 5}, {2, 3}, {2, 6} };
	int n = 7;
	std::vector<bool> hasApple ={false, false, true, false, false, true, false};
	sol2.minTime(n, edges, hasApple);
	std::cin.get();
	return 0;
}