// problem 171: Excel Sheet Column Number
//Given a column title as appear in an Excel sheet, return its corresponding column number.
//
//For example :
//
//A -> 1
//B -> 2
//C -> 3
//...
//Z -> 26
//AA -> 27
//AB -> 28
//...
//Example 1:
//
//Input: "A"
//	Output : 1

// method: actually it's a 26 decimal problem;
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;


class Solution {
public:
	int titleToNumber(string s) {
		std::vector<long int> length2num(8, 1);
		length2num[1] = 26;
		for (int length = 2; length < 8; ++length) {
			length2num[length] = 26 * length2num[length - 1];
		}
		int result = 0;
		for (int idx = 0; idx < s.size(); ++idx) {
			result += (s[idx] - 'A' + 1)*length2num[s.size() - idx - 1];
		}
		return result;
	}
};



int main() {
	cin.get();
	return 0;
}