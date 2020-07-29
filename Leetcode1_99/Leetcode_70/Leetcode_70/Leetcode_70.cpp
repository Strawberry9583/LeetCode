#include<iostream>
#include<vector>
#include<string>

using namespace std;

// there are lots of solutions can be considerred as following:
// https://leetcode.com/problems/climbing-stairs/solution/

class Solution {
public:
	int climbStairs(int n) {
		int pre_1 = 1, pre_2 = 2;
		if (n == 1) {
			return 1;
		}
		if (n == 2) {
			return 2;
		}
		for (int idx = 3; idx <= n; ++idx) {
			int temp = pre_1;
			pre_1 = pre_2;
			pre_2 +=temp;
		}
		return pre_1 + pre_2;
	}
};

int main() {

	cin.get();
	return 0;
}