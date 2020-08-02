#include<iostream>
#include<vector>
#include<bitset>

using namespace std;


class MyHashSet {
	std::bitset<1000001> m_flag;

public:
	/** Initialize your data structure here. */
	MyHashSet() {

	}

	void add(int key) {
		m_flag[key] = true;
	}

	void remove(int key) {
		m_flag[key] = false;
	}

	/** Returns true if this set contains the specified element */
	bool contains(int key) {
		return m_flag[key];
	}
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */



int main() {
	MyHashSet has;

	cin.get();
	return 0;
}