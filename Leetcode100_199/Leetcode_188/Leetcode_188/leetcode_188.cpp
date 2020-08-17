#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


// method1: three dimensional DP
// ref: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/solution/
//We can either store the dp results in a dict or an array.Array costs less time for accessing and updating than dict, so we always prefer an array when possible.Because of three needed characteristics(day number, transaction number used, stock holding status), a three - dimensional array is our choice.We can use dp[day_number][used_transaction_number][stock_holding_status] to represent our states, where stock_holding_status is a 0 / 1 number representing whether you hold the stock or not.
//
//The value of dp[i][j][l] represents the best profit we can have at the end of the i - th day, with j remaining transactions to make and l stocks.
//
//The next step is finding out the so - called "transition equation", which is a method that tells you how to jump from one state to another.
//
//We start with dp[0][0][0] = 0 and dp[0][0][1] = -prices[0], and our final aim is max of dp[n - 1][j][0] from j = 0 to j = k.Now, we need to fill out the entire array to find out the result.Assume we have gotten the results before day i, and we need to calculate the profit of day i.There are only four possible actions we can do on day i : 1. keep holding the stock, 2. keep not holding the stock, 3. buy the stock, or 4. sell the stock.The profit is easy to calculate.
//
//Keep holding the stock :
//dp[i][j][1] = dp[i - 1][j][1]dp[i][j][1] = dp[i−1][j][1]
//
//Keep not holding the stock :
//dp[i][j][0] = dp[i - 1][j][0]dp[i][j][0] = dp[i−1][j][0]
//
//Buying, when j > 0:
//dp[i][j][1] = dp[i - 1][j - 1][0] - prices[i]
//
//Selling :
//	dp[i][j][0] = dp[i - 1][j][1] + prices[i]
//
//	We can combine they together to find the maximum profit :
//
//dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i])
//
//dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i])
//
//Awesome!Now we can use for - loop to calculate the whole dp array and achieve our final result.Remember to solve the special cases when 2k > n.
//


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
		std::vector<std::vector<std::vector<int>>>  dp(n,std::vector<std::vector<int>>(k + 1,std::vector<int>(2)));

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
			res =max(res, dp[n - 1][j][0]);
		}

		return res;
	}
};

int main() {
	cin.get();
	return 0;
}