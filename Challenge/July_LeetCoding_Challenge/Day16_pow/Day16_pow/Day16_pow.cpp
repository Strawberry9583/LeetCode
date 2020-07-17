#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
	double myPow(double x, int n) {
		long int times = std::abs(n);
		std::unordered_map<int, double> archive;
		archive[0] = 1.0;
		archive[1] = x;
		auto result = get_pow(archive, x, times);
		if (n < 0) {
			result = 1. / result;
		}
		return result;
	}
	double get_pow(std::unordered_map<int, double>& archive, double x, long int times) {
		if (archive.find(times) != archive.end()) {
			return archive[times];
		}
		else {
			long int mid = times / 2;
			if (times & 1) {
				archive[times] = get_pow(archive, x, mid) * get_pow(archive, x, mid + 1);
				return archive[times];
			}
			else {
				archive[times] = get_pow(archive, x, mid)*get_pow(archive, x, mid);
				return archive[times];
			}
		}

	}
};

int main() {
	cin.get();
	return 0;
}