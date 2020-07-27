#include<vector>
#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
	bool isPowerOfTwo(int n) {
		//exclude the case of n=0 and the negative overflow of negative num;
		if (n <= 0) {
			return false;
		}
		else {
			// n&(n-1) is the num, deleting the last '1' of binary codes;
			return n&(n - 1) ? false : true;
		}
	}
};

int main() {
	cin.get();
	return 0;
}