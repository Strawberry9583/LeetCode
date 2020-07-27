#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

// binary search;
// if with sorted citations, find the last interger H, satisfying the bottom H_th paper's
// citations is equel or greater than H;
class Solution {
public:
	int hIndex(vector<int>& citations) {
		int left = 0, right = citations.size() - 1;
		while (left<=right) {
			int mid = left + (right - left) / 2;
			if (*(citations.rbegin()+mid) >= mid + 1) {
				left = mid+1;
			}
			else {
				right = mid-1;
			}
		}
		return left;
	}
};

// if without ordered citations, can record the map, which is then
// idx h to the number of papars with equal or greater citatations then h.
class Solution2 {
public:
	int hIndex(vector<int>& citations) {
		// idx h to the number of papars with equal or greater citatations then h;
		std::vector<int> h2gqnum(citations.size() + 1, 0);
		for (auto & cit : citations) {
			if (cit >= citations.size()) {
				++h2gqnum.back();
			}
			else {
				++h2gqnum[cit];
			}
		}
		// the accumulative paper numbers;
		int paper = 0;
		int i = 0;
		for (i = citations.size(); i >= 0; --i) {
			paper += h2gqnum[i];
			if (paper >= i) {
				break;
			}
		}
		return i;
	}
};

int main() {
	Solution sol;
	std::vector<int> test_vec = { 1};
	std::cout << sol.hIndex(test_vec);
	cin.get();
	return 0;
}