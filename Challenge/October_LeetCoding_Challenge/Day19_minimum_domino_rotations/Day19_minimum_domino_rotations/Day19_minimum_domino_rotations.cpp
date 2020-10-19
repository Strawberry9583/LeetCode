#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;


class Solution {
public:
	int minDominoRotations(vector<int>& A, vector<int>& B) {
		std::vector<int> num2freq(6, 0);
		for (int idx = 0; idx < A.size(); ++idx) {
			++num2freq[A[idx]-1];
			++num2freq[B[idx]-1];
		}
		int num1 = -1, num2 = -1;
		for (int num = 0; num < 6; ++num) {
			if (num2freq[num] >= A.size()) {
				if (num1 == -1) {
					num1 = num+1;
				}
				else if (num2 == -1) {
					num2 = num + 1;
				}
			}
		}
		int time1 = min_rotation(num1, A, B);
		int time2 = min_rotation(num2, A, B);
		if (time1 == -1 && time2 == -1) {
			return -1;
		}
		else if (time1 == -1) {
			return time2;
		}
		else {
			return time1;
		}
	}
private:
	int min_rotation(int num1, std::vector<int> & A, std::vector<int> & B) {
		for (int idx = 0; idx < A.size(); ++idx) {
			if (A[idx]==num1 || B[idx]==num1) {
				continue;
			}
			else {
				return -1;
			}
		}
		int time1 = 0;
		int time2 = 0;
		for (int idx = 0; idx < A.size(); ++idx) {
			if (A[idx] != num1) {
				++time1;
			}
			if (B[idx] != num1) {
				++time2;
			}
		}
		return std::min(time1, time2);
	}
};


int main() {
	std::vector<int> A{ 3,5,1,2,3 }, B{ 3,6,3,3,4 };
	std::cout << Solution().minDominoRotations(A, B);
	cin.get();
	return 0;
}