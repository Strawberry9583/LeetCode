#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int findMaxLength(vector<int>& nums) {
		std::unordered_map<int, int> sum2idx;
		sum2idx[0] = 0;
		int result =0, cur_sum = 0;
		for (int idx = 0; idx < nums.size(); ++idx) {
			if (nums[idx]) {
				++cur_sum;
			}
			else {
				--cur_sum;
			}
			auto find_ele = sum2idx.find(cur_sum);
			if (find_ele== sum2idx.end()) {
				sum2idx[cur_sum] = idx;
			}
			else {
				int dis = cur_sum==0?idx+1:idx-find_ele->second;
				if (dis> result) {
					result = dis;
				}
			}
		}
		return result;
	}
};

int main() {
	std::vector<int> test_vec{ 0,1,0 };
	std::cout << Solution().findMaxLength(test_vec);
	cin.get();
	return 0;
}