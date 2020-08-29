#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

// expand the range firstly with multiplying the length of initial range; (the range length is 7 here);
// uniform the expanded range with minus the initial random numbers;
// construct the ideal divider to generate the target range;
// [1,2,3,4,5,6,7]
// [7,14,21,28,35,42,49]
// [0,1,2,3,4,5,6,7,8,...,48]
// [-9,-8,...39]
// [0,1,2,3,4,...,39]
// [1,2,3,4,5,6,7,8,9,10]
class Solution {
public:
	int rand7() {
		return 0;
	}
	int rand10() {
		int r = rand7();
		int rand49 = r * 7;
		int rand048 = rand49 - rand7();
		int rand_939 = rand048 - 9;
		if (rand_939<0) {
			return rand10();
		}
		else {
			return (rand_939 / 4) + 1;
		}
	}
};

int main() {
	cin.get();
	return 0;
}