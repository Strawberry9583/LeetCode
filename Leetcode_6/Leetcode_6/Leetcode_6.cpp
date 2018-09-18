/*The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line : "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows :

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".*/

#include<iostream>
#include<vector>
#include<string>


using namespace std;



class Solution {
public:
	//string convert(string s, int numRows) 
	//{
	//	string result = string(s.length(), '0');
	//	int unit = 2 * numRows-2;
	//	int unit_num = s.length() / unit;
	//	int rest = s.length() - unit*unit_num;
	//	vector<int> rest_index;
	//	for (int i = 0; i < rest; ++i)
	//	{
	//		if (i < numRows)
	//		{
	//			rest_index.push_back(i);
	//		}
	//		else
	//		{
	//			for (int j = 0; j <= i-numRows; ++j)
	//			{
	//				++rest_index[numRows - 1 -j];
	//			}
	//			
	//		}
	//	}
	//	for (int i = 0; i < s.length(); ++i)
	//	{
	//		int unit_index = i / unit;
	//		int i_rest = i - unit_index*unit;
	//		int row = 0;
	//		if (i_rest < numRows)
	//		{
	//			row = i_rest;
	//		}
	//		else
	//		{
	//			row = 2 * numRows - i_rest-1;
	//		}
	//		int result_i = 0;
	//		if (row == 0)
	//		{
	//			result_i = unit_index;
	//		}
	//		else
	//		{
	//			result_i = unit_num * 2*row + unit_index + rest_index[row];
	//		}
	//		result[result_i] = s[i];
	//	}
	//	return result;
	//}


	string convert(string s, int numRows)
	{
		if (s.length() == numRows || numRows == 1)
		{
			return s;
		}
		string result;

		for (int i = 1; i <= numRows; ++i)
		{
			bool even = true;
			int temp_interval_1 = 2 * (numRows - i), temp_interval_2 = 2 * (i-1);
			if (i == 1 || i == numRows)
			{
				temp_interval_1 = 2 * (numRows - 1);
				temp_interval_2 = temp_interval_1;
			}
			int j = i - 1;
			while (j<s.length())
			{
				result.push_back(s[j]);
				if (even)
				{
					j += temp_interval_1;
					even = false;
				}
				else
				{
					j += temp_interval_2;
					even = true;
				}
			}
		}
		return result;
	}



	
};






int main()
{
	Solution sol;
	string result=sol.convert("PAYPALISHIRING", 3);
	cout << result << endl;
	system("pause");
	return 0;
}