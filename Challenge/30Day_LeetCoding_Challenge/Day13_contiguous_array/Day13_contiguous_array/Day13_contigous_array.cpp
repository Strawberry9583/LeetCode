#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;


//solution 1: brute force;
class Solution1 {
public:
	int findMaxLength(vector<int>& nums) {
		int result = 0;
		for (int begin = 0; begin<nums.size(); ++begin) {
			int sum = nums[begin] == 1 ? 1:-1;
			for (int end = begin + 1; end < nums.size(); ++end) {
				sum += nums[end] == 1 ? 1 : -1;
				if (sum == 0&&result<(end-begin+1)) {
					result = end - begin + 1;
				}
			}
		}
		return result;
	}
};

//solution2: every time encountering the num recored, 
//it indicats that intermediate have same amounts of 0 and 1;
class Solution2 {
public:
	int findMaxLength(vector<int>& nums) {
		if (nums.size() < 2) {
			return 0;
		}
		//record the sum in [0,idx] which is not fitted with the requirement with sum == 0;
		std::unordered_map<int, int> exceedednum2idx;
		int result = 0;
		int sum =0;
		for (int idx = 0; idx < nums.size(); ++idx) {
			sum += nums[idx]==1?1:-1;
			int temp_result = 0;
			//if sum==0, then the range is [0,idx] with idx+1 numbers;
			if (sum == 0) {
				temp_result = idx + 1;
			}
			//if sum!=0, then check whether same sum occurred;
			else{
				auto found = exceedednum2idx.find(sum);
				if (found == exceedednum2idx.end()) {
					exceedednum2idx[sum] = idx;
				}
				else {
					temp_result = idx-found->second;
				}
			}
			if (temp_result> result) {
				result = temp_result;
			}
		}
		return result;
	}
};

int main() {
	Solution2 sol;
	std::cout << sol.findMaxLength(std::vector<int>{0, 0, 1, 0, 0, 0, 1, 1});
	std::cin.get();
	return 0;
}