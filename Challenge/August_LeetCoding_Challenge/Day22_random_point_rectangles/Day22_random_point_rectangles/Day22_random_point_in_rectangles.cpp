#include<vector>
#include<map>
#include<iostream>
#include<unordered_map>
#include<functional>
#include<random>
#include<algorithm>

using namespace std;

//template<>struct hash<pair<int,int>> {
//	size_t operator()(const pair<int,int> & rhs)const {
//		return hash<int>()(rhs.first)^(hash<int>()(rhs.second)<<1);
//	}
//};

class Solution {
	vector<vector<int>> recs;
	vector<int> areas;
	int total;
public:
	Solution(vector<vector<int>>& rects) {
		// srand((unsigned) time(NULL));    
		recs = rects;
		int size = rects.size();
		total = 0;
		for (int i = 0; i < size; ++i) {
			vector<int>& r = rects[i];
			int x = abs(r[2] - r[0]) + 1;
			int y = abs(r[3] - r[1]) + 1;
			areas.push_back(x*y);
			total += x * y;
		}
		// cout <<"total="<<total << endl;
	}

	vector<int> pick() {
		int p = rand() % total;
		// cout << "p=" << p;
		int i = 0;
		while (i < recs.size() && p >= areas[i]) {
			p -= areas[i];
			++i;
		}
		// cout << "\t\ti=" << i << ",\tp="<<p << endl;
		vector<int>& r = recs[i];
		int x = abs(r[2] - r[0]) + 1;
		int y = abs(r[3] - r[1]) + 1;
		int x0 = r[0] + p / y;
		int y0 = r[1] + p % y;
		return { x0, y0 };
	}
};
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */

int main() {
	std::vector<std::vector<int>> rects{ {35330199,-46858448,35330694,-46856950} };
	Solution sol(rects);
	cin.get();
	return 0;
}