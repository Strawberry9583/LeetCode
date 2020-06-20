#include<vector>
#include<iostream>
#include<string>

using namespace std;


// knapsack problem: DP method;
// Caution: the out loop can not be the sum, or the answer will be repeated.
// Time complexity: O((length of coins * amount); Space compelxity: O((length of coins * amount);
// and with rolling array, the space complexity can be reduce to O(amount)
class Solution {
public:
	int change(int amount, vector<int>& coins) {
		std::vector<std::vector<int>> dp(coins.size()+1, std::vector<int>(amount+1, 0));
		for (int coin_num = 0; coin_num <= coins.size(); ++coin_num) {
			for (int sum = 0; sum <= amount; ++sum) {
				if (sum == 0) {
					dp[coin_num][sum] = 1;
				}
				else if (coin_num == 0) {
					dp[coin_num][sum] = 0;
				}
				else if (sum >= coins[coin_num-1]) {
					dp[coin_num][sum] = dp[coin_num][sum - coins[coin_num-1]]+dp[coin_num-1][sum];
				}
				else {
					dp[coin_num][sum] = dp[coin_num - 1][sum];
				}
			}
		}
		return dp.back().back();
	}
};

int main() {
	std::vector<int> coins{ 1,2,5 };
	int amount = 5;
	std::cout << Solution().change(amount, coins);
	cin.get();
	return 0;
}