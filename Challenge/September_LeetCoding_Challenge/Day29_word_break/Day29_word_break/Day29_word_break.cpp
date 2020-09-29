#include<iostream>
#include<deque>
#include<vector>
#include<string>
#include<unordered_set>
#include<unordered_map>
using namespace std;

// solution1: dfs + Trie
// time complexity: O(2^N); N is the size of string;
class Trie {
	struct node {
	public:
		bool m_end;
		std::vector<node*> m_next;
		node() :m_end(false), m_next(26, nullptr) {}
	};
public:
	node * m_root;
	Trie():m_root(new node()) {}
	void add_word(const string & str) {
		auto cur_node = m_root;
		for (int idx = 0; idx < str.size(); ++idx) {
			if (cur_node->m_next[str[idx] - 'a'] == nullptr) {
				cur_node->m_next[str[idx] - 'a'] = new node();
			}
			cur_node = cur_node->m_next[str[idx] - 'a'];
		}
		cur_node->m_end = true;
	}
	bool if_exist(const string & str) {
		return dfs(str, 0, m_root);
	}
private:
	bool dfs(const string & str, int cur_idx, node* root) {
		if (str.size()==cur_idx) {
			if (root == nullptr) {
				return false;
			}
			else {
				return root->m_end;
			}
		}
		if (root == nullptr) {
			return false;
		}
		else {
			if (root->m_end) {
				return dfs(str, cur_idx+1 , root->m_next[str[cur_idx] - 'a'])
					|| dfs(str, cur_idx, m_root);
			}
			else {
				return dfs(str, cur_idx + 1, root->m_next[str[cur_idx] - 'a']);
			}
		}
	}
};

class Solution1 {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		Trie tree;
		for (auto & ele : wordDict) {
			tree.add_word(ele);
		}
		return tree.if_exist(s);
	}
};

// DP;
// time complexity: O(n^2);
class Solution {
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
					if (dict.find(s.substr(idx, end - idx + 1)) == dict.end()) {
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

int main() {
	std::vector<string> wordDict{ "leet","code" };
	std::string s = "leetcode";
	std::cout << Solution().wordBreak(s, wordDict);
	cin.get();
	return 0;
}