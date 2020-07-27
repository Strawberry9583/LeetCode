#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() < 1) {
			return 0;
		}
		int buy_price = prices[0];
		int profit = 0;
		for (int cur_time=1; cur_time < prices.size(); ++cur_time) {
			if (prices[cur_time] < buy_price) {
				buy_price = prices[cur_time];
			}
			else {
				profit += prices[cur_time] - buy_price;
				buy_price = prices[cur_time];
			}
		}
		return profit;
	}
};
class Solution1 {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() < 1) {
			return 0;
		}
		int profit = 0;
		for (int cur_time = 1; cur_time < prices.size(); ++cur_time) {
			if (prices[cur_time] > prices[cur_time-1]) {
				profit += prices[cur_time] - prices[cur_time-1];
			}
		}
		return profit;
	}
};

int main() {
	Solution1 sol;
	std::cout << sol.maxProfit(std::vector<int>{7,6,4,3,1});

	std::cin.get();
	return 0;
}