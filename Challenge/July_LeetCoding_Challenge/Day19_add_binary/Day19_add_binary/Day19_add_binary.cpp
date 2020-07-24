#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		auto result = a;
		if (result.size() < b.size()) {
			result = b;
			b = a;
		}
		int flag = 0;
		for (int idx = 0; idx < result.size(); ++idx) {
			int a_ele = result[result.size() - 1 - idx] - '0';
			int b_ele = 0;
			if (idx < b.size()) {
				b_ele = b[b.size() - 1 - idx] - '0';
			}
			int ele_sum = a_ele + b_ele + flag;
			if (ele_sum == 3) {
				flag = 1;
			}
			else if (a_ele + b_ele + flag == 2) {
				result[result.size() - 1 - idx] = '0';
				flag = 1;
			}
			else if (a_ele + b_ele + flag == 1) {
				result[result.size() - 1 - idx] = '1';
				flag = 0;
			}
			else {
				result[result.size() - 1 - idx] = '0';
			}
		}
		if (flag > 0) {
			result = '1' + result;
		}
		return result;
	}
};

int main() {
	cin.get();
	return 0;
}