#include<iostream>
#include<sstream>
#include<string>
#include<unordered_map>
#include<vector>

using namespace std;

class Solution {
public:
	bool wordPattern(string pattern, string str) {
		istringstream s(str);
		string temp_s;
		std::vector<string> vec_s;
		while (getline(s,temp_s,' ') ){
			vec_s.emplace_back(std::move(temp_s));
		}
		if (pattern.size() != vec_s.size()) {
			return false;
		}
		std::vector<string> char2str(26);
		std::unordered_map<string, char> str2char;
		for (int idx = 0; idx < pattern.size(); ++idx) {
			
			if (char2str[pattern[idx] - 'a'].empty()) {
				char2str[pattern[idx] - 'a'] = vec_s[idx];
				auto find_ = str2char.find(vec_s[idx]);
				if (find_ == str2char.end()) {
					str2char[vec_s[idx]] = pattern[idx];
				}
				else if (find_->second != pattern[idx]) {
					return false;
				}
				else {

				}
			}
			else if(char2str[pattern[idx]-'a']!=vec_s[idx]){
				return false;
			}
		}
		return true;
	}
};

int main() {
	string pattern = "abba", str = "dog dog dog dog";
	std::cout << Solution().wordPattern(pattern, str);
	cin.get();
	return 0;
}