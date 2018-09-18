#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<string>



using namespace std;



class Solution {
public:
	////bool compare(const string & s1, const string & s2)
	//{
	//	return s1.length() < s2.length();
	//}
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 1)
		{
			strs.size();

			return strs[0];
		}
		else
		{
			sort(strs.begin(), strs.end(), [](const string & s1, const string & s2) {return s1.length() < s2.length(); });
			//sort(strs.begin(), strs.end(), compare);
			string result = compare_two(strs[0], strs[1]);
			for (int i = 2; i < strs.size(); ++i)
			{
				result = compare_two(result, strs[i]);
				if (result == "")
				{
					break;
				}
			}
			return result;
		}

	}
	string compare_two(const string & s1, const string & s2)
	{
		int i = 0;
		while (s1[i]==s2[i])
		{
			++i;
		}
		return s1.substr(0, i);
	}
};
int main()
{
	Solution sol;
	vector<string> strs = { "flower","flow","flight" };
	string result=sol.longestCommonPrefix(strs);
	cout << result;
	cin.get();
	return 0;
}