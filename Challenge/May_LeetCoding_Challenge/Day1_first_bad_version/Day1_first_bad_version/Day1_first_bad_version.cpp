#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
	bool isBadVersion(int version) { return true; }
	int firstBadVersion(int n) {
		int left = 0, right = n;
		while (left<=n) {
			int mid = left + (right - n) / 2;
			if (isBadVersion(mid)) {
				right = mid;
			}
			else {
				left= mid+1;
			}
		}
		return left;
	}
};

