#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Solution {
public:
	long int arrangeCoins(long int n) {
		if (n < 1) { return 0; }
		long int left = 1, right = n;
		while (left<=right) {
			long int mid = left + (right - left) / 2;
			long long int temp_mid = (mid*(mid + 1)) / 2;
			if (temp_mid > n) {
				right = mid-1;
			}
			else if (temp_mid == n) {
				left = mid + 1;
			}
			else if (temp_mid < n) {
				left = mid + 1;
			}
		}
		return left - 1;
	}
};

int main() {
	std::cout << Solution().arrangeCoins(5);
	cin.get();
	return 0;
}