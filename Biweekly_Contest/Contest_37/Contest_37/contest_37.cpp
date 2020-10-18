#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<functional>
#include<algorithm>

using namespace std;

class Solution1 {
public:
	double trimMean(vector<int>& arr) {
		std::sort(arr.begin(), arr.end());
		int begin = arr.size()*(0.05+1e-10);
		double result = 0;
		for (int idx = begin; idx + begin < arr.size(); ++idx) {
			result += arr[idx];
		}
		result /= arr.size() - 2 * begin;
		return result;
	}
};

class Solution2 {
public:
	vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
		int x_min = std::numeric_limits<int>::max(), x_max = std::numeric_limits<int>::lowest();
		int y_min = std::numeric_limits<int>::max(), y_max = std::numeric_limits<int>::lowest();
		for (auto & ele : towers) {
			if (ele[0] < x_min) {
				x_min = ele[0];
			}
			if (ele[0] > x_max) {
				x_max = ele[0];
			}
			if (ele[1] < y_min) {
				y_min = ele[1];
			}
			if (ele[1] > y_max) {
				y_max = ele[1];
			}
		}
		x_min -= radius; x_max += radius;
		y_min -= radius; y_max += radius;
		int result_quality = 0;
		int result_x = 0, result_y = 0;
		for (int x = x_min; x <= x_max; ++x) {
			for (int y = y_min; y <= y_max; ++y) {
				int temp = quality_sum(towers, radius, x, y);
				if (temp > result_quality) {
					result_quality = temp;
					result_x = x;
					result_y = y;
				}
			}
		}
		return std::vector<int>{result_x, result_y};
	}
private:
	int quality_sum(std::vector<std::vector<int>> & towers, int radius, int x, int y) {
		int sum = 0;
		for (auto & pos : towers) {
			float dis = std::sqrt((pos[0] - x)*(pos[0] - x) + (pos[1] - y)*(pos[1] - y));
			if (dis <= radius) {
				//int d = dis;
				int temp = pos[2] / (1 + dis);
				sum += temp;
			}
		}
		return sum;
	}
};





int main() {
	//std::vector<int> arr = { 9,7,8,7,7,8,4,4,6,8,8,7,6,8,8,9,2,6,0,0,1,10,8,6,3,3,5,1,10,9,0,7,10,0,10,4,1,10,6,9,3,6,0,0,2,7,0,6,7,2,9,7,7,3,0,1,6,1,10,3 };
	//std::cout << Solution1().trimMean(arr);


	//std::vector<std::vector<int>> towers{{31, 13, 33}, {24, 45, 38}, {28, 32, 23}, {7, 23, 22}, {41, 50, 33}, {47, 21, 3}, {3, 33, 39}, {11, 38, 5}, {26, 20, 28}, {48, 39, 16}, {34, 29, 25}};
	//int radius = 21;
	//auto pos = Solution2().bestCoordinate(towers, radius);
	//std::cout << pos.front() << " " << pos.back();
	cin.get();
	return 0;
}