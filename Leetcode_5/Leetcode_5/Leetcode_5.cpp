/*Given a string s, find the longest palindromic substring in s.You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

	Output : "bab"

	Note : "aba" is also a valid answer.
	Example :

	Input : "cbbd"

	Output : "bb"*/




//expand from the center£»
/*#include<iostream>
#include<string>

using namespace std;


class Solution {
public:
	string longestPalindrome(string s)
	{

		int even = 0;
		int length = s.length();
		pair<int, int> result (0, 0);
		while (even<length)
		{
			int head = even;
			int tail = even;
			pair<int, int> temp_result;
			if (even == 0 || even == length - 1)
			{
				temp_result.first = head;
				temp_result.second = tail;
			}
			else
			{
				head = even - 1;
				tail = even + 1;
				for (; head >= 0 && tail < length; --head, ++tail)
				{
					if (s[head] != s[tail])
					{
						break;
					}
				}
				temp_result.first = head + 1;
				temp_result.second = tail - 1;
			}

			if (result.second - result.first < temp_result.second - temp_result.first)
			{
				result.first = temp_result.first;
				result.second = temp_result.second;
			}
			++even;

		}
		int odd = 1;
		while (odd<length)
		{
			int head = odd - 1;
			int tail = odd;
			pair<int, int> temp_result;
			
			for (; head >= 0 && tail < length; --head, ++tail)
			{
				if (s[head] != s[tail])
				{
					break;
				}
			}
			if (tail - head != 1)
			{
				temp_result.first = head + 1;
				temp_result.second = tail - 1;
			}

			if(result.second-result.first<temp_result.second-temp_result.first)
			{
				result.first = temp_result.first;
				result.second = temp_result.second;
			}
			++odd;
		}
		string last_result;
		for (int i = result.first; i <= result.second; ++i)
		{
			last_result += s[i];
		}
		return last_result;
	}
};*/
#include<iostream>
#include<vector>
#include<string>

using namespace std;


class Solution {
public:
	string longestPalindrome(string s) {
		int  ** matric;
		matric = new int * [s.length()];
		for (int j = 0; j<s.length(); j++)
		{
			matric[j] = new int [s.length()]; 
		}

		int length = s.length();
		for (int i = 0; i < length; ++i)
		{
			matric[i][i] = 1;

		}
		for (int i = 0, j = 1; j < length; ++i, ++j)
		{
			if (s[i] == s[j])
			{
				matric[i][j] = 1;
			}
		}

		for (int k = 0; k < length - 2; ++k)
		{
			for (int i = 0,  j = k + 2; i < length&&j < length; ++i, ++j)
			{
				if (matric[i + 1][j - 1] == 1 && s[i] == s[j])
				{
					matric[i][j] = 1;
				}
				else
				{
					matric[i][j] = 0;
				}
			}
		}
		pair<int, int > result(0, 0);
		for (int i = 0; i < length; ++i)
		{
			for (int j = i; j < length; ++j)
			{
				if (matric[i][j] == 1 && j - i > result.second - result.first)
				{
					result.first = i;
					result.second = j;
				}
			}
		}
		for (int i = 0; i<s.length(); i++)
		{
			delete[] matric[i]; 
		}
		delete[] matric;
		return s.substr(result.first, result.second - result.first + 1);
	}
};





int main()
{
	Solution solution;
	string test = "abcda";
	string result=solution.longestPalindrome(test);
	cout << result << endl;
	system("pause");
}