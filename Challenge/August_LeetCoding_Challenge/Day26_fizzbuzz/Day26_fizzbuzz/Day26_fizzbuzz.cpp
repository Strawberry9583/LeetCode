#include<string>
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
	vector<string> fizzBuzz(int n) {
		std::vector<string> result(n);
		for (int idx = 1; idx <= n; ++idx) {
			if (idx % 3 == 0 && idx % 5 == 0) {
				result[idx-1] = "FizzBuzz";
			}
			else if (idx % 3 == 0) {
				result[idx-1] = "Fizz";
			}
			else if (idx % 5 == 0) {
				result[idx-1] = "Buzz";
			}
			else {
				result[idx-1] = std::to_string(idx);
			}
		}
		return result;
	}
};

int main() {
	auto ans = Solution().fizzBuzz(3);
	cin.get();
	return 0;
}