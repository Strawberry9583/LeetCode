/*
There are some specific application of Trie.
https://leetcode.com/problems/implement-trie-prefix-tree/solution/
*/

#include<iostream>
#include<vector>
#include<memory>
using namespace std;

class Trie {
	class tree_node {
	public:
		std::vector<std::shared_ptr<tree_node>> m_childrens;
		//char m_val;
		bool m_is_end;
	public:
		tree_node() {
			m_childrens.assign(27, nullptr);
			m_is_end = true;
		}
	};
private:
	std::shared_ptr<tree_node>  m_root;
public:
	/** Initialize your data structure here. */
	Trie():m_root(std::make_shared<tree_node>()) {
		m_root.reset(new tree_node());
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		auto root = m_root;
		for (int idx = 0; idx < word.size(); ++idx) {
			if (root->m_childrens[word[idx] - 'a'] == nullptr) {
				//root->m_childrens[word[idx] - 'a'] = std::make_shared<tree_node>(new tree_node());
				root->m_childrens[word[idx] - 'a'].reset(new tree_node());
				root = root->m_childrens[word[idx] - 'a'];
				if (idx != word.size() - 1) {
					root->m_is_end = false;
				}
			}
			else {
				root = root->m_childrens[word[idx] - 'a'];
				if (idx == word.size() - 1) {
					root->m_is_end = true;
				}
			}
		}
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		auto root = m_root;
		for (int idx = 0; idx < word.size(); ++idx) {
			if (root->m_childrens[word[idx] - 'a'] == nullptr) {
				return false;
			}
			else {
				root = root->m_childrens[word[idx] - 'a'];
			}
		}
		if (root->m_is_end) {
			return true;
		}
		else {
			return false;
		}
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		auto root = m_root;
		for (int idx = 0; idx < prefix.size(); ++idx) {
			if (root->m_childrens[prefix[idx] - 'a'] == nullptr) {
				return false;
			}
			root = root->m_childrens[prefix[idx] - 'a'];
		}
		return true;
	}
};

/**
* Your Trie object will be instantiated and called as such:
* Trie* obj = new Trie();
* obj->insert(word);
* bool param_2 = obj->search(word);
* bool param_3 = obj->startsWith(prefix);
*/

int main() {
	Trie* obj = new Trie();
	obj->insert("apple");
	std::cout << obj->search("apple");
	std::cout << obj->search("app");
	std::cout << obj->startsWith("app");
	obj->insert("app");
	std::cout << obj->search("app");
	cin.get();
	return 0;
}