#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<bitset>

using namespace std;


// The problem, widely known as digit root problem,
// For base b (decimal case b = 10), the digit root of an integer is:
//
//dr(n) = 0 if n == 0
//dr(n) = (b - 1) if n != 0 and n % (b - 1) == 0
//dr(n) = n mod(b - 1) if n % (b - 1) != 0
//or
//
//dr(n) = 1 + (n - 1) % 9
//Note here, when n = 0, since(n - 1) % 9 = -1, the return value is zero(correct).
//
//From the formula, we can find that the result of this problem is immanently periodic, with period(b - 1).
//
//Output sequence for decimals(b = 10) :
//
//	~input : 0 1 2 3 4 ...
//	output : 0 1 2 3 4 5 6 7 8 9 1 2 3 4 5 6 7 8 9 1 2 3 ....
//
//	Henceforth, we can write the following code, whose time and space complexities are both O(1).
class Solution1 {
public:
	int addDigits(int num) {
		return 1 + (num - 1) % 9;
	}
};

// iterative ways to calc;
class Solution2 {
public:
	int addDigits(int num) {

		if (num / 10 == 0)
			return num;

		int sum = 0;
		while (num > 0) {
			sum = sum + num % 10;
			num = num / 10;
		}

		return addDigits(sum);

	}
};

int main() {
	cin.get();
	return 0;
}