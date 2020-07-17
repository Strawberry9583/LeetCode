#include<iostream>
#include<string>
#include<sstream>
using namespace std;

//scan the words, then insert to the end;
class Solution1 {
public:
	string reverseWords(string s) {
		int right=0;
		for (; right<s.size();++right) {
			if (s[right] == ' ') {
				continue;
			}
			else {
				break;
			}
		}
		s.erase(s.begin(), s.begin() + right);
		right = s.size() - 1;
		for (; right > 0; --right) {
			if (s[right] == ' ') {
				continue;
			}
			else {
				break;
			}
		}
		s.erase(s.begin() + right + 1, s.end());
		int idx = 0, length = s.size();
		int insert_idx = 0;
		while (idx<length) {
			int space_idx = s.find_first_of(' ');
			if (space_idx == string::npos) {
				break;
			}
			else {
				idx += space_idx+1;
				s.insert(s.end() - insert_idx, ' ');
				//++insert_idx;
				s.insert(s.end() - insert_idx, s.begin(),s.begin()+space_idx);
				insert_idx += space_idx+1;
				s.erase(0, space_idx+1);
			}
			int nonspace_idx = s.find_first_not_of(' ');
			idx += nonspace_idx;
			s.erase(0, nonspace_idx);
		}
		return s;
	}
};

// solution2
// reverse two times;
class Solution {
public:
	string reverseWords(string s) {
		s = ' ' + s + ' ';
		std::reverse(s.begin(), s.end());
		int idx = 0;
		while (idx<s.size()) {
			int next_left = s.find_first_not_of(' ',idx);
			int next_right = s.find_first_of( ' ',next_left);
			if (next_left == string::npos || next_right == string::npos) {
				break;
			}
			std::reverse(s.begin() + next_left, s.begin() + next_right);
			idx = next_right;
		}
		int right = 0;
		for (; right<s.size(); ++right) {
			if (s[right] == ' ') {
				continue;
			}
			else {
				break;
			}
		}
		s.erase(s.begin(), s.begin() + right);
		right = s.size() - 1;
		for (; right > 0; --right) {
			if (s[right] == ' ') {
				continue;
			}
			else {
				break;
			}
		}		
		s.erase(s.begin()+right+1, s.end());
		int cur_idx = 1, length = s.size();
		for (int idx = 1; idx < length; ++idx) {
			if (s[cur_idx] == ' '&&s[cur_idx - 1] == ' ') {
				s.erase(s.begin() + cur_idx - 1);
			}
			else {
				++cur_idx;
			}
		}
		return s;
	}
};

int main() {
	string test = "   a   b  c d   e  ";
	std::cout << Solution().reverseWords(test);
	cin.get();
	return 0;
}