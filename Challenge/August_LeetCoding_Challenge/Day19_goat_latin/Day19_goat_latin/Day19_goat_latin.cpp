#include<string>
#include<vector>
#include<list>
#include<iostream>
#include<set>
#include<sstream>

using namespace std;


class Solution1 {
public:
	string toGoatLatin(string S) {
		std::vector<string> words;
		int pre_idx = 0;
		int idx = 0;
		for ( idx = 0; idx < S.size(); ++idx) {
			if (S[idx] == ' ') {
				words.emplace_back(std::move(S.substr(pre_idx, idx - pre_idx)));
				pre_idx = idx + 1;
			}
		}
		if (idx > pre_idx) {
			words.emplace_back(S.substr(pre_idx, idx - pre_idx));
		}
		string result;
		for (int idx = 0; idx < words.size(); ++idx) {
			if (is_vowel(words[idx].front())) {
				//words[idx].erase(words[idx].begin());
				words[idx] = words[idx] + "ma" + string(idx + 1, 'a');
			}
			else {
				words[idx]= words[idx]+words[idx].front() +"ma"+ string(idx + 1, 'a');
				words[idx].erase(words[idx].begin());
			}
			result += words[idx] + " ";
		}
		if (!result.empty()) {
			result.erase(result.end() - 1);
		}
		return result;

	}
private:
	bool is_vowel(char c) {
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'||
			c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
			return true;
		}
		else {
			return false;
		}
	}
};


class Solution {
public:
	string toGoatLatin(string S) {
		istringstream is(S);
		string temp;
		set<char> v = { 'a', 'e','i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
		int cnt = 1;
		string res;
		while (getline(is, temp, ' ')) {
			if (v.find(temp[0]) == v.end()) {
				temp = temp.substr(1) + temp[0];
			}
			temp += "ma" + string(cnt, 'a');
			res += temp + " ";
			cnt++;
		}
		res.pop_back();

		return res;
	}


};
int main() {
	string str = "Each word consists of lowercase and uppercase letters only";
	auto ans = Solution().toGoatLatin(str);

	std::cout << ans;
	cin.get();
	return 0;
}