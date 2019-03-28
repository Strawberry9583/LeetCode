#include<iostream>
#include<vector>
#include<string>

using namespace std;




class Solution {
public:
	bool isMatch(string s, string p) {
		if (p.empty()) return s.empty();

		if (p[1] == '*')
		{
			return isMatch(s, p.substr(2))
				|| (!s.empty()) && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p);
		}
		else
		{
			return (!s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1)));
		}
	}
};



int main(){
	if (Solution().isMatch("mississippi", "mis*is*p*.")) {
		cout << "yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	//vector<int> temp{ 1,2,3 };
	//vector<int> temp1;
	//temp1 = temp;
	//vector<int> temp2(temp1);
	system("pause");
	return 0;
}