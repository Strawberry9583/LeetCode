#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//Use division to solve the problem;
class Solution1 {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		std::vector<int> result(nums.size(),0);
		int product_all = 1;
		//flag to indicate whether 0 exists;
		bool if_regular = true;
		for (auto & ele : nums) {
			if (ele == 0) {
				if_regular = false;
				break;
			}
			product_all *= ele;
		}
		//if 0 exists; then can use all product divide;
		if (if_regular) {
			for (int idx = 0; idx < result.size(); ++idx) {
				result[idx] = product_all / nums[idx];
			}
		}
		else {
			for (int idx = 0; idx < result.size(); ++idx) {
				int temp_result = 1;
				for (int cur = 0; cur < result.size(); ++cur) {
					if (cur != idx) {
						temp_result *= nums[cur];
						//if temp_result==0, then result will be 0 surely.
						if (temp_result == 0) {
							break;
						}
					}
				}
				result[idx] = temp_result;
			}
		}
		return result;
	}
};

// solve it without division and in O(n) space complexity.
class Solution2 {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		std::vector<int> result(nums.size(), 1);
		//left_product[i] is the product of range [0,i);
		std::vector<int> left_product(nums.size(), 1);
		for (size_t idx = 1; idx < left_product.size(); ++idx) {
			left_product[idx] = left_product[idx - 1]*nums[idx-1];
		}
		//right_product is the product of elements in (idx,nums.size());
		int right_product = 1;
		for (int idx = result.size() - 1; idx >= 0; --idx) {
			result[idx] = left_product[idx] * right_product;
			right_product *= nums[idx];
		}
		return result;
	}
};

// solve it without division and in O(1) space complexity.
class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		std::vector<int> result(nums.size(), 1);
		//result[i] is the product of range [0,i);
		for (size_t idx = 1; idx < result.size(); ++idx) {
			result[idx] = result[idx - 1] * nums[idx - 1];
		}
		//right_product is the product of elements in (idx,nums.size());
		int right_product = 1;
		for (int idx = result.size() - 1; idx >= 0; --idx) {
			result[idx] *=right_product;
			right_product *= nums[idx];
		}
		return result;
	}
};
int main() {
	Solution sol;
	auto ans = sol.productExceptSelf(std::vector<int>{1, 2, 3, 4});
	std::cin.get();
	return 0;
}