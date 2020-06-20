#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

// solution1: sort by cost difference;
// think in this way:
// first divide all persion into group1;
// then chosen half num of person to group2, whose all cost will reduce most;
// so select the biggest difference group1 and group2 into the group2.
// Time complexity: O(n*lgn); Space complexity: O(1);
class Solution1 {
public:
	int twoCitySchedCost(vector<vector<int>>& costs) {
		std::sort(costs.begin(), costs.end(), [](const std::vector<int>& rhs1, const std::vector<int>& rhs2)
		{return rhs1[0] - rhs1[1] < rhs2[0] - rhs2[1]; });
		int result = 0;
		int group_num = costs.size() / 2;
		for ( int idx = 0; idx < costs.size(); ++idx) {
			if (idx < group_num) {
				result += costs[idx][0];
			}
			else {
				result += costs[idx][1];
			}
		}
		return result;
	}
};

// solution2: similar to sort but without the neccesity to sort all elements;
// so just find the k_th largest difference then operate as the above;
// Time complexity: O(n*lgn); Space complexity: O(1);
class Solution2 {
public:
	int twoCitySchedCost(vector<vector<int>>& costs) {
		int group_num = costs.size() / 2;
		std::nth_element(costs.begin(),costs.begin()+ group_num-1,costs.end(),[](const std::vector<int>& rhs1, const std::vector<int>& rhs2)
		{return rhs1[0] - rhs1[1] < rhs2[0] - rhs2[1]; });
		int result = 0;
		for (int idx = 0; idx < costs.size(); ++idx) {
			if (idx < group_num) {
				result += costs[idx][0];
			}
			else {
				result += costs[idx][1];
			}
		}
		return result;
	}
};


//solution 3: DP:
// dp[i][j] represents the cost 
// when considering first (i + j) people in which i people assigned to city A and j people assigned to city B.
/*
for (i + j)th people, he / she can be assigned either to A city or B city,
the min cost if he is assigned to A city : dp[i - 1][j] + costs[i + j - 1][0]; //because it is to A, so we should use i-1
the min cost if he is assigned to B city : dp[i][j - 1] + costs[i + j - 1][1]; //because it is to B, so we should use j-1
so dp[i][j] = Math.min(dp[i - 1][j] + costs[i + j - 1][0], dp[i][j - 1] + costs[i + j - 1][1]);

another way to represent the dp equation is : dp[totalPerson][personToA], toatalPerson is the number of people have been assigned, and personToA of them are assigned to city A, so the the equation :
dp[totalPerson][personToA] = Math.min(dp[totalPerson - 1][personToA] + costs[totalPerson - 1][1], //the last one to B
dp[totalPerson - 1][personToA - 1] + costs[totalPerson - 1][0]);//the last one to A

*/
class Solution {
public:
	int twoCitySchedCost(vector<vector<int>>& costs) {
		int N = costs.size() / 2;
		std::vector<std::vector<int>> dp(N + 1,std::vector<int>(N + 1,0));
		for (int i = 1; i <= N; i++) {
			dp[i][0] = dp[i - 1][0] + costs[i - 1][0];
		}
		for (int j = 1; j <= N; j++) {
			dp[0][j] = dp[0][j - 1] + costs[j - 1][1];
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				//assign the (i+j)th person to A or B city;
				dp[i][j] = min({ dp[i - 1][j] + costs[i + j - 1][0], dp[i][j - 1] + costs[i + j - 1][1] });
			}
		}
		return dp[N][N];
	}
};

int main() {

	cin.get();
	return 0;
}