#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;


class Solution {
public:

	string intToRoman(int num) {

		vector<string> Thousands = { "", "M", "MM", "MMM" };
		vector<string> Hundreds = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
		vector<string> Tens = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
		vector<string> Digits = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
		string result = Thousands[num / 1000] + Hundreds[(num % 1000) / 100] + Tens[(num % 100) / 10] + Digits[num % 10];
		return result;
	}
};


int main()
{
	Solution sol;
	cout << sol.intToRoman(1994) << endl;
	cin.get();
	return 0;
}