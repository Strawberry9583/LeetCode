#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<functional>
#include<numeric>
#include<sstream>
#include<bitset>
using namespace std;



//class Solution {
//public:
//	vector<int> minSubsequence(vector<int>& nums) {
//		int sum = std::accumulate(nums.begin(), nums.end(), 0);
//		std::pair<int, int> result_idx(0,1000);
//		int pre =0 , cur = 0, cur_max = 0;
//		int cur_sum = 0;
//		for (; cur < nums.size(); ++cur) {
//			cur_sum += nums[cur];
//			while (cur_sum>sum-cur_sum) {
//				if (cur - pre < result_idx.second - result_idx.first) {
//					result_idx.first = pre;
//					result_idx.second = cur;
//				}
//				else if (cur - pre == result_idx.second - result_idx.first) {
//					if (cur_sum > cur_max) {
//						cur_max = cur_sum;
//						result_idx.first = pre;
//						result_idx.second = cur;
//					}
//				}
//				cur_sum -= nums[pre];
//				++pre;
//			}
//		}
//		return std::vector<int>(nums.begin() + result_idx.first, nums.begin() + result_idx.second);
//	}
//};

class Solution1 {
public:
	vector<int> minSubsequence(vector<int>& nums) {
		std::vector<int>result;
		int sum = std::accumulate(nums.begin(), nums.end(), 0);
		int cur_sum = 0;
		std::sort(nums.begin(), nums.end(), [](const int rhs1, const int rhs2) {return rhs1 > rhs2; });
		for (const auto & ele : nums) {
			cur_sum += ele;
			result.emplace_back(ele);
			if (cur_sum > sum - cur_sum) {
				break;
			}
		}
		return result;
	}
};

class Solution2 {
public:
	int numSteps(string s) {
		if (s.size() == 1) {
			return 0;
		}
		int zero_num = 0;// indicate the operation num to add 1;
		bool first_found = false;//indicate whehter found 1
		for (int idx = s.size() - 1; idx >= 0; --idx) {
			if (!first_found&&s[idx] == '1') {
				first_found = true;
			}
			else if (s[idx]=='0'&&first_found) {
				++zero_num;
			}
		}
		//indicate whether to carry one more digit ahead of the num;
		bool if_carry = 0;
		for (int idx = 1; idx < s.size(); ++idx) {
			if (s[idx] == '1') {
				if_carry = true;
				break;
			}
		}
		//indicate the operation num to divide by 2;
		int divide_num = s.size() - 1;
		if (if_carry) {
			zero_num += 1;
			divide_num += 1;
		}
		return zero_num + divide_num;
	}
};

class Solution3 {
public:
	string longestDiverseString(int a, int b, int c) {
		string result;
		std::pair<char, int> a2num('a', a);
		std::pair<char, int> b2num('b', b);
		std::pair<char, int> c2num('c', c);
		std::vector<std::pair<char, int>> pair_vec{ a2num,b2num,c2num };
		while (1) {
			std::sort(pair_vec.begin(),pair_vec.end(), [](const pair<char, int> & rhs1, const pair<char, int> & rhs2) {
				return rhs1.second > rhs2.second; });
			if (result.size() < 2) {
				if (pair_vec[0].second > 0) {
					--pair_vec[0].second;
					result += pair_vec[0].first;
				}
				else {
					break;
				}
			}
			else {
				if (pair_vec[0].second > 0) {
					if (pair_vec[0].first == *result.rbegin() && pair_vec[0].first == *(result.rbegin() + 1)) {
						if (pair_vec[1].second > 0) {
							result += pair_vec[1].first;
							--pair_vec[1].second;
						}
						else {
							break;
						}
					}
					else {
						result += pair_vec[0].first;
						--pair_vec[0].second;
					}
				}
				else {
					break;
				}
			}
		}
		return result;
	}
};

int main() {
	Solution3 sol;
	//std::vector<int> test{ 4,4,7,6,7 };
	//auto ans = sol.minSubsequence(test);
	//for (auto & ele : ans) {
	//	std::cout << ele << " ";
	//} 
	std::cout << sol.longestDiverseString(1, 1, 7);
	std::cin.get();
	return 0;
}