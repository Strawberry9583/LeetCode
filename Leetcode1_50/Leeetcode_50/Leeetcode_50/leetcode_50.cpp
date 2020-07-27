#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
	//all cases passed, but time limited;
	double myPow(double x, int n) {
		if (n == 0 || x == 1.0) {
			return 1.;
		}
		if (x == -1.0) {
			if (n & 1 == 1) {
				return -1.0;
			}
			else {
				return 1.0;
			}
		}
		if (n == 0x80000000) {
			return 0.;
		}
		int times = std::abs(n);
		double result = 1.;
		//--operator in case that 2^31-1 overflow;
		for (; times>0; --times) {
			result *= x;
		}
		if (n < 0) {
			result = 1. / result;
		}
		return result;
	}
};




class Solution2 {
public:
	double myPow(double x, int n) {
		//following cases can accelerate the calc;
		//if (n == 0 || x == 1.0) {
		//	return 1.;
		//}
		//if (x == -1.0) {
		//	if (n & 1 ) {
		//		return -1.0;
		//	}
		//	else {
		//		return 1.0;
		//	}
		//}
		//if (n == 0x80000000) {
		//	return 0.;
		//}
		long int times = std::abs(n);
		std::unordered_map<long int, double> archive;
		archive[1] = x;
		auto result=get_pow(archive, x, times);
		if (n < 0) {
			result = 1. / result;
		}
		return result;
	}
	//divide the num into two as: x^(n)=x^(n/2)*x^(n/2) , n is odd;
	//divide the num into two as: x^(n)=x^(n/2)*x^(n/2)*x , n is even;
	double get_pow(std::unordered_map<long int,double>& archive,double x, long int times) {
		if (archive.find(times) != archive.end()) {
			return archive[times];
		}
		else {
			long int mid = times / 2;
			if (times & 1 ) {
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
	Solution sol;
	double x = 2.00;
	int n = 2147483647;
	std::cout << sol.myPow(x,n);
	std::cin.get();
	return 0;
}