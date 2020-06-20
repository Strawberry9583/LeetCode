#include<iostream>
#include<vector>
#include<unordered_map>
#include<random>
#include<unordered_set>
using namespace std;

// solution1
class RandomizedSet1 {
private:
	// store the ele and its iterator;
	std::unordered_map<int, std::vector<int>::iterator> m_int2ite;
	int m_size;
	std::vector<int> m_data;
	std::default_random_engine m_engine;
public:
	// caution: allocate the m_data at first, or the iterator may be invalid when the vector grows;
	RandomizedSet1():m_size(0),m_data(1000000,0),m_engine(0) {
		
	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		auto find = m_int2ite.find(val);
		if (find == m_int2ite.end()) {
			m_data[m_size] = val;
			m_int2ite[val] = m_data.begin()+m_size;
			++m_size;
			return true;
		}
		else {
			return false;
		}
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		auto find = m_int2ite.find(val);
		//if then back one is the erased one, then erase directly;
		if (find == m_int2ite.end()) {
			return false;
		}
		// or move the back one to the removed ele's position;
		else {
			int back = m_data[m_size - 1];
			if (back == val) {
				m_int2ite.erase(val);
			}
			else {
				auto ite_temp = find->second;
				*m_int2ite[val] = back;
				m_int2ite.erase(val);
				m_int2ite[back] = ite_temp;
			}
			--m_size;
			return true;
		}
	}

	/** Get a random element from the set. */
	int getRandom() {
		std::uniform_int_distribution<int> uni_dir(0,m_size-1);
		int rand = uni_dir(m_engine);
		return m_data[rand];
	}
};


class RandomizedSet {
public:
	/** Initialize your data structure here. */
	RandomizedSet() {

	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		if (m.find(val) != m.end()) return false;
		nums.emplace_back(val);
		m[val] = nums.size() - 1;
		return true;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		if (m.find(val) == m.end()) return false;
		int last = nums.back();
		m[last] = m[val];
		nums[m[val]] = last;
		nums.pop_back();
		m.erase(val);
		return true;
	}

	/** Get a random element from the set. */
	int getRandom() {
		return nums[rand() % nums.size()];
	}
private:
	vector<int> nums;
	unordered_map<int, int> m;
};


// follow up: the set may contain duplicates;
// with duplicates, then use unordered_set to store all the idx of val;
class RandomizedCollection {
private:
	std::unordered_map<int, std::unordered_set<int>> m_idx2val;
	std::vector<int> m_data;

public:
	/** Initialize your data structure here. */
	RandomizedCollection() {

	}

	/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
	bool insert(int val) {
		m_idx2val[val].emplace(m_data.size());
		m_data.emplace_back(val);
		return m_idx2val[val].size() == 1;
		//auto find_ele = m_idx2val.find(val);
		//if (find_ele == m_idx2val.end()) {

		//	return true;
		//}
		//else {
		//	find_ele->second.emplace_back(m_data.size());
		//	m_data.emplace_back(val);
		//	return false;
		//}
	}

	/** Removes a value from the collection. Returns true if the collection contained the specified element. */
	bool remove(int val) {
		auto find_ele = m_idx2val.find(val);
		if (find_ele == m_idx2val.end()) {
			return false;
		}
		else {
			int free_pos = *find_ele->second.begin();
			find_ele->second.erase(free_pos);
			// move the back_ele to the erased idx;
			m_data[free_pos] = m_data.back();
			int back_pos = m_data.size()-1;
			// add the new idx remove the old idx;
			// first emplace, then erase; 
			// or the case free_pos==back_pos will get wrong solution;
			m_idx2val[m_data.back()].emplace(free_pos);
			m_idx2val[m_data.back()].erase(back_pos);
			//if (free_pos == back_pos) {
			//	m_idx2val[m_data.back()].erase(back_pos);
			//}
			//else {
			//	m_idx2val[m_data.back()].erase(back_pos);
			//	m_idx2val[m_data.back()].emplace(free_pos);

			//}
			m_data.pop_back();
			if (find_ele->second.empty()) {
				m_idx2val.erase(val);
			}
			return true;
		}
	}

	/** Get a random element from the collection. */
	int getRandom() {
		return m_data[rand() % m_data.size()];
	}
};


int main() {
	// Init an empty set.
	RandomizedCollection randomSet;

	// Inserts 1 to the set. Returns true as 1 was inserted successfully.
	randomSet.insert(2);
	randomSet.insert(3);

	randomSet.insert(4);
	randomSet.insert(4);
	randomSet.insert(4);

	randomSet.remove(4);
	randomSet.remove(3);
	randomSet.remove(4);
	randomSet.remove(4);



	// Returns false as 2 does not exist in the set.
	randomSet.remove(1);
	randomSet.remove(1);
	randomSet.remove(1);
	randomSet.remove(3);

	// Inserts 2 to the set, returns true. Set now contains [1,2].
	randomSet.insert(2);

	// getRandom should return either 1 or 2 randomly.
	randomSet.getRandom();

	// Removes 1 from the set, returns true. Set now contains [2].
	randomSet.remove(1);

	// 2 was already in the set, so return false.
	randomSet.insert(2);

	// Since 2 is the only number in the set, getRandom always return 2.
	randomSet.getRandom();
	cin.get();
	return 0;
}