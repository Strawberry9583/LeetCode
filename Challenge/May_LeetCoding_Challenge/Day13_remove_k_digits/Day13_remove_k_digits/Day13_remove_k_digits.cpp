#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;

// if zero in [num[0],num[k+1]] then remove all element ahead of zero, then the digits will be least;
// otherwise: find the smallest element, remove all the element ahead of the it.
class Solution_1 {
public:
	void check_remove_zero(string & num, int & k) {
		auto zero_idx = num.find_first_of('0');
		while (zero_idx!=string::npos&&zero_idx <= k) {
			num.erase(num.begin(), num.begin() + zero_idx+1);
			k -= zero_idx;
			int idx = 0;
			for (; idx != num.size(); ++idx) {
				if (num[idx] != '0') {
					break;
				}
			}
			num.erase(num.begin(), num.begin() + idx);
			zero_idx = num.find_first_of('0');
		}
	}
	string removeKdigits(string num, int k) {
		//if 0 in [0,k+1] then remove the digit ahead the 0; because there will be least digits.
		check_remove_zero(num, k);
		if (k >= num.size()) {
			return "0";
		}
		int begin_idx = 0;
		//find the smallest element, remove all the element ahead of the it.
		while (k>0) {
			auto min_digit=std::min_element(num.begin()+begin_idx, num.begin() + begin_idx+k+1);
			k -= min_digit - num.begin()-begin_idx;
			num.erase(num.begin()+begin_idx, min_digit);
			++begin_idx;
		}
		return num.empty()?"0":num;
	}
};

// combine the two cases into one:
// find the smallest element (including zero), remove all the element ahead of the it.
// Caution: there is a bug
class Solution {
public:
	string removeKdigits(string num, int k) {
		int begin_idx = 0;
		//find the smallest element, remove all the element ahead of the it.
		while (k>0) {
			auto min_digit = std::min_element(num.begin() + begin_idx, num.begin() + begin_idx + k + 1);
			k -= min_digit - num.begin() - begin_idx;
			num.erase(num.begin() + begin_idx, min_digit);		
			int idx = 0;
			for (; idx != num.size(); ++idx) {
				if (num[idx] != '0') {
					break;
				}
			}
			num.erase(num.begin()+begin_idx, num.begin()+begin_idx + idx);
			++begin_idx;
			if (k >= num.size()) {
				return "0";
			}
		}
		return num.empty() ? "0" : num;
	}
};

//Monotonous stack to record the string with ascending order.
class Solution_2 {
public:
	string removeKdigits(string num, int k) {
		string result;
		int result_size(num.size() - k);
		for (int idx = 0; idx < num.size(); ++idx) {
			while ((!result.empty()) && k&&result.back() > num[idx]) {
				result.pop_back();
				--k;
			}
			result.push_back(num[idx]);
		}
		//make sure having remove k numbers;
		//such as "9" , k=1 , then result is "0";
		result.resize(result.size());
		while ((!result.empty()) && result.front() == '0') {
			result.erase(result.begin());
		}
		return result.empty() ? "0" : result;
	}
};


class Solution_3 {
public:
	string removeKdigits(string num, int k) {
		string result;
		int result_size(num.size() - k);
		for (int idx = 0; idx < num.size(); ++idx) {
			while ((!result.empty()) && k&&result.back() > num[idx]) {
				result.pop_back();
				--k;
			}
			//exlude the zero-leading situation;
			if ((!result.empty()) || num[idx] != '0') {
				result.push_back(num[idx]);
			}
		}
		//make sure having remove k numbers;
		while (result.size() && k > 0) {
			result.pop_back();
			--k;
		}
		return result.empty() ? "0" : result;
	}
};

int main() {
	Solution_3 sol;
	string test = "1111111";
	int k = 1000;
	std::cout << sol.removeKdigits(test, k);
	cin.get();
	return 0;
}