#include<iostream>
#include<vector>
#include<string>


using namespace std;


class Solution {
public:
	int reverse(int x) {

	    int result=0;
		if (x > INT_MAX || x < INT_MIN)
		{
			return 0;
		}
		while (x!=0)
		{
			

			result = result * 10 + (x % 10);
			x /= 10;

		}

		return  result;
	}

	int reverse1(int x) {
		int y = 0;
		int n;
		while (x != 0) {
			n = x % 10;
			if (y > INT_MAX / 10 || y < INT_MIN / 10) {
				return 0;
			}
			y = y * 10;
			if (y > INT_MAX - n || y < INT_MIN - n) {
				y += n;
			}
			x /= 10;
		}
		return y;
	}
};


int main()
{
	Solution sol;
	cout << sol.reverse(123168798798456132);
	return 0;
}