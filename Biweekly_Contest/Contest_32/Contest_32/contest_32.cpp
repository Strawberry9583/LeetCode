#include<iostream>
#include<stack>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>

using namespace std;


class Solution1 {
public:
	int findKthPositive(vector<int>& arr, int k) {
		int idx = 0;
		for ( idx = 0; idx < arr.size(); ++idx) {
			if (arr[idx] - (idx + 1) >=k) {
				break;
			}
		}
		if (idx == arr.size()) {
			return k - (arr.back() - arr.size()) + arr.back();
		}
		else if(idx==0) {
			return k;
		}
		else {
			return arr[idx - 1] + k-(arr[idx - 1] - idx);
		}
	}
};

class Solution2 {
public:
	bool canConvertString(string s, string t, int k) {
		if (s.size() != t.size()) {
			return false;
		}
		std::vector<int> shiftnum2freq(27, k/26);
		k %= 26;
		for (int idx = 1; idx <= k; ++idx) {
			++shiftnum2freq[idx];
		}
		for (int idx = 0; idx < s.size(); ++idx) {
			if (s[idx] != t[idx]) {
				int gap = t[idx]-s[idx];
				if (s[idx] > t[idx]) {
					gap = t[idx] + 26 - s[idx];
				}
				--shiftnum2freq[gap];
				if (shiftnum2freq[gap] < 0) {
					return false;
				}
			}
		}
		return true;
	}
};




class Solution3 {
public:
	int minInsertions(string s) {
		int cur_state = 0;
		int result = 0;
		for (int idx = 0; idx < s.size(); ) {
			if (cur_state >= 0 && cur_state % 2 == 0) {
				if (s[idx] == '(') {
					cur_state += 2;
				}
				else {
					cur_state -= 1;
				}
				++idx;
			}
			else if (cur_state>0 && cur_state % 2) {
				if (s[idx] == '(') {
					result += 1;
					--cur_state;
				}
				else if (s[idx] == ')') {
					--cur_state;
					++idx;

				}
			}
			else {
				cur_state += 2;
				++result;
			}

		}

		if (cur_state > 0) {
			return result + cur_state;

		}
		else {
			return result + (abs(cur_state) / 2) + 2 * (abs(cur_state) % 2);
		}
	}
};


class Solution {
public:
	int longestAwesome(string s) {

	}
};

int main() {
	//string s = "input", t = "ouput";
	//int k = 9;
	//std::cout << Solution2().canConvertString(s, t, k);

	//string s = "(()))(()))()())))";
	//std::cout << Solution3().minInsertions(s);

	//std::vector<int> arr{ 2 };
	//int k = 1;
	//std::cout << Solution().findKthPositive(arr, k);
	cin.get();
	return 0;
}