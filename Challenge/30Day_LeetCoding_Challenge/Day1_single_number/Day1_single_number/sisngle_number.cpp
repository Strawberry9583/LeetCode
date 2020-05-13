#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int result = 0;
		//exclusive OR shorted for XOR;
		//when a^b
		//if a==b, then 0;
		//if a!=b, then 1;
		for (const auto & ele : nums) {
			result ^= ele;
		}
		return result;
	}
};

int main() {
	Solution sol;
	std::vector<int> vec{ 4,1,2,1,2,4,5 };
	std::cout << sol.singleNumber(vec) << std::endl;
	std::cin.get();

	return 0;
}