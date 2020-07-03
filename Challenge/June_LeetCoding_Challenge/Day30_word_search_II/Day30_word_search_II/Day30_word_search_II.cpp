#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>

using namespace std;

//class Solution {
//	std::unordered_set<string> m_result;
//	std::vector<std::vector<std::vector<int>>> m_pos2char2idx;
//	std::vector<string>m_all_words;
//	std::vector<std::vector<char>> m_board;
//	int m_row_size = 0;
//	int m_col_size = 0;
//public:
//	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
//		auto max_ = max_element(words.begin(), words.end(), [](const string & rhs1, const string & rhs2)
//		{return rhs1.size() < rhs2.size(); })->size();
//		m_pos2char2idx.resize(max_, std::vector<std::vector<int>>(26, std::vector<int>()));
//		for (int idx = 0; idx<words.size(); ++idx) {
//			for (int pos = 0; pos < words[idx].size(); ++pos) {
//				m_pos2char2idx[pos][words[idx][pos] - 'a'].emplace_back(idx);
//			}
//		}
//		m_row_size = board.size();
//		m_col_size = board.front().size();
//		std::vector<int> word_idx(words.size(), 0);
//		for (int idx = 0; idx < word_idx.size(); ++idx) { word_idx[idx] = idx; }
//		m_all_words = words;
//		m_board = board;
//		//std::vector<std::vector<std::vector<int>>> dp[find]
//		for (int row = 0; row < m_row_size; ++row) {
//			for (int col = 0; col < m_col_size; ++col) {
//				//dfs()
//				search_words(row, col, 0, word_idx);
//			}
//		}
//		std::vector<string> final_result;
//		for (auto & ele : m_result) {
//			final_result.emplace_back(ele);
//		}
//		return final_result;
//	}
//	void search_words(int row, int col, int cur_pos, std::vector<int>  words_idx) {
//		if (row < 0 || row >= m_row_size || col < 0 || col >= m_col_size||words_idx.empty()) {
//			return ;
//		}
//		std::vector<int> next_word_idx;
//		for (int idx = 0; idx < words_idx.size(); ++idx) {
//			if (m_all_words[words_idx[idx]][cur_pos] == m_board[row][col]) {
//				if(cur_pos==m_all_words[words_idx[idx]].size()-1){
//					if (m_result.find(m_all_words[words_idx[idx]]) == m_result.end()) {
//						m_result.emplace(m_all_words[words_idx[idx]]);
//					}
//				}
//				else {
//					if (m_result.find(m_all_words[words_idx[idx]]) == m_result.end()) {
//						next_word_idx.emplace_back(words_idx[idx]);
//					}
//				}
//			}
//		}
//		if (next_word_idx.empty()) { return; }
//		search_words(row + 1, col, cur_pos+1, next_word_idx);
//		search_words(row - 1, col, cur_pos+1, next_word_idx);
//		search_words(row, col+1, cur_pos + 1, next_word_idx);
//		search_words(row , col-1, cur_pos + 1, next_word_idx);
//	}
//};

class TrieNode {
public:
	bool is_end;
	vector<TrieNode*> children;
	TrieNode() {
		is_end = false;
		children = vector<TrieNode*>(26, NULL);
	}
};

class Trie {
public:
	TrieNode* getRoot() { return root; }
	Trie(vector<string>& words) {
		root = new TrieNode();
		for (int i = 0; i<words.size(); ++i)
			addWord(words[i]);
	}
	void addWord(const string& word) {
		TrieNode* cur = root;
		for (int i = 0; i<word.size(); ++i) {
			int index = word[i] - 'a';
			if (cur->children[index] == NULL)
				cur->children[index] = new TrieNode();
			cur = cur->children[index];
		}
		cur->is_end = true;
	}
private:
	TrieNode* root;
};

class Solution {
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		Trie* trie = new Trie(words);
		TrieNode* root = trie->getRoot();
		unordered_set<string> result_set;
		for (int x = 0; x<board.size(); ++x)
			for (int y = 0; y<board[0].size(); ++y)
				findWords(board, x, y, root, "", result_set);

		vector<string> result;
		for (auto it : result_set)    result.push_back(it);
		return result;
	}
private:
	void findWords(vector<vector<char>>& board, int x, int y, TrieNode* root, string word, unordered_set<string>& result) {
		if (x<0 || x >= board.size() || y<0 || y >= board[0].size() || board[x][y] == ' ') return;

		if (root->children[board[x][y] - 'a'] != NULL) {
			word = word + board[x][y];
			root = root->children[board[x][y] - 'a'];
			if (root->is_end) result.insert(word);
			char c = board[x][y];
			board[x][y] = ' ';
			findWords(board, x + 1, y, root, word, result);
			findWords(board, x - 1, y, root, word, result);
			findWords(board, x, y + 1, root, word, result);
			findWords(board, x, y - 1, root, word, result);
			board[x][y] = c;
		}
	}
};

int main() {
	std::vector<std::vector<char>> board= {
		{'o', 'a', 'a', 'n'},
			{'e', 't', 'a', 'e'},
			{'i', 'h', 'k', 'r'},
			{'i', 'f', 'l', 'v'}
	};
	std::vector<string> word = { "oath","pea","eat","rain" };
	auto ans = Solution().findWords(board, word);
	for (auto & ele : ans) {
		std::cout << ele << "  ";
	}
	cin.get();
	return 0;
}