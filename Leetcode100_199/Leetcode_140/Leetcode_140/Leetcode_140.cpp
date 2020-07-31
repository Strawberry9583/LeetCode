#include<iostream>
#include<vector>
#include<string>
#include<vector>
#include<unordered_map>


using namespace std;

// solution1: dp top-down with memorization;
// store all possible result in dp_str;
// dp_str[i] is the all break result of range [0,i];
// store all idx of privious possible words in dp;
// dp[i][j]==idx; then wordDict[idx] and be ended with the substr [0,i];
class Solution {
	std::vector<string> result;
public:
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		// transfer into a set to find substring for convinience;
		std::unordered_map<string, int> str2idx;
		for (int idx = 0; idx < wordDict.size(); ++idx) {
			str2idx[wordDict[idx]] = idx;
		}
		// dp[i+1] indicates whether string in range [0,i] can be valid a wordBreak;
		std::vector<std::vector<int>> dp(s.size() + 1, std::vector<int>());
		std::vector<std::vector<string>> dp_str(s.size() + 1, std::vector<string>());
		// -1 indicates the heading;
		dp[0].emplace_back(-1);
		for (int end = 0; end < s.size(); ++end) {
			for (int idx = end; idx >= 0; --idx) {
				// range s[0,idx-1] must also be valid, then to check the existence of range [idx,end] in dict;
				if (!dp[idx].empty()) {
					auto found = str2idx.find(s.substr(idx, end - idx + 1));
					if (found == str2idx.end()) {
						continue;
					}
					// if true then break;
					else {
						dp[end + 1].emplace_back(found->second);
						// if idx=0; the add no word;
						if (idx == 0) {
							dp_str[end + 1].emplace_back(s.substr(idx, end - idx + 1));
						}
						// if idx!=0; add all previous possible break ways into current dp_str[end+1];
						else {
							for (auto & ele : dp_str[idx]) {
								dp_str[end + 1].emplace_back(ele + " " + s.substr(idx, end - idx + 1));
							}
						}
					}
				}
			}
		}
		return dp_str.back();
	}
};


// solution2: dp (top-down and down-top way);
// similar to solution1 but get the dp first, then get all break ways from the dp recorded;
// store all idx of privious possible words in dp;
// dp[i][j]==idx; then wordDict[idx] and be ended with the substr [0,i];
class Solution {
	std::vector<string> result;
public:
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		// transfer into a set to find substring for convinience;
		std::unordered_map<string, int> str2idx;
		for (int idx = 0; idx < wordDict.size(); ++idx) {
			str2idx[wordDict[idx]] = idx;
		}
		// dp[i+1] indicates whether string in range [0,i] can be valid a wordBreak;
		std::vector<std::vector<int>> dp(s.size() + 1, std::vector<int>());

		dp[0].emplace_back(-1);
		for (int end = 0; end < s.size(); ++end) {
			for (int idx = end; idx >= 0; --idx) {
				// range s[0,idx-1] must also be valid, then to check the existence of range [idx,end] in dict;
				if (!dp[idx].empty()) {
					auto found = str2idx.find(s.substr(idx, end - idx + 1));
					if (found == str2idx.end()) {
						continue;
					}
					else {
						dp[end + 1].emplace_back(found->second);
					}
				}
			}
		}
		string cur_result;
		int cur_pos = s.size() - 1;
		collect_result(s, cur_result, cur_pos, dp, wordDict);
		return result;
	}
	void collect_result(const string & s, string & cur_result, int cur_pos, std::vector<std::vector<int>>& dp, std::vector<string>& str2idx) {
		if (cur_pos == -1) {
			result.emplace_back(cur_result);
			return;
		}
		if (dp[cur_pos + 1].empty()) {
			return;
		}
		// if current pos is not the end; then plus " " and the word;
		if (s.size() - 1 != cur_pos) {
			for (auto & pre_str_idx : dp[cur_pos + 1]) {
				string temp = cur_result;
				cur_result = str2idx[pre_str_idx] + " " + cur_result;
				//get the privious pos with  cur_pos - str2idx[pre_str_idx].size();
				collect_result(s, cur_result, cur_pos - str2idx[pre_str_idx].size(), dp, str2idx);
				cur_result = temp;
			}
		}
		// if current pos is the end; then don' t add " ";
		else {
			for (auto & pre_str_idx : dp[cur_pos + 1]) {
				string temp = cur_result;
				cur_result = str2idx[pre_str_idx];
				collect_result(s, cur_result, cur_pos - str2idx[pre_str_idx].size(), dp, str2idx);
				cur_result = temp;
			}
		}
	}
};

int main() {
	//string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	//std::vector<string> word_dic{ "a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa" };
	string s = "pineapplepenapple";
	std::vector<string> word_dic{ "apple", "pen", "applepen", "pine", "pineapple" };
	auto ans = Solution().wordBreak(s, word_dic);


	cin.get();
	return 0;
}