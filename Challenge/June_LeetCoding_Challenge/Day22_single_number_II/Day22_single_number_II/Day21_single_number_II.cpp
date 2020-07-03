#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


// solution1: count the frequency of numbers;
// Time complexity: O(n), Space complexity: O(n);
class Solution1 {
public:
	int singleNumber(vector<int>& nums) {
		std::unordered_map<int, int> num2freq;
		for (auto & ele : nums) {
			++num2freq[ele];
			if (num2freq[ele] == 3) {
				num2freq.erase(ele);
			}
		}
		return num2freq.begin()->first;
	}
};

// solution2: check every bits of the numbers;
// check every bit, set the bit to 0, when the freq of 1 in numbers can divide 3;
// Time complexity: O(n), Space complexity: O(1);
class Solution2 {
public:
	int singleNumber(vector<int>& nums) {
		int result = 0;
		for (int idx = 0; idx < 32; ++idx) {
			int count = 0;
			for (auto & ele : nums) {
				// firstly, right shift to get the idx_th digit of the ele;
				// then, check the digit whether to be 1;
				if ((ele >> idx) & 1) {
					++count;
				}
			}
			int mask = 0;
			//get the digit if rest is not 0;
			if (count % 3) {
				mask = 1;
				mask <<= idx;
				result |= mask;
			}
		}
		return result;
	}
};

// solution3: similar to solution2, but to construct an operation f() subjucted to f(f(f(1)))=0, f(1)=1;
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int x1 = 0, x2 = 0, mask = 0;
		for (int i : nums) {
			x2 ^= x1 & i;
			x1 ^= i;
			mask = ~(x1 & x2);
			x2 &= mask;
			x1 &= mask;
		}
		return x1;
	}
};

int main() {
	std::vector<int> test_vec{ -2,-2,1,1,-3,1,-3,-3,-4,-2};
	std::cout << Solution().singleNumber(test_vec);
	cin.get();
	return 0;
}