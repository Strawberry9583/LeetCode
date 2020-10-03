#include<iostream>
#include<vector>
#include<algorithm>
#include<string>


using namespace std;

class Solution {
public:
	bool carPooling(vector<vector<int>>& trips, int capacity) {
		std::vector<int> gap(1001, 0);
		
		for (int idx = 0;idx< trips.size(); ++idx) {

			gap[trips[idx][1]]+=trips[idx][0];
			gap[trips[idx][2]]-=trips[idx][0];
		}
		int cur_size = 0;
		for (int idx = 0; idx < gap.size(); ++idx) {
			cur_size += gap[idx];
			if (cur_size > capacity) {
				return false;
			}
		}
		return true;
	}
};

int main() {
	std::vector<std::vector<int>> trips = {{2,1,5}, {3,5, 7}};
	int capacity = 3;
	std::cout << Solution().carPooling(trips, capacity);

	cin.get();
	return 0;
}