#include<iostream>
#include<string>
#include<math.h>


using namespace std;


class Solution {
public:
	bool isPalindrome(int x) {
		int digit_num = static_cast<int>(log10(x)) + 1;
		bool result = true;
		if (x<0){
			return false;
		}
		else if (x == 0){
			return true;
		}
		else if (x < 10)
		{
			return true;
		}
		else if (x >= 10 && x < 100)
		{
			if (x / 10 == x % 10)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else{
			for (int i = 0; i <digit_num / 2; ++i){
				int back = x % 10;
				x -= back;
				int head = x / pow(10, digit_num - 2 * i-1);
				if (back != head) {
					result = false;
					break;
				}
				else if (i == (digit_num / 2)-1){
					if (digit_num%2==1)
					{
						result = true;
					}
			}
			x = x % static_cast<int>(pow(10, digit_num - 2 * i-1));
			x /= 10;
			}
			return result;
		}


	}
};


int main() {

	if (Solution().isPalindrome(1123211)) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
	system("pause");
	return 0;
}