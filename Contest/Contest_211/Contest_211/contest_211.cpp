#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<unordered_set>
#include<unordered_map>


using namespace std;

class Solution1 {
public:
	int maxLengthBetweenEqualCharacters(string s) {
		std::vector<int> begin_idx(26, -1);
		int result = -1;
		for (int idx = 0; idx < s.size(); ++idx) {
			if (begin_idx[s[idx] - 'a'] == -1) {
				begin_idx[s[idx] - 'a'] = idx;
			}
			else {
				if (idx - begin_idx[s[idx] - 'a'] - 1 > result) {
					result = idx - begin_idx[s[idx] - 'a'] - 1;
				}
			}
		}
		return result;
	}
};

class Solution {
public:
	string findLexSmallestString(string s, int a, int b) {
		std::unordered_set<string> all_seq;
		string cur_str = s;
		while (all_seq.find(cur_str)==all_seq.end()) {
			all_seq.emplace(cur_str);
			string temp = cur_str;
			cur_str = temp.substr(temp.size()-b) + temp.substr(0, temp.size() - b);
		}
		std::vector<string> all_seq1;
		for (const auto & ele : all_seq) {
			all_seq1.emplace_back(ele);
		}
		for (auto & str : all_seq1) {
			auto min_addtime = get_min(str.front(), a);
			int add_num = min_addtime.front()+'0' - str.front();
			for (auto & c : str) {
				int num = c - '0';
				num += add_num;
				num %= 10;
				c = num + '0';
			}
		}
		std::sort(all_seq1.begin(), all_seq1.end());
		return all_seq1.front();
	}
private:
	std::vector<int> get_min(char c, int add_num) {
		std::map<int, int> min_addfreq;
		int time = 0; int num = c - '0';
		while (min_addfreq.find(num)==min_addfreq.end()) {
			min_addfreq[num] = time;
			++time;
			num += add_num;
			num %= 10;
		}
		return std::vector<int>{min_addfreq.begin()->first, min_addfreq.begin()->second};
	}
};


int main() {
	//std::string test_s = "cabbac";
	//std::cout << Solution1().maxLengthBetweenEqualCharacters(test_s);
	string s = "5525";
	int a = 9, b = 2;
	std::cout << Solution().findLexSmallestString(s, a, b);

	cin.get();
	return 0;
}