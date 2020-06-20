#include<iostream>
#include<vector>
#include<string>

using namespace std;

// solutin 1: binary search
// similar to binary search: search the first num in [0,x+1), whose num*num>x;
class Solution1 {
public:
	int mySqrt(int x) {
		long int left = 0;
		// x = 0, then search range should be extend, so plus one;
		long int right = static_cast<long int>(x) + 1;
		//find the first num, satisfying num*num>x;
		while (left<right) {
			long int mid = left + (right - left) / 2;
			if (mid*mid > x) {
				right = mid;
			}
			else if (mid*mid <= x) {
				left = mid + 1;
			}
		}
		return left - 1;
	}
};

// solution 2: Newton's method;
// Time complexity: O(lgn), the analysis is shown as following:
// https://www.zhihu.com/question/63641120/answer/929488290
/*	Given y = f(x), find the root x such that f(x) = 0, geometrically
	speaking, find the intersection of the function y and the x - axis.

	For a roughly estimated root x0, it's coordinate on the function
	is P(x0, f(x0)).We can find P's tangent line L whose slope is m,
	such that the intersection of the L and the x - axis, say S(x1, 0),
	it's function value f(x1) is closer to the real root of y = f(x),
	comparing to the f(x0).

	Set m = f'(x0), where f' denotes the differential on x0 ... (1)
	The slope m is defined by PS : m = (f(x0) - 0) / (x0 - x1) ... (2)
	Combine(1) (2), f'(x0) = f(x0) / (x0 - x1)
	= > x0 - x1 = f(x0) / f'(x0)
	= > x1 = x0 - f(x0) / f'(x0)

	x(n + 1) = x(n) - f(x(n)) / f'(x(n))
	By applying Newton's method to the root problem, finding the
	r such that r ^ 2 equals to the input x is the same as finding the
	root of f(r) where

	f(r) = r ^ 2 - x = 0
	= > r(n + 1) = r(n) - f(r(n)) / f'(r(n))
	= > r(n + 1) = r(n) - (r(n) ^ 2 - x) / 2 * r(n)
	= > r(n + 1) = r(n) - r(n) / 2 + x / 2 * r(n)
	= > r(n + 1) = (r(n) + x / r(n)) / 2

	The pseudo recursive code :

	while (r ^ 2 - x > 0) {
		r = (r + x / r) / 2
	}
*/
class Solution {
public:
	int mySqrt(int x) {
		long long r = x;
		while (r*r > x)
			r = (r + x / r) / 2;
		return r;
	}
};


int main() {
	cin.get();
	return 0;
}