#include<string>
#include<vector>
#include<iostream>

using namespace std;


class Solution {
public:
	void reverseString(vector<char>& s) {
		int i = 0, j = s.size() - 1;
		while (i<j) {
			char temp = s[i];
			s[i] = s[j];
			s[j] = temp;
			++i; --j;
		}
	}
};

int main() {

	cin.get();
	return 0;
}