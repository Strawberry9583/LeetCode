#include<string>
#include<iostream>
#include<vector>
#include<list>
#include<stack>

using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0") {
			return string("0");
		}
		if (num2.size() > num1.size()) {
			std::swap(num1, num2);
		}
		std::vector<int> result(num1.size() + num2.size(), 0);
		for (int i = 0; i < num1.size(); ++i) {
			for (int j = 0; j < num2.size(); ++j) {
				//int n1 = num1[i] - '0';
				//int n2 = num2[j] - '0';
				//if(n1)
				int digit = i + j;
				result[digit] += (num1[num1.size()-1-i] - '0')*(num2[num2.size()-1-j] - '0');;
				while (digit<result.size()) {
					if (result[digit] < 10) {
						break;
					}
					else {
						result[digit + 1] += result[digit] / 10;
						result[digit] = result[digit] % 10;
						++digit;
					}
				}
			}
		}
		string ans;
		int end_idx = result.size() - 1;
		for (; end_idx >= 0; --end_idx) {
			if (result[end_idx] != 0) {
				break;
			}
		}
		for (int i = end_idx; i >= 0; --i) {
			ans += result[i] + '0';
		}
		return ans;
	}
};

int main() {
	Solution sol;
	string num1 = "10", num2 = "10";
	std::cout << sol.multiply(num1, num2);


	std::cin.get();
}