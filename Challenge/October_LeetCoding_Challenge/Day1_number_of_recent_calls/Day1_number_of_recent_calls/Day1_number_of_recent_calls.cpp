#include<iostream>
#include<vector>
#include<deque>
#include<list>
using namespace std;


class RecentCounter {
	std::list<int> m_data;
public:
	RecentCounter() {

	}

	int ping(int t) {
		while (t-m_data.front()>3000) {
			m_data.pop_front();
		}
		m_data.emplace_back(t);
		return m_data.size();
	}
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

int main() {
	cin.get();
	return 0;
}