#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
	bool buddyStrings(string A, string B) {
		if (A.size() != B.size()) {
			return false;
		}
		int diff_num = 0;
		int pos1, pos2;
		for (int idx = 0; idx < A.size(); ++idx) {
			if (A[idx] != B[idx]) {
				if (diff_num == 0) {
					++diff_num;
					pos1 = idx;
				}
				else if (diff_num == 1) {
					++diff_num;
					pos2 = idx;
				}
				else {
					return false;
				}
			}
		}
		if (diff_num == 2) {
			return A[pos1] == B[pos2] && A[pos2] == B[pos1];
		}
		else if (diff_num == 0) {
			std::vector<int> freq(26, 0);
			for (int idx = 0; idx < A.size(); ++idx) {
				++freq[A[idx] - 'a'];
				if (freq[A[idx] - 'a'] >= 2) {
					return true;
				}
			}
			return false;
		}
		else {
			return false;
		}
	}
};


int main() {
	cin.get();
	return 0;
}