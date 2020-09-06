#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include<string>
#include<functional>

using namespace std;


class Solution1 {
	char possible_char(char left, char right) {
		char ans;
		for (int idx = 0; idx < 26; ++idx) {
			ans = 'a' + idx;
			if (ans != left&&ans != right) {
				break;
			}
		}
		return ans;
	}
public:
	string modifyString(string s) {
		string result(s);
		for (int idx = 0; idx < s.size(); ++idx) {
			char left='?', right = '?';
			if (idx - 1 >= 0) {
				left = result[idx - 1];
			}
			if (idx + 1 < s.size()) {
				right = result[idx + 1];
			}
			if (result[idx] == '?') {
				result[idx] = possible_char(left, right);
			}

		}
		return result;
	}
};

class Solution2 {
public:
	int numTriplets(vector<int>& nums1, vector<int>& nums2) {
		std::unordered_map<long int, long int> num2freq1;
		std::unordered_map<long int, long int> num2freq2;
		for (long int idx = 0; idx < nums1.size(); ++idx) {
			++num2freq1[nums1[idx]];
		}
		for (long int idx = 0; idx < nums2.size(); ++idx) {
			++num2freq2[nums2[idx]];
		}
		long int result = 0;
		for (auto & ele : num2freq1) {
			long int square = ele.first*ele.first;
			for (auto & product : num2freq2) {
				if (square%product.first==0) {
					auto another = num2freq2.find(square / product.first);
					if (another == num2freq2.end()) {
						continue;
					}
					else {
						//result += another->second*product.second;
						if (another->first == product.first) {
							result += ele.second*another->second*(another->second-1);
						}
						else {
							result += ele.second*another->second*product.second;
						}
					}
				}
			}
		}

		for (auto & ele : num2freq2) {
			long int square = ele.first*ele.first;
			for (auto & product : num2freq1) {
				if (square%product.first == 0) {
					auto another = num2freq1.find(square / product.first);
					if (another == num2freq1.end()) {
						continue;
					}
					else {
						//result += another->second*product.second;
						if (another->first == product.first) {
							result += ele.second*another->second*(another->second-1);
						}
						else {
							result += ele.second*another->second*product.second;
						}
					}
				}
			}
		}
		return result/2;
	}
};

class Solution3 {
public:
	int minCost(string s, vector<int>& cost) {
		int result = 0;
		int begin_pos = 0;
		int cur_cost = cost[0];
		int max_cost = cost[0];
		for (int idx = 1; idx < s.size(); ++idx) {
			if (s[idx] == s[idx - 1]) {
				cur_cost += cost[idx];
				if (max_cost < cost[idx]) {
					max_cost = cost[idx];
				}
			}
			else {
				if (idx - 1 == begin_pos) {
					cur_cost = cost[idx];
					begin_pos = idx;
					max_cost = cost[idx];
				}
				else {
					cur_cost -= max_cost;
					result += cur_cost;
					cur_cost = cost[idx];
					max_cost = cost[idx];
					begin_pos = idx;
				}
			}
		}
		if (begin_pos != cost.size() - 1) {
			cur_cost -= max_cost;
			result += cur_cost;
		}
		return result;
	}
};


int main() {

	//string s = "??yw?ipkj?";
	//std::cout << Solution1().modifyString(s);

	//std::vector<int> nums1{ 4,7,9,11,23 };
	//std::vector<int> nums2{ 3,5,1024,12,18 };
	//std::cout << Solution2().numTriplets(nums1, nums2);

	//std::vector<int> cost{ 1,2,3 };
	//string s = "abc";
	//std::cout << Solution().minCost(s, cost);



	cin.get();
	return 0;
}