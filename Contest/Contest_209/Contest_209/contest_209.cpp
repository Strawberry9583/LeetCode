#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>
#include<cmath>

using namespace std;

class Solution {
public:
	int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
		float pi = 4 * atan(1.0);
		std::vector<float> all_angles;
		int equal_num = 0;
		for (int idx = 0; idx < points.size(); ++idx) {
			if (points[idx][0] == location[0] && points[idx][1] == location[1]) {
				++equal_num;
				continue;
			}
			float base_x =1.f, base_y = 0.f;
			float p_x = points[idx][0] - location[0], p_y = points[idx][1] - location[1];
			float cos_angle = (base_x*p_x) / std::sqrt(p_x*p_x + p_y*p_y);
			float angle = 180*std::acos(cos_angle)/pi;
			if (points[idx][1] >= location[1]) {
				all_angles.emplace_back(angle);
			}
			else {
				all_angles.emplace_back(360 - angle);
			}
		}
		std::sort(all_angles.begin(), all_angles.end());
		return max_point_num(all_angles, angle)+equal_num;
	}
private:
	int max_point_num(std::vector<float>& all_angles, float angle) {
		if (all_angles.empty()) {
			return 0;
		}
		int max_num = -1;
		for (int idx = 0; idx < all_angles.size(); ++idx) {
			float start_angle = all_angles[idx];
			float end_angle = start_angle + angle+10e-5;
			int cur_num = 0;
			if (end_angle > 360) {
				cur_num += all_angles.size() - idx;
				end_angle -= 360;
				auto last_le = std::upper_bound(all_angles.begin(), all_angles.begin() + idx, end_angle);
				cur_num += last_le - all_angles.begin();
			}
			else {
				auto last_le = std::upper_bound(all_angles.begin() + idx, all_angles.end(), end_angle);
				cur_num += last_le - (all_angles.begin() + idx);
			}
			if (cur_num > max_num) {
				max_num = cur_num;
				if (max_num == all_angles.size()) {
					break;
				}
			}
		}
		return max_num;
	}
};


int main() {
	std::vector<std::vector<int>> points{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {1, 2}, {2, 1}};
	int angle = 0;
	std::vector<int> location = { 1, 1 };
	std::cout << Solution().visiblePoints(points, angle, location);
	cin.get();
	return 0;
}