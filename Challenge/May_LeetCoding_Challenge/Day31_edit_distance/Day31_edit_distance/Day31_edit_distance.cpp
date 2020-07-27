#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
	int minDistance(string s, string t) {
		// �����⣺
		// f(i, j) = s[0..i) �� t[0..j) �ı༭����

		// f(0, j) = j
		// f(i, 0) = i
		// f(i, j) = f(i-1, j-1), if s[i-1] == t[j-1]
		//           max: f(i-1, j) + 1
		//                f(i, j-1) + 1
		//                f(i-1, j-1) + 1, if s[i-1] != t[j-1]

		int m = s.length();
		int n = t.length();
		std::vector<std::vector<int>> dp(m+1,std::vector<int>(n+1,0));
		for (int i = 0; i <= m; i++) {
			for (int j = 0; j <= n; j++) {
				if (i == 0) {
					dp[i][j] = j;
				}
				else if (j == 0) {
					dp[i][j] = i;
				}
				else {
					if (s[i - 1] == t[j - 1]) {
						dp[i][j] = dp[i - 1][j - 1];
					}
					else {
						dp[i][j] = 1 + min({
							dp[i - 1][j],  // ɾ������
							dp[i][j - 1],  // �������
							dp[i - 1][j - 1] } // �滻����
						);
					}
				}
			}
		}
		return dp[m][n];
	}
};

int main() {

	cin.get();
	return 0;
}