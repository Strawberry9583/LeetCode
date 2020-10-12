#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_set>

using namespace std;

// solution1: check every possible characters from 'a' to 'z';
// if char, x, can be put, it must satisfy that in range of [chars' idx, end], every char > x will occur.;
class Solution1 {
public:
	string removeDuplicateLetters(string s) {
		std::vector<int> charflag(27, -1);
		int char_num = 0;
		for (int idx = 0; idx < s.size(); ++idx) {
			if(charflag[s[idx]-'a']==-1){
				charflag[s[idx] - 'a'] = 1;
				++char_num;
			}
		}

		for (int idx = 0,cur_num=1; idx < charflag.size(); ++idx) {
			if (charflag[idx] != -1) {
				charflag[idx] = char_num - cur_num;
				++cur_num;
			}
		}


		int last_pos = -1;
		string result;
		for (int idx = 0; idx < char_num; ++idx) {
			for (int trial_idx = 0; trial_idx < charflag.size(); ++trial_idx) {
				if (charflag[trial_idx]!=-1) {
					char trial_char = trial_idx + 'a';
					if (check(s, trial_char, last_pos,charflag)) {
						result += trial_char;
						charflag[trial_idx] = -1;
						for (int i=0; i < trial_idx; ++i) {
							if (charflag[i]>0) {
								--charflag[i];
							}
						}
						break;
					}
				}
			}
		}
		return result;
	}
private:
	bool check(const string & s, char trial, int & last_pos,const std::vector<int> & requirement) {
		//bool trial_found = false;
		int found_idx = -1;
		std::unordered_set<char> bigger_num;
		for (int idx = last_pos+1; idx < s.size(); ++idx) {
			if (found_idx!=-1) {
				if (s[idx] > trial&&requirement[s[idx]-'a']!=-1&&bigger_num.find(s[idx])==bigger_num.end()) {
					bigger_num.emplace(s[idx]);
					if (bigger_num.size() == requirement[trial - 'a']) {
						last_pos = found_idx;
						return true;
					}
				}
			}
			else {
				if (s[idx] == trial) {
					found_idx = idx;
					if (requirement[trial - 'a'] == 0) {
						last_pos = found_idx;
						return true;
					}
				}
			}
		}
		return false;
	}
};


class Solution {
public:
	string removeDuplicateLetters(string s) {
		vector<int> dict(256, 0);
		vector<bool> visited(256, false);
		for (auto ch : s)  dict[ch]++;
		string result = "0";
		/** the key idea is to keep a monotically increasing sequence **/
		for (auto c : s) {
			dict[c]--;
			/** to filter the previously visited elements **/
			if (visited[c])  continue;
			while (c < result.back() && dict[result.back()]) {
				visited[result.back()] = false;
				result.pop_back();
			}
			result += c;
			visited[c] = true;
		}
		return result.substr(1);
	}
};


int main() {
	string s = "cbacdcbc";
	std::cout << Solution().removeDuplicateLetters(s);
	cin.get();
	return 0;
}