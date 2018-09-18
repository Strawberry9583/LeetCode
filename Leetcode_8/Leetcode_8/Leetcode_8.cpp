#include<iostream>
#include<string>
#include<cctype>

using namespace std;

class Solution {
public:
	
	int myAtoi(string str) {
		int begin = 0;
		int end = 0;
		bool num_start = false;
		for (int i = 0; i < str.length(); ++i)
		{
			
			
			if (  (!num_start)  && ( isdigit(str[i]) || str[i] == '+' ||str[i] == '-') )
			{
				begin = i;
				end = begin;
				num_start = true;
			}
			else if(num_start && isdigit(str[i]))
			{
				++end;
			}
			else if (num_start && !isdigit(str[i]))
			{
				break;
			}
			
		}

		if (!num_start )
		{
			return 0;
		}

		for (int i = 0; i < begin; ++i) {
			if ( (!isspace(str[i])) && (!(isdigit(str[i]))) && (str[i] != '+') && (str[i] != '-'))
			{
				return 0;
			}
		}

		int result = 0;
		bool minus = false;
		if (str[begin] == '+')
		{
			++begin;
		}
		else if (str[begin] == '-')
		{
			minus = true;
			++begin;
		}

		if (begin > end)
		{
			return 0;
		}
		for (int i = begin; i <= end; ++i)
		{

			if (result > (INT_MAX-(str[i] - 48) )/ 10 )
			{
				return INT_MAX;
			}
			else if (result < (INT_MIN + (str[i] - 48)) / 10)
			{
				return INT_MIN;
			}
			else if (minus)
			{
				result = result*10- (str[i] - 48);
			}
			else
			{
				result = result * 10 + (str[i] - 48);
			}
		}
		return result;
	}
};


int main() {

	string s("    010");

	cout << Solution().myAtoi(s);
	system("pause");
	return 0;
}