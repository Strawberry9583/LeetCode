#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

//method 1: use STL next_permutation to get permutation;
class Solution1 {
public:
	string getPermutation(int n, int k) {
		string s;
		for (int i = 1; i <= n; ++i) {
			s += '0' + i;
		}
		for (int idx = 1; idx < k; ++idx) {
			std::next_permutation(s.begin(), s.end());
		}
		return s;
	}
};


int main() {
	
	std::cin.get();
	return 0;
}