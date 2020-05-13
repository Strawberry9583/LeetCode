#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

class Solution1 {
public:
	vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
		auto max=std::max_element(candies.begin(), candies.end());
		std::vector<bool> result(false, candies.size());
		for (int idx = 0; idx < result.size(); ++idx) {
			if (candies[idx] + extraCandies >= *max) {
				result[idx] = true;
			}
		}
		return result;
	}
};



class Solution2 {
public:
	int maxDiff(int num) {
		std::vector<int> digits;
		while (num>0) {
			digits.emplace(digits.begin(), num %10);
			num /= 10;
		}
		std::vector<int>max_digits(digits), min_digits(digits);
		bool flag = false;
		int modified_num = 0;
		for (auto & ele : max_digits) {
			if ((!flag)&&ele != 9) {
				modified_num = ele;
				flag = true;
				ele = 9;
			}
			else if (flag&&ele == modified_num) {
				ele = 9;
			}
		}
		int modified_idx=-1;
		for (int idx = 0; idx < min_digits.size(); ++idx) {
			if (modified_idx == -1) {
				if (idx == 0&& min_digits[idx] != 1) {
					modified_num = min_digits[idx];
					min_digits[idx] = 1;
					modified_idx = idx;
				}
				// min_digits[idx]==1 must be replaced by min_digits[idx] >1
				// or the 1101057 will be transformed into 0000057, which is led by 0;
				else if(idx!=0 && min_digits[idx] >1) {
					modified_num = min_digits[idx];
					min_digits[idx] = 0;
					modified_idx = idx;
				}
			}
			else if (modified_idx != -1 && min_digits[idx] == modified_num) {
				if (modified_idx == 0) {
					min_digits[idx] = 1;
				}
				else {
					min_digits[idx] = 0;
				}
			}
		}
		return conver2int(max_digits) - conver2int(min_digits);
	}
	int conver2int(std::vector<int> & digits) {
		int num = 0;
		for (int idx = 0; idx < digits.size();++idx) {
			num = num * 10 + digits[idx];
		}
		return num;
	}
};


//class Solution {
//public:
//	bool checkIfCanBreak(string s1, string s2) {
//		std::vector<int> numtime1(27, 0);
//		std::vector<int> numtime2(27, 0);
//		for (auto & ele : s1) {
//			++numtime1[ele - 'a'];
//		}
//		for (auto & ele : s2) {
//			++numtime2[ele - 'a'];
//		}
//		int sum1 = 0;
//		int sum2 = 0;
//		for (int idx = 0; idx < 27; ++idx) {
//			sum1 += numtime1[idx];
//			sum2 += numtime2[idx];
//			if (sum1 < sum2) {
//				return false;
//			}
//		}
//		if (sum1 < sum2) {
//			return false;
//		}
//		else {
//			return true;
//		}
//	}
//};


class Solution {
public:
	bool checkIfCanBreak(string s1, string s2) {
		std::sort(s1.begin(), s1.end(), std::greater<char>());
		std::sort(s2.begin(), s2.end(), std::greater<char>());
		int count_1 = 0, count_2 = 0;
		for (int idx = 0; idx < s1.size(); ++idx) {
			if (s1[idx] >= s2[idx]) {
				++count_1;
			}
			if (s1[idx] <= s2[idx]) {
				++count_2;
			}
		}
		if (count_1 == s1.size() || count_2 == s1.size()) {
			return true;
		}
		else {
			return false;
		}
	}
};
int main() {
	Solution sol;
	//sol.maxDiff(1101057);
	string s1 = "abc", s2 = "xya";
	std::cout<<sol.checkIfCanBreak(s1, s2);
	std::cin.get();
	return 0;
}
