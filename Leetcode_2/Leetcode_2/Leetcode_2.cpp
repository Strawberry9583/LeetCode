#include<iostream>
#include<unordered_map>
#include<algorithm>


using namespace std;
/*BF Alg.
class Solution {
public:
	int lengthOfLongestSubstring(string s) 
	{
		int best_result = 0;
		for (size_t i = 0; i < s.length()-best_result; ++i)
		{
			string temp(s, i, 1);
			int result = 1;
			for (size_t j = i + 1; j < s.length(); ++j)
			{	
				if (temp.find(s[j]) == string::npos)
				{
					temp += s[j];
					++result;
				}
				else
				{
					break;
				}
			}
			if (result > best_result)
			{
				best_result = result;
			}

		}
		return best_result;
	}

};*/
class Solution {
public:
	int lengthOfLongestSubstring(string s)
	{
		int best_result = 0;
		size_t below = 0, above = 0;
		//Actually implement use hash
		unordered_map<char, size_t> h_map;
		auto length = s.length();
		while (below<length && above<length)
		{
			if (h_map.count(s[above]) == 0)
			{
				h_map.insert(pair<char,size_t>(s[above],above));
				++above;
				if (h_map.size() > best_result)
				{
					best_result = h_map.size();
				}
			}
			else
			{
				h_map.erase(s[below]);
				below=h_map[s[below]]
			}
		}
		return best_result;
	}

};


int main()
{
	Solution s;
	string a= "asdffsdajflkasjdflkjfoejglkaskldg";
	cout<<s.lengthOfLongestSubstring(a);
	system("pause");
	return 0;

}