#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		std::vector<int> result(digits);
		result.insert( result.begin(),0);
		++(*result.rbegin());
		for (auto && ele = result.rbegin(); ele != result.rend(); ++ele) {
			if ((*ele) == 10) {
				(*ele) = 0;
				++(*(ele + 1));
			}
			else {
				break;
			}
		}
		if ((*result.begin()) == 0) {
			result.erase(result.begin());
		}
		return result;
	}
};

int main() {
	Solution sol;
	auto ans = sol.plusOne(std::vector<int>{9, 1, 9, 3});
	std::cin.get();
	return 0;
}