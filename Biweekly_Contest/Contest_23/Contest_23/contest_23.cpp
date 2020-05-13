#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<algorithm>
using namespace std;

class Solution1 {
public:
	int countLargestGroup(int n) {
		std::map<int, int> digit_sum_num;
		for (int num = 1; num <= n; ++num) {
			int rest = num;
			int digit_sum = 0;
			while (rest!=0) {
				digit_sum += rest % 10;
				rest /= 10;
			}
			++digit_sum_num[digit_sum];
		}
		int largest_size=std::max_element(digit_sum_num.begin(), digit_sum_num.end(),
			[](const std::pair<int, int> & rhs1, const std::pair<int, int> & rhs2)
		{return rhs1.second < rhs2.second; })->second;
		int result = 0;
		for (const auto & _ele : digit_sum_num) {
			if (_ele.second == largest_size) {
				++result;
			}
		}
		return result;
	}
};

class Solution2 {
public:
	bool canConstruct(string s, int k) {
		if (s.size() < k) {
			return false;
		}
		std::vector<int> letter_num(26, 0);
		for (const auto& ele : s) {
			++letter_num[ele - 'a'];
		}
		int letter_with_odd_num = 0;
		for (const auto & ele : letter_num) {
			if (ele % 2 == 1) {
				++letter_with_odd_num;
			}
		}
		return letter_with_odd_num > k ? false : true;
	}
};

class Solution3 {
public:
	bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
		std::pair<int, int> regular_x(x1 - radius, x2 + radius);
		std::pair<int, int> regular_y(y1 - radius, y2 + radius);
		if (x_center<regular_x.first || x_center>regular_x.second || y_center<regular_y.first || y_center>regular_y.second) {
			return false;
		}
		else if (x_center >= regular_x.first&&x_center <= regular_x.second&&y_center >= y1&&y_center <= y2) {
			return true;
		}
		else if (x_center >= x1&&x_center <= x2&&y_center >= regular_y.first&&y_center <= regular_y.second) {
			return true;
		}
		else {
			float d = 0;
			if (x_center <= x1&&y_center >= y2) {
				d = distance(x_center, y_center, x1, y2);
			}
			else if (x_center <= x1&&y_center <= y1) {
				d = distance(x_center, y_center, x1, y1);
			}
			else if (x_center >= x2&&y_center >= y2) {
				d = distance(x_center, y_center, x2, y2);
			}
			else {
				d = distance(x_center, y_center, x2, y1);
			}
			if (d >= radius) {
				return false;
			}
			else {
				return true;
			}
		}
	}
	float distance(float x1, float y1, float x2, float y2) {
		return std::sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
	}
};

int main() {
	Solution sol;
	std::cout << sol.checkOverlap(1,1,1,1,-3,2,-1);
	std::cin.get();
	return 0;
}