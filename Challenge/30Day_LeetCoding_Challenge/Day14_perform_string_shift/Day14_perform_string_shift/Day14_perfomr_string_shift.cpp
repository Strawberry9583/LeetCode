#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Solution {
public:
	string stringShift(string s, vector<vector<int>>& shift) {
		string result=s;
		int shift_distance = 0;
		for (auto & ele : shift) {
			if (ele[0] == 0) {
				shift_distance -= ele[1];
			}
			else {
				shift_distance += ele[1];
			}
		}
		if (shift_distance == 0) {
			return result;
		}
		else if (shift_distance < 0) {
			shift_distance = -1*(std::abs(shift_distance) % s.size());
		}
		else {
			shift_distance = shift_distance%s.size();
		}
		for (int idx = 0; idx < s.size(); ++idx) {
			int shift_idx = idx + shift_distance;
			std::cout << shift_idx << "  " << s.size() << std::endl;
			bool test = shift_idx >= s.size();
			//Alert: unsigned and signed type cacl together, then the signed will transformed into unsigned;
			if (shift_idx > (int)s.size()-1) {
				shift_idx -= s.size();
			}
			else if (shift_idx < 0) {
				shift_idx += s.size();
			}
			result[shift_idx] = s[idx];
		}
		return result;
	}
};

int main() {
	//Solution sol;
	//string test_s = "wpdhhcj";
	//std::vector<std::vector<int>> test_vec{ {0, 7}, {1, 7}, {1, 0}, {1, 3}, {0, 3}, {0, 6}, {1, 2} };
	//sol.stringShift(test_s, test_vec);
	int comp1 = -4;
	size_t num2 = 1;
	bool judge(comp1 > num2);
	std::cout << judge;
	std::cin.get();
	return 0;
}