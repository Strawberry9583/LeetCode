#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution1 {
public:
	int minStartValue(vector<int>& nums) {
		int min_sum = std::numeric_limits<int>::max();
		int cur_sum = 0;
		for (auto &ele : nums) {
			cur_sum += ele;
			if (cur_sum < min_sum) {
				min_sum = cur_sum;
			}
		}
		return min_sum>=1? 1: 1-min_sum;
	}
};

int main() {
	
	std::cin.get();
	return 0;
}