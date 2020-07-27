#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	bool isPerfectSquare(int num) {
		unsigned long left = 1, right = num;
		while (left<=right) {
			unsigned long mid = left + (right - left) / 2;
			unsigned long square = mid*mid;
			if (square == num) {
				return true;
			}
			else if (square < num) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
		return false;
	}
};

int main() {
	Solution sol;
	std::cout << sol.isPerfectSquare(15);

	std::cin.get();
	return 0;
}