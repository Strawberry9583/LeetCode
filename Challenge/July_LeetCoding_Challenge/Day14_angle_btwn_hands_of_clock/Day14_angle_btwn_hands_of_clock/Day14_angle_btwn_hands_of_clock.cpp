#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

class Solution {
public:
	double angleClock(int hour, int minutes) {
		double hour_angle=hour% 12;
		hour_angle += (double)minutes / 60.0;
		hour_angle = (hour_angle / 12)*360.0;
		double minutes_angle = ((double)minutes / 60.0)*360.0;
		return minutes_angle > hour_angle?minutes_angle-hour_angle:hour_angle-minutes_angle;
	}
};

int main() {
	std::cout << Solution().angleClock(1, 57);
	cin.get();
	return 0;
}