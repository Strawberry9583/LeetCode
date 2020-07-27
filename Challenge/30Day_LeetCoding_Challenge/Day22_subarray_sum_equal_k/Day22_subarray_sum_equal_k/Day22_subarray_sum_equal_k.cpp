#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

//class Solution {
//public:
//	int subarraySum(vector<int>& nums, int k) {
//		int left = 0, right = 0;
//		int sum = 0;
//		int result = 0;
//		while (right<nums.size()) {
//			sum += nums[right++];
//			if (sum == k) {
//				++result;
//			}
//			while (sum>=k&&left<right) {
//				sum -= nums[left++];
//				if (sum == k&&left<right) {
//					++result;
//				}
//			}
//		}
//		return result;
//	}
//};

class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		int result = 0;
		if (nums.empty()) {
			return result;
		}
		//record the occurred sum and its corresponding times;
		std::unordered_map<int, int> sum2times;
		int sum = 0;
		for (int idx = 0; idx < nums.size(); ++idx) {
			sum += nums[idx];
			int distance = sum - k;
			auto find_ele = sum2times.find(distance);
			//if distance==0, and then result should add 1 more;
			//because the begin sum is 0 without any elements;
			if (distance == 0) {
				if (find_ele == sum2times.end()) {
					result +=1;
				}
				else {
					result += find_ele->second + 1;
				}
			}
			else {
				if (find_ele != sum2times.end()) {
					result += find_ele->second;
				}
			}
			++sum2times[sum];
		}
		return result;
	}
};

//solution 2: directly put 0 into the sum2times firstly;
class Solution2 {
public:
	int subarraySum(vector<int>& nums, int k) {
		int result = 0;
		if (nums.empty()) {
			return result;
		}
		std::unordered_map<int, int> sum2times;
		int sum = 0;
		sum2times[0] = 1;
		for (int idx = 0; idx < nums.size(); ++idx) {
			sum += nums[idx];
			int distance = sum - k;
			auto find_ele = sum2times.find(distance);
			if (find_ele != sum2times.end()) {
				result += find_ele->second;
			}
			++sum2times[sum];
		}
		return result;
	}
};

int main() {
	Solution sol;
	std::vector<int> test{ -1,-1,1 };
	std::cout << sol.subarraySum(test,0);

	std::cin.get();
	return 0;
}