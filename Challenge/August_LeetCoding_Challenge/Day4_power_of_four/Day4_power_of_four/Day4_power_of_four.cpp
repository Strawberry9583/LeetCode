#include<iostream>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

class Solution1 {
public:
	bool isPowerOfFour(int num) {
		int root = (log2(num)) / 2;
		int power = std::pow(4, root);
		return power == num;
	}
};


// The basic idea is from power of 2, We can use "n&(n-1) == 0" to determine 
// if n is power of 2. For power of 4, the additional restriction is that in binary form, 
// the only "1" should always located at the odd position.For example,
// 4 ^ 0 = 1, 4 ^ 1 = 100, 4 ^ 2 = 10000. So we can use "num & 0x55555555==num" to check 
// if "1" is located at the odd position.
class Solution {
public:
	bool isPowerOfFour(int num) {
		return (num > 0) && ((num & (num - 1)) == 0) && ((num & 0x55555554) == num);
	}
};

int main() {
	std::cout << Solution().isPowerOfFour(4) << std::endl;
	std::cout << Solution().isPowerOfFour(16) << std::endl;
	std::cout << Solution().isPowerOfFour(1) << std::endl;
	cin.get();
	return 0;
}