// problem 168: Excel Sheet Column Title
//Given a positive integer, return its corresponding column title as appear in an Excel sheet.
//
//For example :
//
//1->A
//2->B
//3->C
//...
//26->Z
//27->AA
//28->AB
//...
//Example 1:
//
//Input: 1
//	Output : "A"


#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
	string convertToTitle(int n) {
		string result;
		while (n > 0) {
			result += (n - 1) % 26 + 'A';
			//n-=n%26;
			n = (n - 1) / 26;
		}
		std::reverse(result.begin(), result.end());
		return result;
	}
};

int main() {
	cin.get();
	return 0;
}