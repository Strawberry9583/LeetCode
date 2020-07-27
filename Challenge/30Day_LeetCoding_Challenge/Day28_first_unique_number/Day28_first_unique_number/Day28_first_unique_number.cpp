#include<vector>
#include<iostream>
#include<algorithm>
#include<list>
#include<map>
#include<queue>
#include<unordered_map>
#include<iterator>
using namespace std;

//link list to store;
//map (unordered_map) to judge whether occurred & occurrance time;
class FirstUnique_1 {
private:
	//store the num;
	std::list<int> m_data;
	//check whether exist;
	std::map<int, std::pair<int,std::list<int>::iterator>> m_map;
public:
	FirstUnique_1(vector<int> & nums) {
		for (auto & ele : nums) {
			auto  find_ele = m_map.find(ele);
			if (find_ele == m_map.end()) {
				m_data.emplace_back(ele);
				m_map.emplace(ele,std::make_pair(1,--m_data.end()));
			}
			else {
				if (find_ele->second.first == 1) {
					m_data.erase(find_ele->second.second);
				}
				++m_map[ele].first;
			}
		}
	}

	int showFirstUnique() {
		if (m_data.empty()) {
			return -1;
		}
		else {
			return *m_data.begin();
		}
	}

	void add(int value) {
		auto  find_ele = m_map.find(value);
		if (find_ele == m_map.end()) {
			m_data.emplace_back(value);
			m_map.emplace(value, std::make_pair(1, --m_data.end()));
		}
		else {
			if (find_ele->second.first == 1) {
				m_data.erase(find_ele->second.second);

				//++find_ele->second.first;
			}
			++m_map[value].first;
		}
	}
};

class FirstUnique {
	unordered_map<int, int> cnt;
	queue<int> q;
public:
	FirstUnique(vector<int>& nums) {
		for (int i : nums)
			++cnt[i];
		for (int i : nums)
			if (cnt[i] == 1)
				q.push(i);
	}

	int showFirstUnique() {
		return q.size() ? q.front() : -1;
	}

	void add(int value) {
		int x = ++cnt[value];
		if (x == 1)
			q.push(value);
		else while (q.size() && cnt[q.front()] > 1)
			q.pop();
	}
};

int main() {
	//std::vector<int> li{ 1,2,3 };
	//auto end_1 = li.end();
	//for (int i = 0; i < 100; ++i) {
	//	li.emplace_back(i);
	//	std::cout << (end_1 == li.end()) << std::endl;
	//}
	std::cin.get();
	FirstUnique firstUnique(std::vector<int>{ 7, 7, 7, 7, 7, 7 });
	std::cout<<firstUnique.showFirstUnique(); // return -1
	firstUnique.add(7);            // the queue is now [7,7,7,7,7,7,7]
	firstUnique.add(3);            // the queue is now [7,7,7,7,7,7,7,3]
	firstUnique.add(3);            // the queue is now [7,7,7,7,7,7,7,3,3]
	firstUnique.add(7);            // the queue is now [7,7,7,7,7,7,7,3,3,7]
	firstUnique.add(17);           // the queue is now [7,7,7,7,7,7,7,3,3,7,17]
	std::cout << firstUnique.showFirstUnique(); // return 17
	std::cin.get();
	return 0;

}