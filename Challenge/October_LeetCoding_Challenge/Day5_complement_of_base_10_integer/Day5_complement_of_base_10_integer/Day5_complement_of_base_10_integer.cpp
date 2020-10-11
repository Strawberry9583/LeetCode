#include<iostream>
#include<sstream>
#include<string>
#include<bitset>

using namespace std;
// use bitset to transform the number to binary string;
class Solution1 {
	
public:
	int bitwiseComplement(int N) {
		if (N == 0) {
			return 1;
		}
		std::bitset<32>m_bits(N);
		int idx = 0;
		for (idx = 31; idx>=0; --idx) {
			if (m_bits[idx]) {
				break;
			}
		}
		string result;
		for (int i = idx; i >= 0; --i) {
			if (m_bits[i]) {
				result += '0';
			}
			else {
				result += '1';
			}
		}
		return std::stoi(result,nullptr,2);
	}
};
//
//Hints
//what is the relationship between input and output
//input + output = 111....11 in binary format
//Is there any corner case ?
//0 is a corner case expecting 1, output > input
//Intuition
//Let's find the first number X that X = 1111....1 > N
//And also, it has to be noticed that,
//N = 0 is a corner case expecting1 as result.

class Solution2 {
public:
	int bitwiseComplement(int N) {
		int X = 1;
		while (N > X) X = X * 2 + 1;
		return X-N;
	}
};


//N ^ bitwiseComplement(N) = 11....11 = X
//bitwiseComplement(N) = N ^ X
class Solution {
public:
	int bitwiseComplement(int N) {
		int X = 1;
		while (N > X) X = X * 2 + 1;
		return X^N;
	}
};

int main() {
	int N = 10;
	std::cout << Solution().bitwiseComplement(N);
	cin.get();
	return 0;
}