#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// solutin1: dp
// time complexity: O(n), space complexity: O(n);
// leftmin[i] indicate the minimum valun in range [0,i];
// then calc the max difference from the right to the left;
class Solution1 {
public:
	int maxProfit(vector<int>& prices) {
		std::vector<int> leftmin(prices.size(), 0);
		int cur_min = std::numeric_limits<int>::max();
		for (int idx = 0; idx < prices.size(); ++idx) {
			if (prices[idx] < cur_min) {
				cur_min = prices[idx];
			}
			leftmin[idx] = cur_min;
		}
		int result = std::numeric_limits<int>::lowest();
		for (int idx = prices.size() - 1; idx > 0; --idx) {
			int temp_profit = prices[idx] - leftmin[idx - 1];
			if (temp_profit > result) {
				result = temp_profit;
			}
		}
		return result < 0 ? 0 : result;
	}
};

// solution2£º Kadane's algorithm£»
// calc the difference directly;
// time complexity: O(n), space complexity: O(1);
//Suppose we have original array:
//[a0, a1, a2, a3, a4, a5, a6]
//
//what we are given here(or we calculate ourselves) is :
//	[b0, b1, b2, b3, b4, b5, b6]
//
//where,
//b[i] = 0, when i == 0
//b[i] = a[i] - a[i - 1], when i != 0
//
//suppose if a2 and a6 are the points that give us the max difference(a2 < a6)
//	then in our given array, we need to find the sum of sub array from b3 to b6.
//
//	b3 = a3 - a2
//	b4 = a4 - a3
//	b5 = a5 - a4
//	b6 = a6 - a5
//
//	adding all these, all the middle terms will cancel out except two
//	i.e.
//
//	b3 + b4 + b5 + b6 = a6 - a2
//
//	a6 - a2 is the required solution.
//
//	so we need to find the largest sub array sum to get the most profit
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int cur_max = 0, result =0;
		for (int idx = 1; idx < prices.size(); ++idx) {
			cur_max = std::max(0, cur_max + prices[idx] - prices[idx - 1]);
			if (cur_max > result) {
				result = cur_max;
			}
		}
		return result;
	}
};


int main() {
	cin.get();
	return 0;
}