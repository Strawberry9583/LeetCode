/*
38. Count and Say
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ¡Ü n ¡Ü 30, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

Example 1:

Input: 1
Output: "1"
Example 2:

Input: 4
Output: "1211"*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;


class Solution {
public:
	string countAndSay(int n) {
		if (n == 1) {
			return "1";
		}
		else {
			//get the previous string of n-1;
			//then, count the previous string of n-1 can get string of n;
			string str_pre = countAndSay(n - 1);
			string result;
			//the counter of the specific char;
			int num_count = 1;
			//the char occurred;
			char num = str_pre[0];
			for (int i = 1, j = 0; i <= str_pre.size(); ++i) {
				if (str_pre[i] == str_pre[j]) {
					++num_count;
				}
				else {
					result += to_string(num_count);
					result += num;
					num_count = 1;
					j = i;
					num = str_pre[j];
				}
			}
			return result;
		}
	}
};

int main() {
	Solution sol;
	int n = 6;
	string res = sol.countAndSay(n);
	std::cout << res << std::endl;

	cin.get();
	return 0;
}