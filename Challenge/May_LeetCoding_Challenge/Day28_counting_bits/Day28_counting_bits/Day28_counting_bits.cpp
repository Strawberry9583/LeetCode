#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// solution 1: find out the law that the result can be generated with the specific law:
// 0   1   2   3   4   5   6   7   8   9   10   11   12   13   14  15
// 0   1  (1  2) (1   2   2   3) (1   2    2    3    2    3    3   4)   
class Solution1 {
public:
	vector<int> countBits(int num) {
		std::vector<int> result{ 0,1,1,2 };
		if (result.size() > num+1) {
			return std::vector<int>(result.begin(), result.begin() + num + 2);
		}
		int repeat_num = 2;
		while (result.size()<num+1) {
			int begin_idx = result.size() - repeat_num;
			for (int idx = 0; idx < repeat_num; ++idx) {
				result.emplace_back(result[begin_idx + idx]);
				if (result.size() == num + 1) {
					return result;
				}
			}
			begin_idx = result.size() - repeat_num;
			for (int idx = 0; idx < repeat_num;++idx) {
				result.emplace_back(result[begin_idx + idx] + 1);
				if (result.size() == num + 1) {
					return result;
				}
			}
			// expand repeat num to 2 times;
			repeat_num <<= 1;
		}
		return result;
	}
};

// solution2: first drop the lowest bit which is '1', then use sub-problem to calc the current result;
// For example: i = 14, its binary representation is 1110, so i-1 is 1101, i&(i-1) = 1100,
// the number of "1" in its binary representation decrease one, so ret[i] = ret[i&(i-1)] + 1. 
class Solution2 {
public:
	vector<int> countBits(int num) {
		vector<int> ret(num + 1, 0);
		for (int i = 1; i <= num; ++i)
			ret[i] = ret[i&(i - 1)] + 1;
		return ret;
	}
};

// solution3: calc the num of '1' in i, divide the i into the lowest bit and the other bits;
// for an integer i, when i/2 equals to the bit representation of i shift right for one bit. 
// So it's r[i/2]. (or use shift operator complete the function)
// And we just need to add i%2 which is the most right hand side of the bit set.
class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> r;
		r.push_back(0);
		for (int i = 1; i <= num; i++) {
			int x = r[i / 2] + (i % 2);
			// or write as follow:
			//int x = r[i >> 1] + (i % 2);
			r.push_back(x);
		}
		return r;
	}
};

int main() {
	auto ans = Solution().countBits(4);
	cin.get();
	return 0;
}