#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;


// soluton1: DP (similar to knapsack problem)
// regard the num as the volume of goods;
// n as the total volume of knapsack;
// to find the minimum number of goods to carray;
// Time complexity: O(n*sqrt(n)); 
// Space complexity: O(n*sqrt(n)) (also can reduced to O(sqrt(n));
class Solution1 {
public:
	int numSquares(int n) {
		std::vector<int> all_num;
		for (long int num = 1; num*num <= n; ++num) {
			all_num.emplace_back(num*num);
		}
		std::vector<std::vector<int>> dp(all_num.size()+1, std::vector<int>(n+1, 0));
		dp[0][0] = 0;
		for (int num = 1; num <= all_num.size(); ++num) {
			for (int sum = 1; sum <= n; ++sum) {
				if (num == 1) {
					dp[num][sum] = sum;
				}
				else if (sum == 1) {
					dp[num][sum] = sum;
				}
				else {
					if (sum >= all_num[num - 1]) {
						dp[num][sum] = std::min(dp[num - 1][sum], dp[num][sum - all_num[num - 1]] + 1);
					}
					else {
						dp[num][sum] = dp[num - 1][sum];
					}
				}
			}
		}
		return dp.back().back();
	}
};

// static DP: prune if current n <= previous largest n;
// dp[i] indicate the minimum number of i;
class Solution2 {
public:
	int numSquares(int n) {
		// static vector to store the previous calc result;
		static vector<int> dp{ 0 };
		while (dp.size() <= n) {
			int m = dp.size(), squares = INT_MAX;
			for (int i = 1; i*i <= m; ++i)
				squares = min(squares, dp[m - i*i] + 1);
			dp.push_back(squares);
		}
		return dp[n];
	}
};

// solution3: BFS + pruning;
class Solution {
public:
	int numSquares(int n) {
		if (n <= 0) {
			return 0;
		}

		// perfectSquares contain all perfect square numbers which 
		// are smaller than or equal to n.
		vector<int> perfectSquares;
		// cntPerfectSquares[i - 1] = the least number of perfect 
		// square numbers which sum to i.
		vector<int> cntPerfectSquares(n);

		// Get all the perfect square numbers which are smaller than 
		// or equal to n.
		for (int i = 1; i*i <= n; i++) {
			perfectSquares.push_back(i*i);
			cntPerfectSquares[i*i - 1] = 1;
		}

		// If n is a perfect square number, return 1 immediately.
		if (perfectSquares.back() == n) {
			return 1;
		}

		// Consider a graph which consists of number 0, 1,...,n as
		// its nodes. Node j is connected to node i via an edge if  
		// and only if either j = i + (a perfect square number) or 
		// i = j + (a perfect square number). Starting from node 0, 
		// do the breadth-first search. If we reach node n at step 
		// m, then the least number of perfect square numbers which 
		// sum to n is m. Here since we have already obtained the 
		// perfect square numbers, we have actually finished the 
		// search at step 1.
		queue<int> searchQ;
		for (auto& i : perfectSquares) {
			searchQ.push(i);
		}

		int currCntPerfectSquares = 1;
		while (!searchQ.empty()) {
			currCntPerfectSquares++;

			int searchQSize = searchQ.size();
			for (int i = 0; i < searchQSize; i++) {
				int tmp = searchQ.front();
				// Check the neighbors of node tmp which are the sum 
				// of tmp and a perfect square number.
				for (auto& j : perfectSquares) {
					if (tmp + j == n) {
						// We have reached node n.
						return currCntPerfectSquares;
					}
					else if ((tmp + j < n) && (cntPerfectSquares[tmp + j - 1] == 0)) {
						// If cntPerfectSquares[tmp + j - 1] > 0, this is not 
						// the first time that we visit this node and we should 
						// skip the node (tmp + j).
						cntPerfectSquares[tmp + j - 1] = currCntPerfectSquares;
						searchQ.push(tmp + j);
					}
					else if (tmp + j > n) {
						// We don't need to consider the nodes which are greater ]
						// than n.
						break;
					}
				}

				searchQ.pop();
			}
		}
		return 0;
	}
};

int main() {
	//std::vector<int> test_vec{ 2 };
	//int amount = 3;
	//std::cout << Solution3().coinChange(test_vec,amount);
	cin.get();
	return 0;
}