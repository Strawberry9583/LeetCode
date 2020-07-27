#include<iostream>
#include<unordered_set>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<functional>

using namespace std;
class Solution1 {
public:
	int countOdds(int low, int high) {
		int numofnum = high - low + 1;
		int result = 0;
		if (low % 2) {
			result = (numofnum + 1) / 2;
			// 1 2 3
			// 1 2 3 4
		}
		else {
			result = (numofnum ) / 2; 
			//2 3 4
			//2 3 4 5
		}
		return result;
	}
};


// check every possible range [i,j]: TLE
// time complexity: O(n^2);
class Solution2_1 {
public:
	int numOfSubarrays(vector<int>& arr) {
		int result = 0, mod = 1000000007;
		std::vector<int> sum(arr.size()+1, 0);
		sum[1] = arr[0];
		for (int idx = 2; idx <= arr.size(); ++idx) {
			sum[idx] = sum[idx - 1] + arr[idx-1];
		}
		for (int start = 1; start <= arr.size(); ++start) {
			for (int end = start; end <= arr.size(); ++end) {
				if ((sum[end] - sum[start - 1]) % 2) {
					++result;
					if (result == mod) {
						result = 0;
					}
				}
			}
		}
		return result;
	}
};

// directly judge the odd and even number
// odd_num[i] indicates the sum odd number in range [0,i];
// time complexity: O(n);
class Solution2_2 {
public:
	int numOfSubarrays(vector<int>& arr) {
		int result = 0, mod = 1000000007;
		int sum = 0;
		//std::vector<std::pair<int, int>> odd_even(arr.size(), std::pair<int, int>(0, 0));
		std::vector<int> odd_num(arr.size()+1, 0);
		std::vector<int> even_num(arr.size()+1, 0);
		for (int idx = 1; idx <= arr.size(); ++idx) {
			sum += arr[idx-1];
			if (sum % 2) {
				odd_num[idx] = odd_num[idx - 1] + 1;
				//itself odd, then plus 1; besides the odd minus even sum will get odd too;
				result += even_num[idx - 1]+1;
			}
			else {
				odd_num[idx] = odd_num[idx - 1];
				//even minus odd sum will get odd;
				result += odd_num[idx - 1];
			}
			// calc the even num according to odd num;
			even_num[idx] = idx - odd_num[idx];
			result %= mod;
		}
		return result;
	}
};

// scan in two direction;
// left2right[i] indicates  the amount of distinctive chars in range[0,i-1];
class Solution3 {
public:
	int numSplits(string s) {
		std::vector<int> left2right(s.size()+1, 0);
		// record the accurance of lower characters;
		std::vector<int> exist_flag(26, 0);
		// scan from left to right;
		for (int idx = 0; idx < s.size(); ++idx) {
			if (exist_flag[s[idx] - 'a']) {
				left2right[idx + 1] = left2right[idx];
			}
			else {
				exist_flag[s[idx] - 'a'] = 1;
				left2right[idx + 1] = left2right[idx] + 1;
			}
		}
		int result = 0;
		//exist_flag.resize(26, 0);
		exist_flag.assign(26, 0);
		int cur_distinct_num = 0;
		for (int idx = s.size() - 1; idx > 0; --idx) {
			if (exist_flag[s[idx] - 'a']) {
				
			}
			else {
				exist_flag[s[idx] - 'a'] = 1;
				++cur_distinct_num;
			}
			if (left2right[idx] == cur_distinct_num) {
				++result;
			}

		}
		return result;
	}
};

// Intuition:
// To eliminate target[i], just find the first j>i, whose target[j]<target[i];
// the operation number to eliminate target[i] is target[i]-target[j];

// Eg.: 4 1 8 2 5

// step1  3  0  7  1  4 
// step2: 3  0  6  0  3

// result: 3 + 6 + 3 + 2
class Solution {
public:
	int minNumberOperations(vector<int>& target) {
		int sum = 0;
		int n = target.size();
		for (int i = 0; i < n - 1; i++) {
			if (target[i] > target[i + 1])
				sum += target[i] - target[i + 1];
		}
		return sum + target.back();
	}
};
int main() {
	std::vector<int> target{ 3,1,5,4,2 };
	std::cout << Solution().minNumberOperations(target);
/*
	std::vector<int> test_vec{ 1,2,3,4,5,6,7};
	std::cout << Solution2().numOfSubarrays(test_vec);*/

	//string test_str = "aacaba";
	//std::cout << Solution().numSplits(test_str);
	//std::cout << Solution1().countOdds(3, 7);
	cin.get();
	return 0;
}