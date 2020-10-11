#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


class Solution1 {
public:
	int removeCoveredIntervals(vector<vector<int>>& intervals) {
		int result = 0;
		for (int i = 0; i < intervals.size(); ++i) {
			bool is_covered = false;
			for (int j = 0; j < intervals.size(); ++j) {
				if (i != j && intervals[j].front() <= intervals[i].front() && intervals[j].back() >= intervals[i].back()) {
					is_covered = true;
					break;
				}
				else {
					continue;
				}
			}
			if (!is_covered) {
				++result;
			}
		}
		return result;
	}
};


//Solution 1, sort
//Sort the array, and note the previous left and right bound.
//For evert interval v,
//if v[0] > left && v[1] > right,
//It's a new uncovered interval,
//so we increment ++res.
//
//Complexity: time O(NlogN), space O(1)

class Solution {
public:
	int removeCoveredIntervals(vector<vector<int>>& A) {
		int res = 0, left = -1, right = -1;
		sort(A.begin(), A.end());
		for (auto& v : A) {
			if (v[0] > left && v[1] > right) {
				left = v[0];
				++res;
			}
			right = max(right, v[1]);
		}
		return res;
	}
};

int main() {
	cin.get();
	return 0;
}