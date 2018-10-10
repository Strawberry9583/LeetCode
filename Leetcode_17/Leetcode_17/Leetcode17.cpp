#include<iostream>
#include<algorithm>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
#include<string>

using namespace std;


class Solution {
public:
	vector<string> letterCombinations(string digits) {
		if (digits.empty())
		{
			return vector<string>();
		}
		map<char, int> digit_num = { make_pair('2',3),make_pair('3',3),make_pair('4',3),make_pair('5',3),make_pair('6',3)
			,make_pair('7',4),make_pair('8',3),make_pair('9',4) };
		map<char, vector<int> > map_char2int = { make_pair('2',vector<int>{'a','b','c'}),make_pair('3',vector<int>{'d','e','f'}),make_pair('4',vector<int>{'g','h','i'})
			,make_pair('5',vector<int>{'j','k','l'}) ,make_pair('6',vector<int>{'m','n','o'}) ,make_pair('7',vector<int>{'p','q','r','s'})
			,make_pair('8',vector<int>{'t','u','v'})
			,make_pair('9',vector<int>{'w','x','y','z'}) };
		vector<int> recurrent_time;
		stack<int> recurrent_stack;
		recurrent_stack.push(1);
		for (int i = 0; i < digits.size()-1; ++i) {

			recurrent_stack.push(recurrent_stack.top()*digit_num[*(digits.end() - 1 - i)]);
		}
		while (!recurrent_stack.empty()){
			recurrent_time.push_back(recurrent_stack.top());
			recurrent_stack.pop();
		}
		vector<string> result(digit_num[digits[0]] * recurrent_time[0], digits);

		for (int i = 0; i < digits.size(); ++i) {
			int n = 0;

			while (n<result.size())
			{
				int temp = 0;

				while (temp<result.size()/(recurrent_time[i]* map_char2int[digits[i]].size()))
				{
					int x = 0;
					while (x<map_char2int[digits[i]].size())
					{
						int count = 0;
						while (count<recurrent_time[i])
						{
							result[n][i] = map_char2int[digits[i]][x];
							++count;
							++n;
						}
						++x;
					}
					++temp;
				}
			}
		}
		return result;
	}
};


int main()
{
	Solution sol;
	string test("234");
	auto result= sol.letterCombinations(test);
	for (auto & i : result) {
		cout << i << endl;
	}
	cin.get();
	return 0;
}



