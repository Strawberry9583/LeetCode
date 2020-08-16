#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

// method1£ºfinite state machine;
// best time to buy ans sell stock III
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() < 2) {
			return 0;
		}

		std::vector<int> s0(std::max((int)prices.size(), 4), 0), s1(std::max((int)prices.size(), 4), 0);
		std::vector<int> s2(std::max((int)prices.size(), 4), 0), s3(std::max((int)prices.size(), 4), 0);
		std::vector<int> s4(std::max((int)prices.size(), 4), 0);
		s0[0] = 0; s1[0] = -prices[0];
		s2[0] = std::numeric_limits<int>::lowest();
		s3[0] = std::numeric_limits<int>::lowest(),
			s4[0] = std::numeric_limits<int>::lowest();
		s0[1] = 0; 
		s1[1] = s0[0] - prices[0]; 
		if (prices.size() > 1) {
			s2[1] = s1[0] + prices[1];
		}
		s3[1] = std::numeric_limits<int>::lowest(); s4[1] = std::numeric_limits<int>::lowest();
		//s0[2] = std::numeric_limits<int>::lowest(), s1[2] = std::numeric_limits<int>::lowest(); s2[2] = std::numeric_limits<int>::lowest();
		if (prices.size() > 2) {
			s3[2] = s2[1] - prices[2];
		}
		s4[2] = std::numeric_limits<int>::lowest();
		s4[2] = std::numeric_limits<int>::lowest();
		s4[3] = s3[2];
		for (int cur_time = 1; cur_time < prices.size(); ++cur_time) {
			s0[cur_time] = s0[cur_time - 1];
			s1[cur_time] = std::max(s0[cur_time - 1] - prices[cur_time], s1[cur_time - 1]);
			s2[cur_time] = std::max(s2[cur_time - 1], s1[cur_time - 1] + prices[cur_time]);

			if (cur_time >= 2) {
				s3[cur_time] = std::max(s3[cur_time - 1], s2[cur_time - 1] - prices[cur_time]);
			}
			if (cur_time >= 3) {
				s4[cur_time] = std::max(s4[cur_time - 1], s3[cur_time - 1] + prices[cur_time]);
			}
		}
		return std::max({s0[prices.size() - 1], s1[prices.size() - 1], s2[prices.size() - 1],
			s3[prices.size() - 1], s4[prices.size() - 1]});
	}
};

int main() {

	std::vector<int> test_vec{ 1,4,2,7};
	std::cout << Solution().maxProfit(test_vec);

	cin.get();
	return 0;
}