#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
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
	std::vector<int> test_vec{ 3,0,6,1,5 };
	std::cout << Solution().hIndex(test_vec);
	cin.get();
	return 0;
}