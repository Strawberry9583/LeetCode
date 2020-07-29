#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


// solution1: dp;
// time compexity: O(n^2), space complexity£º O(n);
class Solution1 {
	std::vector<std::vector<int>> dp;
public:
	int max_profit(std::vector<int> & prices, int day, int op) {
		if (dp[day + 1][op] != -1) {
			return dp[day + 1][op];
		}
		else {
			// buy in the day;
			if (op == 0) {
				dp[day + 1][0] = max_profit(prices, day - 1, 2);
			}
			// sell in the day;
			else if (op == 1) {
				//find a day to buy in;
				for (int pre_day = 0; pre_day < day; ++pre_day) {
					auto temp = max_profit(prices, pre_day, 0) + prices[day] - prices[pre_day];
					if (temp > dp[day + 1][1]) {
						dp[day + 1][1] = temp;
					}
				}
			}
			//cool down in the day;
			else if (op == 2) {
				dp[day + 1][op] = std::max({
					max_profit(prices,day - 1,0),
					max_profit(prices,day - 1,1),
					max_profit(prices,day - 1,2)
				});
			}
			if (dp[day + 1][op] < 0) {
				dp[day + 1][op] = 0;
			}
			return dp[day + 1][op];
		}
	}
	int maxProfit(vector<int>& prices) {
		if (prices.empty()) {
			return 0;
		}
		dp.resize(prices.size() + 1, std::vector<int>(3, -1));
		dp[0][0] = dp[0][1] = dp[0][2] = 0;
		dp[1][0] = dp[1][1] = dp[0][2] = 0;
		return std::max({
			max_profit(prices,prices.size() - 1,0),
			max_profit(prices, prices.size() - 1, 1),
			max_profit(prices, prices.size() - 1, 2),
			});
	}
};

// solution: DP;
// time compexity: O(n^2), space complexity£º O(n);
// state machine to explain the state meaning;
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/75928/Share-my-DP-solution-(By-State-Machine-Thinking)
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() <= 1) return 0;
		vector<int> s0(prices.size(), 0);
		vector<int> s1(prices.size(), 0);
		vector<int> s2(prices.size(), 0);
		s1[0] = -prices[0];
		s0[0] = 0;
		s2[0] = INT_MIN;
		for (int i = 1; i < prices.size(); i++) {
			s0[i] = max(s0[i - 1], s2[i - 1]);
			s1[i] = max(s1[i - 1], s0[i - 1] - prices[i]);
			s2[i] = s1[i - 1] + prices[i];
		}
		return max({ s0[prices.size() - 1],s1[prices.size()-1], s2[prices.size() - 1] });
	}
};

int main() {
	std::vector<int> test_vec{ 1,2,3,0,2};
	std::cout << Solution().maxProfit(test_vec);
	cin.get();
	return 0;
}