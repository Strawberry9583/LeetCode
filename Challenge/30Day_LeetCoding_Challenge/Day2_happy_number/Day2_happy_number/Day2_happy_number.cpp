#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
	bool isHappy(int n) {
		if (n <= 0) {
			return false;
		}
		std::set<int> history;
		while (history.find(n)==history.end()) {
			history.insert(n);
			int next = 0;
			while (n!=0) {
				next+= (n % 10)*(n % 10);
				n = n / 10;
			}
			if (next == 1) {
				return true;
			}
			else {
				n = next;
			}
		}
		return false;
	}
};

int main() {
	Solution sol;
	if (sol.isHappy(19)) {
		cout << "true";
	}
	else {
		cout << "false";
	}

	std::cin.get();
	return 0;
}