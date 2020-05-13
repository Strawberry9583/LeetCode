#include<vector>
#include<iostream>
#include<algorithm>
#include<bitset>
#include<cmath>
using namespace std;

//use bitset
class Solution {
public:
	int findComplement(int num) {
		std::bitset<32> bits(num);
		int digit_num = static_cast<int>(std::log2(num) + 1);
		for (int idx = 0; idx <digit_num ; ++idx) {
			bits.flip(idx);
		}
		return bits.to_ulong();
	}
};

//use mask code to and with original num;
class Solution2 {
public:
	int findComplement(int num) {
		int mask = 1;

		while (mask < num) {
			mask = (mask << 1) + 1;
		}

		return num ^ mask;
	}
};
int main() {
	std::cout << Solution().findComplement(5);
	std::cin.get();
	return 0;
}