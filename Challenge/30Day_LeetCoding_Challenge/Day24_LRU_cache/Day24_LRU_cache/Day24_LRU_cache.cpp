#include<iostream>
#include<queue>
#include<list>
#include<unordered_map>

using namespace std;

//use map to record the iterator of key,value pair;
//every time put or update the pair, move the pair to the beginning and remove the redundency;
class LRUCache1 {
public:
	LRUCache1(int capacity):m_size(0),m_capacity(capacity) {
		
	}

	int get(int key) {
		auto find_ele = m_map.find(key);
		if (find_ele == m_map.end()) {
			return -1;
		}
		else {
			//erase the existing and cnst one in the beginning;
			m_list.emplace_front(*find_ele->second);
			m_list.erase(find_ele->second);
			m_map[key] = m_list.begin();
			return m_map[key]->second;
		}
	}

	void put(int key, int value) {
		auto find_ele = m_map.find(key);
		if (find_ele == m_map.end()) {
			//cntr new pair;
			m_list.emplace_front(std::pair<int, int>(key, value));
			m_map[key] = m_list.begin();
			++m_size;
			if (m_size > m_capacity) {
				m_map.erase(m_list.rbegin()->first);
				m_list.pop_back();
				--m_size;
			}
		}
		else {
			//cntr new pair and remove the existing one;
			m_list.emplace_front(std::pair<int, int>(key, value));
			m_list.erase(find_ele->second);
			m_map[key] = m_list.begin();
		}
	}
private:
	int m_size;
	int m_capacity;
	std::list<std::pair<int,int>> m_list;
	std::unordered_map<int, std::list<std::pair<int,int>>::iterator>m_map;
};

class LRUCache {
public:
	LRUCache(int capacity) :m_size(0), m_capacity(capacity) {

	}

	int get(int key) {
		auto find_ele = m_map.find(key);
		if (find_ele == m_map.end()) {
			return -1;
		}
		else {
			//move the exisiting one to the beginning;
			m_list.splice(m_list.begin(), m_list, find_ele->second);
			//m_list.emplace_front(*find_ele->second);
			//m_list.erase(find_ele->second);
			//m_map[key] = m_list.begin();
			return m_map[key]->second;
		}
	}

	void put(int key, int value) {
		auto find_ele = m_map.find(key);
		if (find_ele == m_map.end()) {
			//cntr new pair;
			m_list.emplace_front(std::pair<int, int>(key, value));
			m_map[key] = m_list.begin();
			++m_size;
			if (m_size > m_capacity) {
				m_map.erase(m_list.rbegin()->first);
				m_list.pop_back();
				--m_size;
			}
		}
		else {
			//update value and move the existing one to the beginning;
			find_ele->second->second = value;
			m_list.splice(m_list.begin(), m_list, find_ele->second);
			//m_list.emplace_front(std::pair<int, int>(key, value));
			//m_list.erase(find_ele->second);
			//m_map[key] = m_list.begin();
		}
	}
private:
	int m_size;
	int m_capacity;
	std::list<std::pair<int, int>> m_list;
	std::unordered_map<int, std::list<std::pair<int, int>>::iterator>m_map;
};

int main() {

	std::cin.get();
	return 0;
}