#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<deque>
#include<queue>

using namespace std;

// solutin1: dfs (TLE)
// time complexity: 
class Solution1 {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		for (int idx = 0; idx < wordDict.size(); ++idx) {
			if (s[0] == wordDict[idx][0]) {
				if (dfs(1, idx, 1, s, wordDict)) {
					return true;
				}
				
			}
		}
		return false;
	}
	bool dfs(int s_cur_idx, int word_idx, int word_char_idx, string s, std::vector<string> & wordDict) {
		if (s_cur_idx == s.size()&&word_char_idx==wordDict[word_idx].size()) {
			return true;
		}
		else if(word_char_idx<wordDict[word_idx].size()&& s[s_cur_idx] == wordDict[word_idx][word_char_idx]){
			return dfs(s_cur_idx + 1, word_idx, word_char_idx + 1, s, wordDict);
		}
		else if (word_char_idx == wordDict[word_idx].size()) {
			for (int idx = 0; idx < wordDict.size(); ++idx) {
				if (s[s_cur_idx] == wordDict[idx][0]) {
					if (dfs(s_cur_idx+1, idx, 1, s, wordDict)) {
						return true;
					}
				}
			}
			return false;
		}
		else {
			return false;
		}
	}
};


// solution2: dp (top-down thinking way);
// dp[i] indicates whether string in range [0,i] can be valid a wordBreak;
class Solution2 {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		// transfer into a set to find substring for convinience;
		std::unordered_set<string> dict;
		for (auto & ele : wordDict) {
			dict.emplace(std::move(ele));
		}
		// dp[i+1] indicates whether string in range [0,i] can be valid a wordBreak;
		std::deque<bool> dp(s.size() + 1, false);
		dp[0] = true;
		for (int end = 0; end < s.size(); ++end) {
			for (int idx = end; idx >= 0; --idx) {
				// range s[0,idx-1] must also be valid, then to check the existence of range [idx,end] in dict;
				if (dp[idx]) {
					if (dict.find(s.substr(idx, end - idx+1)) == dict.end()) {
						continue;
					}
					// if true then break;
					else {
						
						dp[end + 1] = true;
						break;
					}
				}
			}
		}
		return dp.back();
	}
};



// solution3: dp (down-top thinking way);
// dp[i] indicates whether string in range [0,i] can be valid a wordBreak;
class Solution3 {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		// transfer into a set to find substring for convinience;
		std::unordered_set<string> dict;
		for (auto & ele : wordDict) {
			dict.emplace(std::move(ele));
		}
		// dp[i+1] indicates whether string in range [0,i] can be valid a wordBreak;
		std::deque<bool> dp(s.size() + 1, false);
		dp[0] = true;
		for (int start = 0; start < s.size(); ++start) {
			//if range [0,start-1] can be valid, then the [0,start-1] plus any words can be valid;
			if (dp[start]) {
				for (int idx = start; idx < s.size();++idx) {
					if (dict.find(s.substr(start, idx - start + 1)) == dict.end()) {
						continue;
					}
					else {
						dp[idx + 1] = true;
					}
				}
			}
		}
		return dp.back();
	}
};



// solution4: dp with Trie (down-top thinking way);
// dp[i] indicates whether string in range [0,i] can be valid a wordBreak;

// the implementation of Trie;
struct TreeNode {
public:
	bool m_is_end;
	std::vector<TreeNode*> m_nexts;
	char m_cur;
public:
	TreeNode() :m_is_end(false), m_cur('#'), m_nexts(26, nullptr) {}
	TreeNode(char c) :m_is_end(false), m_cur(c), m_nexts(26, nullptr) {}
};
struct Trie {
public:
	TreeNode* m_root;
private:
	void add_word_(const string & word, TreeNode * cur_node, int cur_idx) {
		if (cur_idx == word.size()) {
			cur_node->m_is_end = true;
		}
		else {
			if (cur_node->m_nexts[word[cur_idx] - 'a'] == nullptr) {
				cur_node->m_nexts[word[cur_idx] - 'a'] = new TreeNode(word[cur_idx]);
			}
			add_word_(word, cur_node->m_nexts[word[cur_idx] - 'a'], cur_idx + 1);
		}
	}
public:
	Trie() :m_root(new TreeNode()) {}
	void add_word(const string & word) {
		if (word.empty()) {
			return;
		}
		add_word_(word, m_root, 0);
	}
};

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		// transfer into word vector into a Trie;
		Trie word_tree;
		for (auto & word : wordDict) {
			word_tree.add_word(word);
		}
		// dp[i+1] indicates whether string in range [0,i] can be valid a wordBreak;
		std::deque<bool> dp(s.size() + 1, false);
		dp[0] = true;
		for (int start = 0; start < s.size(); ++start) {
			TreeNode * cur = word_tree.m_root;
			if (dp[start]) {
				for (int idx = start; idx < s.size(); ++idx) {
					//from this case on, all dp should be false, so break directly;
					if (cur->m_nexts[s[idx]-'a']==nullptr) {
						break;
					}
					else {
						cur = cur->m_nexts[s[idx] - 'a'];
						if (cur->m_is_end) {
							dp[idx + 1] = true;
						}
					}
				}
			}
		}
		return dp.back();
	}
};

int main() {
	string test = "catsanddog";
	std::vector<string> words{ "cats", "dog", "sand", "and", "cat"};
	std::cout << Solution().wordBreak(test, words);
	cin.get();
	return 0;
}