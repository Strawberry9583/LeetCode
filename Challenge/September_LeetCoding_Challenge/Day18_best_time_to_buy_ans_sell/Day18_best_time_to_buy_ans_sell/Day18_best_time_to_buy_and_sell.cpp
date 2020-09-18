#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int result = 0;
		int cur = 0;
		for (int idx = 1; idx < prices.size(); ++idx) {
			cur += prices[idx] - prices[idx - 1];
			if (cur < 0) {
				cur = 0;
			}
			else {
				if (result < cur) {
					result = cur;
				}
			}
		}
		return result;
	}
};

int main() {
	std::vector<int> prices = { 7,6,4,3,1 };
	std::cout << Solution().maxProfit(prices);
	cin.get();
	return 0;
}