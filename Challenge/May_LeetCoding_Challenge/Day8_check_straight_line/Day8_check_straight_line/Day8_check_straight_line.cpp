#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
	bool checkStraightLine(vector<vector<int>>& coordinates) {
		float delta_y = coordinates[0][1] - coordinates[1][1];
		float delta_x = coordinates[0][0] - coordinates[1][0];
		float delta = 0.f;
		bool if_upright = false;
		if (coordinates[0][0] == coordinates[1][0]) {
			if_upright = true;
		}
		else {
			delta = delta_y / delta_x;
		}
		for (int i = 2; i < coordinates.size(); ++i) {
			if (if_upright) {
				if (coordinates[0][0] != coordinates[i][0]) {
					return false;
				}
				else {
					continue;
				}
			}
			else {
				delta_y = coordinates[i][1] - coordinates[1][1];
				delta_x = coordinates[i][0] - coordinates[1][0];
				if (delta_x != 0.f&&delta == (delta_y / delta_x)) {
					continue;
				}
				else {
					return false;
				}
			}
		}
		return true;
	}
};

int main() {

	std::cin.get();
	return 0;
}