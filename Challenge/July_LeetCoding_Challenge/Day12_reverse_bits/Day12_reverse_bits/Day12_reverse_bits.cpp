#include<vector>
#include<string>
#include<iostream>
#include<bitset>
using namespace std;

class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		std::bitset<32> bits(n);
		int left = 0, right = 31;
		while (left<right) {
			int temp = bits[left];
			bits[left] = bits[right];
			bits[right] = temp;
			++left; --right;
		}
		return bits.to_ulong();
	}
};

int main() {
	std::cout << Solution().reverseBits(43261596);
	cin.get();
	return 0;
}