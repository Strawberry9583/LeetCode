//Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
//An input string is valid if:
//
//Open brackets must be closed by the same type of brackets.
//Open brackets must be closed in the correct order.
//Note that an empty string is also considered valid.
//
//Example 1:
//
//Input: "()"
//	Output : true
//	Example 2 :
//
//	Input : "()[]{}"
//	Output : true
//	Example 3 :
//
//	Input : "(]"
//	Output : false
//	Example 4 :
//
//	Input : "([)]"
//	Output : false
//	Example 5 :
//
//	Input : "{[]}"
//	Output : true


#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<map>



using namespace std;


class Solution {
public:
	bool isValid(string s) {
		stack<char> ch_stack;
		ch_stack.push('#');
		// # and * indicate the beginning and the end respectively;
		s += '*';
		//contrc the char_map;
		map<char, int> ch_map{make_pair('#',-4), make_pair('(',-3),make_pair('{',-2),
			make_pair('[',-1),make_pair(')',3),make_pair('}',2),make_pair(']',1),make_pair('*',4) };
		for (int i = 0; i < s.size(); ++i) {
			if (ch_map[s[i]] < 0) {
				ch_stack.push(s[i]);
			}
			else if (ch_map[s[i]] + ch_map[ch_stack.top()] == 0) {
				ch_stack.pop();
			}
			else {
				return false;
			}
		}
		if (ch_stack.empty()) {
			return true;
		}

	}
};

int main() {
	string test = "([)]";
	Solution sol;
	if (sol.isValid(test)) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}

	cin.get();
	return 0;
}