#include<iostream>
#include<vector>

using namespace std;

// method: trie with dfs
// use trie to store words;
// use dfs to search the words with ".";
class WordDictionary {
	struct node {
	public:

		int m_char;
		int m_is_end;
		std::vector<node*> m_next;
		
		node(char c) :m_char(c), m_is_end(false), m_next(26, nullptr) {}
	};
private:
	node m_trie;

	bool is_word(node * root, int idx, const string & word) {
		if (root == nullptr) {
			return false;
		}
		if (idx == word.size()) {
			return root->m_is_end;
		}
		if (word[idx] == '.') {
			bool flag = false;
			for (int seq = 0; seq < 26; ++seq) {
				if (root->m_next[seq] == nullptr) {
					continue;
				}
				else if(is_word(root->m_next[seq],idx+1,word)) {
					flag = true;
					break;
				}
				else {
					continue;
				}
			}
			return flag;
		}
		else {
			return is_word(root->m_next[word[idx] - 'a'], idx + 1, word);
		}

	}
public:

	/** Initialize your data structure here. */
	WordDictionary():m_trie('#') {
		
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		if (word.empty()) {
			return;
		}
		node * root = &m_trie;
		for (int idx = 0; idx < word.size(); ++idx) {
			if (root->m_next[word[idx] - 'a'] == nullptr) {
				root->m_next[word[idx] - 'a'] = new node(word[idx]);
			}
			root = root->m_next[word[idx] - 'a'];
		}
		root->m_is_end = true;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		node* root = &m_trie;
		return is_word(root, 0, word);
	}
};


int main() {
	WordDictionary dic;
	dic.addWord("");
	//dic.addWord("mad");
	//dic.addWord("bad");
	//std::cout << dic.search("pad") << std::endl;
	//std::cout << dic.search("bad") << std::endl;
	//std::cout << dic.search(".ad") << std::endl;
	std::cout << dic.search("a") << std::endl;
	cin.get();
	return 0;
}