#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

// sorted permutation + check
class Solution {
public:
	string largestTimeFromDigits(vector<int>& A) {
		std::sort(A.begin(), A.end());
		std::vector<std::vector<int>> all_permutation = {A};
		while (std::next_permutation(A.begin(),A.end())) {
			all_permutation.emplace_back(A);
		}
		for (int idx = 0; idx < all_permutation.size();) {
			if (if_valide(all_permutation[idx])) {
				++idx;
			}
			else {
				all_permutation.erase(all_permutation.begin() + idx);
			}
		}
		string result;
		if (!all_permutation.empty()) {
			for (int idx = 0; idx < 4; ++idx) {
				result+=std::to_string((*all_permutation.rbegin())[idx]);
			}
			result.insert(result.begin() + 2, ':');
		}
		return result;
	}
private:
	bool if_valide(const vector<int>& digits) {
		if (digits[2] >5) {
			return false;
		}
		else {
			if (digits[0] == 0 || digits[0] == 1) {
				return true;
			}
			else if (digits[0] == 2&&digits[1]<4) {
				return true;
			}
			else {
				return false;
			}
		}
	}
};

int main() {
	std::vector<int> test_vec{1,9,6,0 };
	std::cout << Solution().largestTimeFromDigits(test_vec);
	cin.get();
	return 0;
}