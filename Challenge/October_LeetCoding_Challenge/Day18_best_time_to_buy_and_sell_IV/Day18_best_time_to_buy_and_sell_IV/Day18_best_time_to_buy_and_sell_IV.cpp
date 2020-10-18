#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		int n = prices.size();

		// solve special cases
		if (n <= 0 || k <= 0) {
			return 0;
		}

		if (2 * k > n) {
			int res = 0;
			for (int i = 1; i < n; i++) {
				res += max(0, prices[i] - prices[i - 1]);
			}
			return res;
		}

		// dp[i][used_k][ishold] = balance
		// ishold: 0 nothold, 1 hold
		std::vector<std::vector<std::vector<int>>>  dp(n, std::vector<std::vector<int>>(k + 1, std::vector<int>(2)));

		// initialize the array with -inf
		// we use -1e9 here to prevent overflow
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= k; j++) {
				dp[i][j][0] = -1000000000;
				dp[i][j][1] = -1000000000;
			}
		}

		// set starting value
		dp[0][0][0] = 0;
		dp[0][1][1] = -prices[0];

		// fill the array
		for (int i = 1; i < n; i++) {
			for (int j = 0; j <= k; j++) {
				// transition equation
				dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
				// you can't hold stock without any transaction
				if (j > 0) {
					dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
				}
			}
		}

		int res = 0;
		for (int j = 0; j <= k; j++) {
			res = max(res, dp[n - 1][j][0]);
		}

		return res;
	}
};

int main() {
	cin.get();
	return 0;
}