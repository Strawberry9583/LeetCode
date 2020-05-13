#include<iostream>
#include<unordered_map>
#include<string>
#include<list>
#include<array>
using namespace std;

//linked hashmap;
class Solution {
public:
	int firstUniqChar(string s) {
		std::unordered_map<char, std::pair<std::list<std::pair<char,int>>::iterator,int>> char2iterandnum;
		std::list<std::pair<char,int>> data;
		for (int idx = 0; idx < s.size(); ++idx) {
			auto find_ele = char2iterandnum.find(s[idx]);
			if (find_ele == char2iterandnum.end()) {
				data.emplace_back(s[idx],idx);
				char2iterandnum.emplace(s[idx], std::make_pair(--data.end(), 1));
			}
			else {
				if (find_ele->second.second == 1) {
					data.erase(find_ele->second.first);
					++char2iterandnum[s[idx]].second;
				}
				else {
					++char2iterandnum[s[idx]].second;
				}
			}
		}
		if (data.empty()) {
			return -1;
		}
		else {
			return data.front().second;
		}
	}
};

//scan the string two time
class Solution_2 {
public:
	int firstUniqChar(string s) {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		int count[26] = { 0 };
		for (int i = 0; i < s.size(); ++i) {
			count[s[i] - 'a'] += 1;
		}

		for (int i = 0; i < s.size(); ++i) {
			if (count[s[i] - 'a'] == 1)
				return i;
		}
		return -1;
	}
};

int main() {

	std::cin.get();
	return 0;
}