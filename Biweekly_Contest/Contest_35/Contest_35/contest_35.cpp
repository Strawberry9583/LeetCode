#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;


class Solution2 {
public:
	int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
		std::vector<int> gap(nums.size()+1);
		for (auto & interval : requests) {
			++gap[interval[0]];
			--gap[interval[1]+1];
		}
		std::vector<int> freq(nums.size());
		int cur = 0;
		for (int idx = 0; idx < freq.size(); ++idx) {
			cur += gap[idx];
			freq[idx] = cur;
		}
		std::sort(freq.begin(), freq.end());
		std::sort(nums.begin(), nums.end());
		int result = 0;
		int mod = (1e9) + 7;
		for (int idx = 0; idx < freq.size(); ++idx) {
			result += freq[idx] * nums[idx];
			result %= mod;
		}
		return result;
	}
};


class Solution3 {
public:
	int minSubarray(vector<long int>& nums, long int p) {
		long int all_sum = 0;
		for (long int idx = 0; idx < nums.size(); ++idx) {
			all_sum += nums[idx];
			all_sum %= p;
		}
		if (all_sum == 0) {
			return 0;
		}
		std::unordered_map<long int, long int> sum2idx;
		sum2idx[0] = -1;
		sum2idx[nums[0] % p] = 0;

		long int cur_sum = nums[0] % p;
		long int min_length = std::numeric_limits<long int>::max();
		for (long int idx = 1; idx < nums.size(); ++idx) {
			cur_sum += nums[idx];
			//cur_sum %= p;
			long int target =cur_sum-all_sum;
			target %= p;
			//if (target == 0) {
			//	sum2idx[0] = idx;
			//}
			if (sum2idx.find(target) != sum2idx.end()) {
				long int cur_length = idx - sum2idx[target] ;
				if (cur_length < min_length) {
					min_length = cur_length;
				}
			}
			sum2idx[cur_sum%p] = idx;
		}
		long int result = -1;
		if (min_length !=std::numeric_limits<long int>::max()&&min_length!=nums.size()) {
			result = min_length;
		}
		return result;
	}
};

class Solution {
public:
	int sumOddLengthSubarrays(vector<int>& arr) {
		int result = 0;
		for (int i = 0; i < arr.size(); ++i) {
			for (int j = i; j < arr.size(); ++j) {
				if ((j - i + 1) % 2) {
					int cur_sum = 0;
					for (int idx = i; idx <= j; ++idx) {
						cur_sum += arr[idx];
					}
					result += cur_sum;
				}
			}
		}
		return result;
	}
};

int main() {


	//std::vector<int> nums = { 1,2,3,4,5,10 };
	//std::vector<std::vector<int>> request = { {0,2}, {1,3},{1,1} };
	//std::cout << Solution2().maxSumRangeQuery(nums, request);




	cin.get();
	return 0;
}