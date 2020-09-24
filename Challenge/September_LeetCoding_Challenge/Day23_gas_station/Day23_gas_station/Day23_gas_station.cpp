#include<iostream>
#include<vector>
#include<string>

using namespace std;


// Idea1: If car starts at A and can not reach B.Any station between A and B
// can not reach B.(B is the first station that A can not reach.)
// Idea2: If the total number of gas is bigger than the total number of cost.There must be a solution.

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int total_gas = 0;
		int total_cost = 0;
		// record the start gas;
		int result = 0;
		// record current rest gas;
		int cur_rest = 0;
		for (int idx = 0; idx < gas.size(); ++idx) {
			cur_rest += gas[idx] - cost[idx];
			if (cur_rest < 0) {
				result = idx+1;
				cur_rest = 0 ;
			}
			else {

			}
			total_gas += gas[idx];
			total_cost += cost[idx];
		}
		if (total_gas < total_cost) {
			return -1;
		}
		else {
			return result;
		}
	}
};

int main() {
	std::vector<int> gas = { 5, 1, 2, 3, 4 };
	std::vector<int> cost = {4, 4, 1, 5, 1};
	std::cout<<Solution().canCompleteCircuit(gas, cost);
	cin.get();
	return 0;
}