//Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
//
//Return the quotient after dividing dividend by divisor.
//
//The integer division should truncate toward zero.
//
//Example 1:
//
//Input: dividend = 10, divisor = 3
//	Output : 3
//	Example 2 :
//
//	Input : dividend = 7, divisor = -3
//	Output : -2
//	Note :
//
//	Both dividend and divisor will be 32 - bit signed integers.
//	The divisor will never be 0.
//	Assume we are dealing with an environment which could only store integers within 
//	the 32 - bit signed integer range : [−2^31, 2^31 − 1].For the purpose of this problem,
//	assume that your function returns 231 − 1 when the division result overflows.

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>


using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		// 整数除法，因此只有当 dividend == -231，divisor == -1 时结果才会越界
		if (!divisor || (dividend == INT_MIN && divisor == -1))
			return INT_MAX;
		/* ！使用 异或 操作符判断符号值得学习！ */
		int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
		// dividend == -231时，取绝对值后仍赋值给 int 则会越界，因此存储在 long long
		long long dvd = labs(dividend);
		long long dvs = labs(divisor);
		int res = 0;
		while (dvd >= dvs) {
			long long temp = dvs, multiple = 1;
			while (dvd >= (temp << 1)) {
				temp <<= 1;
				multiple <<= 1;
			}
			dvd -= temp;
			res += multiple;
		}
		return sign == 1 ? res : -res;
	}
/*
	int divide(int dividend, int divisor) {
		//if divident=-2^31,divisor==-1, the result overflows;
		if (divisor == -1 && dividend == INT_MIN) {
			return INT_MAX;
		}
		//long long max_int = 0x7FFFFFFF;
		//long long min_int = -(max_int + 1);
		//cout << max_int << endl;
		//cout << min_int << endl;
		//long long 
		long int sign_dividend = dividend & 0x80000000;
		int sign_divisor = divisor & 0x80000000;
		long dividend_temp = abs(dividend);
		long divisor_temp = abs(divisor);

		int result = 0;
		while (dividend_temp-divisor_temp>=0) {
			dividend_temp -= divisor_temp;
			++result;
		}
		if (sign_dividend^sign_divisor) {
			//positive to negative integer;
			//negative to positive integer;
			result = ~result +1;
		}
		return result;
		
	}
	*/


};

int main() {
	cout << sizeof(int) << endl;
	int x = 15, y = -3;
	Solution sol;
	cout<<sol.divide(x, y);
	cin.get();
	return 0;
}

