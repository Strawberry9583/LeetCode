#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<functional>
#include<queue>


using namespace std;

class Solution1 {
public:
	int numSpecial(vector<vector<int>>& mat) {
		int result = 0;
		for (int row = 0; row < mat.size(); ++row) {
			for (int col = 0; col < mat.front().size(); ++col) {
				if (check_special(row, col, mat)) {
					++result;
				}
			}
		}
		return result;
	}
private:
	bool check_special(int row, int col, std::vector<std::vector<int>> & mat) {
		if (mat[row][col] == 0) {
			return false;
		}
		for (int idx = 0; idx < mat.size(); ++idx) {
			if (idx != row) {
				if (mat[idx][col] == 0) {
					continue;
				}
				else {
					return false;
				}
			}
		}
		for (int idx = 0; idx < mat.front().size(); ++idx) {
			if (idx != col) {
				if (mat[row][idx] == 0) {
					continue;
				}
				else {
					return false;
				}

			}
		}
		return true;
	}
};

class Solution2 {
public:
	int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
		std::vector<std::vector<int>> pref_order(n, std::vector<int>(n, 0));
		for (int person_id = 0; person_id < n; ++person_id) {
			for (int pefer_id = 0; pefer_id < n-1; ++pefer_id) {
				pref_order[person_id][preferences[person_id][pefer_id]] = pefer_id;
			}
		}
		int result = 0;
		std::vector<int> dp(n, 0);
		for (int dual_idx = 0; dual_idx < pairs.size(); ++dual_idx) {
			int first_1 = pairs[dual_idx][0], first_2 = pairs[dual_idx][1];
			for (int test_idx = 0; test_idx < pairs.size(); ++test_idx) {
				if (test_idx != dual_idx) {
					int second_1 = pairs[test_idx][0], second_2 = pairs[test_idx][1];
					if((pref_order[first_1][first_2]>pref_order[first_1][second_1]&&
						pref_order[second_1][second_2] > pref_order[second_1][first_1]) ||
						(pref_order[first_1][first_2] > pref_order[first_1][second_2] &&
							pref_order[second_2][second_1] > pref_order[second_2][first_1]) ){
						dp[first_1] = 1;
					}
					if ((pref_order[first_2][first_1]>pref_order[first_2][second_1] &&
						pref_order[second_1][second_2] > pref_order[second_1][first_2]) ||
						(pref_order[first_2][first_1] > pref_order[first_2][second_2] &&
							pref_order[second_2][second_1] > pref_order[second_2][first_2])) {
						dp[first_2] = 1;
					}

				}
			}
		}
		for (int idx = 0; idx < n; ++idx) {
			if (dp[idx] == 1) {
				++result;
			}
		}
		return result;
	}
};


class Solution3 {
	
public:
	int minCostConnectPoints(vector<vector<int>>& points) {
		std::vector<std::vector<int>> edges(points.size(), std::vector<int>(points.size(), 0));
		for (int node = 0; node < points.size(); ++node) {
			for (int neighor = node + 1; neighor < points.size(); ++neighor) {
				int dis = abs(points[node][0] - points[neighor][0]) + abs(points[node][1] - points[neighor][1]);
				edges[node][neighor] = dis;
				edges[neighor][node] = dis;
			}
		}
		std::vector<int> next(points.size(), std::numeric_limits<int>::max());
		std::vector<int> visited(points.size(), 0);
		int linked_num=1;
		visited[0] = 1;
		int result = 0;
		for (int next_node = 1; next_node < points.size(); ++next_node) {
			next[next_node] = edges[0][next_node];
		}
		while (linked_num!=points.size()) {
			int added_node = 0, added_dis = std::numeric_limits<int>::max();
			for (int idx = 0; idx < points.size(); ++idx) {
				if (visited[idx] == 0 && next[idx] < added_dis) {
					added_dis = next[idx];
					added_node = idx;
				}
			}
			visited[added_node] = 1; ++linked_num;
			result += added_dis;
			for (int idx = 0; idx < points.size(); ++idx) {
				if (visited[idx] == 0 && next[idx] > edges[added_node][idx]) {
					next[idx] = edges[added_node][idx];
				}
			}
		}
		return result;
	}
};

int main() {
	//std::vector<std::vector<int>>  mat = { { 0, 0, 0, 0, 0 },
	//{ 1, 0, 0, 0, 0 },
	//{ 0, 1, 0, 0, 0 },
	//{ 0, 0, 1, 0, 0 },
	//{ 0, 0, 0, 1, 1 } };
	//std::cout << Solution1().numSpecial(mat);


	//std::vector<std::vector<int>> preference = { {1, 4, 3, 2, 5}, {0, 5, 4, 3, 2}, {3, 0, 1, 5, 4}, {2, 1, 4, 0, 5}, {2, 1, 0, 3, 5}, {3, 4, 2, 0, 1} };
	////std::vector<std::vector<int>> {{1, 3, 2}, {2, 3, 0}, {1, 3, 0}, {0, 2, 1}};
	//std::vector<std::vector<int>> pairs = { {3,1}, {2,0},{5,4} };
	//std::cout << Solution2().unhappyFriends(preference.size(), preference, pairs);

	//std::vector<std::vector<int>> points = {{0, 0}};
	//std::cout << Solution3().minCostConnectPoints(points);

	cin.get();
	return 0;
}