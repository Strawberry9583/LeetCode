#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;


class Solution {
public:
	int romanToInt(string s) {
		map<char, int> compare;
		compare.insert(pair<char, int>('M', 1000));
		compare.insert(pair<char, int>('D', 500));
		compare.insert(pair<char, int>('C', 100));
		compare.insert(pair<char, int>('L', 50));
		compare.insert(pair<char, int>('X', 10));
		compare.insert(pair<char, int>('V', 5));
		compare.insert(pair<char, int>('I', 1));
		int result = 0;
		if (s.size() == 1)
		{
			result = compare[s[0]];
		}
		else
		{
			for (auto first = s.begin(); first != s.end();)
			{
				auto next = first + 1;
				if (next == s.end())
				{
					result += compare[*first];
					++first;
				}
				else
				{
					if (compare[*first] == compare[*next])
					{
						result += compare[*first];
						++first;
					}
					else if (compare[*first] < compare[*next])
					{
						result += compare[*next] - compare[*first];
						first += 2;
					}
					else
					{
						result += compare[*first];
						++first;
					}
				}


			}
		}
		return result;
	}
};


int main()
{

	Solution sol;
	string temp = "MCMXCIV";
	cout << sol.romanToInt(temp) << endl;
	cin.get();
	return 0;
}