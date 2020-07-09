#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// soltution1
// compare all the digits in orders;
class Solution1 {
public:
	int hammingDistance(int x, int y) {
		int result = 0;
		int base = 1;
		for (int idx = 0; idx<31; ++idx) {
			int mask = base << idx;
			int x_mask = x&mask;
			int y_mask = y&mask;
			if (x_mask != y_mask) {
				++result;
			}
		}
		return result;
	}
};

// solution2: find the different numbers at first;
// then get how many 1 int the result of OXR (use n&n-1 to get rid of the lowest 1)
class Solution {
public:
	int hammingDistance(int x, int y) {
		int dist = 0, n = x ^ y;
		while (n) {
			++dist;
			n &= n - 1;
		}
		return dist;
	}
};

int main() {

	cin.get();
	return 0;
}