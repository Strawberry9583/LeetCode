#include<vector>
#include<algorithm>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
	int maxUncrossedLines(vector<int>& A, vector<int>& B) {
		std::vector<std::vector<int>> dp(A.size(), std::vector<int>(B.size(), 0));
		dp[0][0] = A[0] == B[0] ? 1 : 0;
		for (int idx_a = 0; idx_a < A.size(); ++idx_a) {
			for (int idx_b = 0; idx_b < B.size(); ++idx_b) {
				if (idx_a == 0) {
					if (idx_b != idx_a) {
						dp[idx_a][idx_b] = A[idx_a] == B[idx_b] ?1: dp[idx_a][idx_b-1];
						//if (A[idx_a] == B[idx_b]) {
						//	dp[idx_a][idx_b] = 1;
						//}
						//else {
						//	dp[idx_a][idx_b] = dp[idx_a][idx_b - 1];
						//}
					}
				}
				else if (idx_b == 0) {
					dp[idx_a][idx_b] = A[idx_a] == B[idx_b] ? 1 : dp[idx_a-1][idx_b];
					//if (A[idx_a] == B[idx_b]) {
					//	dp[idx_a][idx_b] = 1;
					//}
					//else {
					//	dp[idx_a][idx_b] = dp[idx_a-1][idx_b];
					//}

				}
				else {
					if (A[idx_a] == B[idx_b]) {
						dp[idx_a][idx_b] = dp[idx_a - 1][idx_b - 1] + 1;
					}
					else {
						dp[idx_a][idx_b] = std::max(dp[idx_a - 1][idx_b], dp[idx_a][idx_b - 1]);
					}
				}
			}
		}
		return dp[A.size() - 1][B.size() - 1];
	}
};


int main() {


	cin.get();
	return 0;
}