#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;



class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& A) {
		int even_num = 0;
		for (int idx = 0; idx < A.size(); ++idx) {
			if (A[idx] % 2) {

			}
			else {
				if (even_num != idx) {
					std::swap(A[idx], A[even_num]);
				}
				++even_num;
			}
		}
		return A;
	}
};


int mina() {

	cin.get();
	return 0;
}