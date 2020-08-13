#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class CombinationIterator {
private:
	int m_max_num;
	int m_length;
	std::vector<int> m_all_idx;
	string m_char;
public:
	CombinationIterator(string characters, int combinationLength): m_max_num(characters.size()),m_length(combinationLength),m_char(characters){
		m_all_idx.resize(combinationLength, 0);
		for (int idx = 0; idx < combinationLength; ++idx) {
			m_all_idx[idx] = idx;
		}
		--m_all_idx.back();
	}

	string next() {

		++m_all_idx.back();
		if (m_all_idx.back() == m_max_num) {
			int idx = m_all_idx.size() - 2;
			for (; idx >= 0; --idx) {
				++m_all_idx[idx];
				if (m_all_idx[idx] + m_length - idx - 1 >= m_max_num) {
					continue;
				}
				else {
					break;
				}
			}
			for (int update_idx = idx + 1; update_idx < m_all_idx.size(); ++update_idx) {
				m_all_idx[update_idx] = m_all_idx[update_idx-1] + 1;
			}
		}
		string result(m_length,' ');
		for (int idx = 0; idx < m_length; ++idx) {
			result[idx] = m_char[m_all_idx[idx]];
		}
		return result;
	}

	bool hasNext() {
		if ((m_all_idx.back() == m_max_num - 1)&&(m_all_idx.front()==m_max_num-m_length)) {
			return false;
		}
		else {
			return true;
		}
	}
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main() {
	string test = "abc";
	int length = 2;
	auto temp = CombinationIterator(test, length);
	std::cout << temp.hasNext();
	std::cout << temp.next();
	cin.get();
	return 0;
}