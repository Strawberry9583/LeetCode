#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//solution1: the result is C_(m+n-1)_(m-1);
//so main work is to calc the composition numbers with reccursion method;
class Solution {

public:
	
public:
	int uniquePaths(int m, int n) {
		//start points and end is the samme;
		if (m == 1 && n == 1) {
			return 0;
		}
		m = m + n - 2;
		n = n - 1;
		if (n > m) {
			n = m - 1;
		}
		//allocte the memory to store the C_m_n calculated;
		std::vector<std::vector<int>> c_m_n(m + 1, std::vector<int>(m, -1));
		for (int idx = 0; idx < c_m_n.size(); ++idx) {
			c_m_n[idx][0] = 1;
			c_m_n[idx][1] = idx;
			if (idx < c_m_n.begin()->size()) {
				c_m_n[idx][idx] = 1;
			}
		}
		return get_composition(m, n, c_m_n);
	}
	// calc the C_m_n;
	int get_composition(int m, int n, std::vector<std::vector<int>> & c_m_n) {
		if (c_m_n[m][n] != -1) {
			return c_m_n[m][n];
		}
		else {
			c_m_n[m][n]= get_composition(m - 1, n, c_m_n) + get_composition(m - 1, n - 1, c_m_n);
			return c_m_n[m][n];
		}
	}
};

//solution2 : to use DP;
class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> dp(m, vector<int>(n));
		dp[0][0] = 1;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (i == 0 && j == 0) continue;
				if (i == 0 && j > 0) {
					dp[0][j] = dp[0][j - 1];
					continue;
				}
				if (j == 0 && i > 0) {
					dp[i][0] = dp[i - 1][0];
					continue;
				}
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		return dp[m - 1][n - 1];
	}
};
int main() {
	Solution sol;
	std::cout << sol.uniquePaths(2,1);
	std::cin.get();
	return 0;
}