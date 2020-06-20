#include<iostream>
#include<vector>

using namespace std;

// solution1:
// result= std::Max(range_max,1-range_min);
// Time complexity£º O(n); Space complexity: O(1);
class Solution_1 {
public:
	int maxSubarraySumCircular(vector<int>& A) {
		int cur_max = A[0];
		int max = A[0];
		int min = A[0];
		int cur_min = A[0];
		int sum = A[0];
		for (int idx = 1; idx < A.size(); ++idx) {
			sum += A[idx];
			if (cur_max >= 0) {
				cur_max = cur_max + A[idx];
			}
			else {
				cur_max = A[idx];
			}
			if (max < cur_max) {
				max = cur_max;
			}
			if (cur_min <= 0) {
				cur_min = cur_min + A[idx];
			}
			else {
				cur_min = A[idx];
			}
			if (min > cur_min) {
				min = cur_min;
			}
		}
		//if max<0, then all element <0; then min will be the sum;
		//but empty is not permitted; so return the max directly.
		if (max<0) {
			return max;
		}
		return max > sum - min ? max : sum - min;
	}
};

// solution 2:
// the max of two cases:
// case1: just one interval to use DP can get answer;
// case2: left range + right range: record the left range max with starting point of idx=0;
// then change the right range to get update max;
class Solution {
public:
	int maxSubarraySumCircular(vector<int>& A) {
		// one interval max calculation:
		int cur_max = A[0];
		int max = A[0];
		for (int idx = 1; idx < A.size(); ++idx) {
			if (cur_max >= 0) {
				cur_max = cur_max + A[idx];
			}
			else {
				cur_max = A[idx];
			}
			if (max < cur_max) {
				max = cur_max;
			}
		}
		// two interval max calculation:
		// left interval:
		// dp[i] indicate max sum of [0,i];
		vector<int> dp(A.size(), 0);
		dp[0] = A[0];
		for (int idx = 1; idx < A.size(); ++idx) {
			dp[idx] = A[idx] + dp[idx - 1];
		}
		//update dp, then dp[i] indicates the max sum of range [0,n], n<=i;
		for (int idx = 1; idx < A.size(); ++idx) {
			if (dp[idx] < dp[idx - 1]) {
				dp[idx] = dp[idx-1];
			}
		}
		//cur_right_sum indicate the sum of range [idx,A.size()-1];
		int cur_right_sum = 0;
		//cur_sum indicate the current max_sum of two interval with fixed j:
		//left range of [0,i], right range of [j,A.size()-1];
		int cur_sum = 0;
		for (int idx = A.size() - 1; idx > 1; --idx) {
			cur_right_sum += A[idx];
			cur_sum = cur_right_sum + dp[idx - 1];
			if (cur_sum > max) {
				max = cur_sum;
			}
		}
		return max;
	}
};




int main() {
	std::vector<int> test{-2,2,-2,9};
	std::cout << Solution().maxSubarraySumCircular(test);
	cin.get();
	return 0;
}