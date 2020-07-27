#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<bitset>

using namespace std;

//Time limit excceed;
class Solution1 {
public:
	int rangeBitwiseAnd(int m, int n) {
		int result = m;
		for (int cur = m + 1; cur <= n; ++cur) {
			result = result&cur;
		}
		return result;
	}
};

//solution 2: check the m&n bits, which is true;
class Solution2 {
public:
	int rangeBitwiseAnd(int m, int n) {
		std::bitset<32> m_bits(m);
		std::bitset<32> n_bits(n);
		//if bits of n> bits of m, then result is zero;
		for (int idx = 31; idx >= 0; --idx) {
			if (n_bits[idx]) {
				if (m_bits[idx]) {
					break;
				}
				else {
					return 0;
				}
			}
		}
		//if bits of n= bits of m, then check every true bits of the n&m;
		int subtract = n - m;
		std::bitset<32> sub_bits(n&m);
		for (int idx = 0; idx < sub_bits.size(); ++idx) {
			if (sub_bits[idx]) {
				if (std::pow(2, idx) <= subtract) {
					sub_bits[idx] = false;
				}
			}
		}
		return sub_bits.to_ulong();
	}
};


//solution3: find the leftmost same bits;
class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		int c = 0;
		while (m != n) {
			m >>= 1;
			n >>= 1;
			++c;
		}
		return n << c;


	}
};
int main() {
	Solution sol;
	std::cout<<sol.rangeBitwiseAnd(5, 7);
	std::cin.get();
	return 0;
}