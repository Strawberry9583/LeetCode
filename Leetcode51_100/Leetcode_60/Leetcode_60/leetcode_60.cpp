#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

// solution1: with build-in next_permutation function to loop;
// Time complexity: O(n^2); Space complexity: O(n)
class Solution1 {
public:
	string getPermutation(int n, int k) {
		string result;
		for (int idx = 0; idx < n; ++idx) {
			result += '1' + idx;
		}
		for (int seq = 1; seq < k; ++seq) {
			std::next_permutation(result.begin(), result.end());
		}
		return result;
	}
};

// solution2: Divide and Conquer
// Every time a number digit is fixed from the end to the beginning.
// Time complexity: O(n); Space complexity: O(n)
class Solution {
public:
	string getPermutation(int n, int k) {
		string sequence;
		for (int idx = 0; idx < n; ++idx) {
			sequence += '1' + idx;
		}
		// calc the factorial value 1!, 2!, 3!,...,n!;
		std::vector<int> factorial(n + 1, 1);
		for (int idx = 1; idx < factorial.size(); ++idx) {
			factorial[idx] = factorial[idx - 1] * idx;
		}
		string result;
		// count from 0, then k should minus one;
		--k;
		for (int cur_idx = n - 1; cur_idx >= 0; --cur_idx) {
			// find the add_idx big digit from the sequence;
			int add_idx = k / factorial[cur_idx];
			// add the add_idx big digit;
			result += sequence[add_idx];
			// erase the selected one;
			sequence.erase(sequence.begin() + add_idx);
			// find the new k_th big number from the rest;
			k -= add_idx*factorial[cur_idx];
		}
		return result;
	}
};

int main() {
	std::cout << Solution().getPermutation(4, 9);
	cin.get();
	return 0;
}