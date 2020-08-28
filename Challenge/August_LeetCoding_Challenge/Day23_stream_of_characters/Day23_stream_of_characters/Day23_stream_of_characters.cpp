#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<deque>
#include<memory>

using namespace std;

// build Trie with reverse search
class Trie {
	struct node {
		std::vector<std::shared_ptr<node>> m_next;
		bool m_end;
		node() :m_next(26, nullptr), m_end(false) {}
	};
private:
	std::shared_ptr<node> m_root;

public:
	Trie() :m_root(std::make_shared<node>()){ }
	void insert_word(const string & word) {
		auto cur = m_root;
		for (int idx = 0; idx < word.size(); ++idx) {
			if (cur->m_next[word[idx] - 'a'] == nullptr) {
				cur->m_next[word[idx] - 'a'] = std::make_shared<node>();
			}
			cur = cur->m_next[word[idx] - 'a'];
		}
		cur->m_end = true;
	}

	bool query_word(const string &word) {
		return find_word(word, m_root, 0);
	}
private:
	bool find_word(const string& word,std::shared_ptr<node> node,int idx) {
		if (node == nullptr) {
			return false;
		}
		if (word.size() == idx) {
			return node->m_end;
		}
		if (node->m_end) {
			return true;
		}
		else {
			return find_word(word, node->m_next[word[idx] - 'a'], idx + 1);
		}
	}
};
//["StreamChecker", "query", "query", "query", "query", "query", "query", "query", "query", "query", "query", "query", "query", "query", "query", "query", "query", "query", "query", "query", "query", "query", "query", "query", "query", "query", "query", "query", "query", "query", "query"]
//[[["ab", "ba", "aaab", "abab", "baa"]], ["a"], ["a"], ["a"], ["a"], ["a"], ["b"], ["a"], ["b"], ["a"], ["b"], ["b"], ["b"], ["a"], ["b"], ["a"], ["b"], ["b"], ["b"], ["b"], ["a"], ["b"], ["a"], ["b"], ["a"], ["a"], ["a"], ["b"], ["a"], ["a"], ["a"]]

class StreamChecker {
	int m_max_length=-1;
	Trie m_tree;
	string m_query_word;
public:
	StreamChecker(vector<string>& words) {
		for (int idx = 0; idx < words.size(); ++idx) {
			// reverse the words to search backward;
			std::reverse(words[idx].begin(), words[idx].end());
			m_tree.insert_word(words[idx]);
			if ((int)words[idx].size() > m_max_length) {
				m_max_length = words[idx].size();
			}
		}
	}

	bool query(char letter) {
		m_query_word = letter+ m_query_word;
		if (m_query_word.size() > m_max_length) {
			m_query_word.pop_back();
		}
		return m_tree.query_word(m_query_word);
	}
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
int main() {
	std::vector<string>test_words = { "ab", "ba", "aaab", "abab", "baa" };
	StreamChecker streamChecker(test_words); // init the dictionary.
	std::cout<<streamChecker.query('a') << std::endl;          // return false
	std::cout << streamChecker.query('b') << std::endl;          // return false
	std::cout << streamChecker.query('c') << std::endl;          // return false
	std::cout << streamChecker.query('d') << std::endl;          // return true, because 'cd' is in the wordlist
	std::cout << streamChecker.query('e') << std::endl;          // return false
	std::cout << streamChecker.query('f') << std::endl;          // return true, because 'f' is in the wordlist
	std::cout << streamChecker.query('g') << std::endl;          // return false
	std::cout << streamChecker.query('h') << std::endl;          // return false
	std::cout << streamChecker.query('i') << std::endl;          // return false
	std::cout << streamChecker.query('j') << std::endl;          // return false
	std::cout << streamChecker.query('k') << std::endl;          // return false
	std::cout << streamChecker.query('l') << std::endl;          // return true, because 'kl' is in the wordlist

	cin.get();
	return 0;
}