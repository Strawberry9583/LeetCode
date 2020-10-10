#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
// First, we sort balloons by increasing points.end(if ends are the same, then by increasing of points.start).
// Every time arrow shot points.end, say, points[i].second.If next balloon.start <= points[i].second, it is also shot, thus we continue.
class Solution {
public:
	int findMinArrowShots(vector<vector<int>>& points) {
		if (points.empty()) {
			return 0;
		}
		if (points.size() == 1) {
			return 1;
		}
		std::sort(points.begin(), points.end(),
			[](const std::vector<int>& rhs1, const std::vector<int>& rhs2) {return rhs1[1] != rhs2[1] ? rhs1[1] < rhs2[1] : rhs1[0] < rhs2[0]; });
		int result = 1;
		int shoot_point = points[0][1];
		for (int idx = 1; idx < points.size(); ++idx) {
			if (shoot_point >= points[idx][0]) {
				continue;
			}
			else {
				shoot_point = points[idx][1];
				++result;
			}
		}
		return result;
	}
};

int main() {
	std::vector<std::vector<int>> vec{{1, 2}, {3, 4}, {5, 6}, {7, 8}};
	std::cout << Solution().findMinArrowShots(vec);
	cin.get();
	return 0;
}