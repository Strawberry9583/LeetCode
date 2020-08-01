#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

// solution1: dp;
// time complexity: O(N), space complexity: O(N);
class Solution1 {
public:
	int climbStairs(int n) {
		std::vector<int> dp(n + 1, 0);
		dp[0] = 1;
		dp[1] = 1;
		for (int idx = 1; idx < n; ++idx) {
			dp[idx + 1] = dp[idx] + dp[idx - 1];
		}
		return dp.back();
	}
};

// solution2: dp with rolling vector;
// time complexity: O(N); space complexity£º O(1);
class Solution {
public:
	int climbStairs(int n) {
		std::vector<int> dp(2, 0);
		dp[0] = 1;
		dp[1] = 1;
		for (int idx = 1; idx < n; ++idx) {
			int temp = dp[1];
			dp[1] += dp[0];
			dp[0] = temp;
		}
		return dp.back();
	}
};

int main() {
	std::cout << Solution().climbStairs(2);
	cin.get();
	return 0;
}