//You are given a string, s, and a list of words, words, that are all of the same length.Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.
//
//Example 1:
//
//Input:
//s = "barfoothefoobarman",
//words = ["foo", "bar"]
//Output : [0, 9]
//	Explanation : Substrings starting at index 0 and 9 are "barfoor" and "foobar" respectively.
//	The output order does not matter, returning[9, 0] is fine too.
//	Example 2 :
//
//	Input :
//	s = "wordgoodstudentgoodword",
//	words = ["word", "student"]
//	Output : []

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>


using namespace std;

class Solution {
public:
	vector<int> findSubstring(string s, vector<string> & words) {
		if (words.empty()) {
			return vector<int>();
		}
		//record the string and its time of occurance;
		map<string, int> map_s2i;
		for (auto & i : words) {
			if (map_s2i.find(i) != map_s2i.end()) {
				++map_s2i[i];
			}
			else {
				map_s2i[i]=1;
			}
		}
		//backup for map;
		auto map_backup = map_s2i;
		vector<int> result;
		for (int i = 0; i + words.size()*words[0].size()-1 < s.size(); ++i) {
			map_s2i = map_backup;
			//starting from idx=i;
			int match_num = 0;
			bool is_matched = false;
			while (match_num<words.size()) {
				string temp_str = s.substr(i + match_num*words[0].size(), words[0].size());
				
				if (map_s2i.find(temp_str) != map_s2i.end()) {
					if (map_s2i[temp_str] > 0) {
						//Current string matched, next words begins to match.
						--map_s2i[temp_str];
						++match_num;
						//all string matched, it's a success.
						if (match_num == words.size()) {
							is_matched = true;
							break;
						}
					}
					//Current words fails to match, then next round begins.
					else {
						break;
					}
				}
				else {
					break;
				}
			}
			if (is_matched) {
				result.push_back(i);
			}
		}
		return result;
	}

};


int main() {
	Solution sol;
	vector<string> words{ "foo","bar" };
	auto ans=sol.findSubstring("wordgoodgoodgoodbestword", vector<string>{"word", "good", "best", "good"});
	for (auto & i : ans) {
		cout << i << "  ";
	}


	cin.get();
	return 0;
}