#include<iostream>
#include<deque>
#include<vector>
#include<string>
#include<unordered_set>
#include<unordered_set>
#include<algorithm>

using namespace std;

// TLE
// Time complexity: O(n^3);
class Solution1 {
public:
	int nthUglyNumber(int n) {
		static std::vector<int> ugly_number{ 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 };
		static int tria_num = ugly_number.back() + 1;
		//int number = ugly_number.back()+1;
		while (ugly_number.size()<n) {
			if (is_ugly(tria_num)) {
				ugly_number.emplace_back(tria_num);
			}
			++tria_num;
		}
		return ugly_number[n - 1];
	}
	bool is_ugly(int number) {
		//int root = std::sqrt(number);
		for (int idx = 4; idx <= number; ++idx) {
			if (idx == 5) {
				continue;
			}
			else if (number%idx == 0 && is_prime(idx)) {
				return false;
			}
		}
		return true;
	}
	bool is_prime(int number) {
		static std::deque<bool> is_prime{false,true,true};
		while (is_prime.size()<number) {
			int temp_num = is_prime.size()+1;
			int root = std::sqrt(temp_num);
			bool flag = true;
			for (int idx = 2; idx <= root; ++idx) {
				if (temp_num%idx == 0) {
					flag = false;
					break;
				}
			}
			is_prime.emplace_back(flag);
		}
		return is_prime[number - 1];
	}
};

// solution2: TLE 
// Time complexity: O(n^2); Space complexity:O(n)
// Use all generated ugly number to multiply with 2, 3, 5;
// every time add the current smallest ugly number into set until find the n_th smallest number;
class Solution2 {
public:
	int nthUglyNumber(int n) {
		std::vector<int> all_ugly_num{ 1 };
		std::vector<int> cur_idx{ 0,0,0 };
		while (all_ugly_num.size()<n) {
			// calc the current three possible minimal ugly numbers;
			std::vector<int> all_num{ all_ugly_num[cur_idx[0]] * 2,
				all_ugly_num[cur_idx[1]] * 3,all_ugly_num[cur_idx[2]] * 5 };
			auto min_ = std::min_element(all_num.begin(), all_num.end());
			++cur_idx[min_ - all_num.begin()];
			// find wether to be found;
			if (std::find(all_ugly_num.begin(), all_ugly_num.end(), *min_) == all_ugly_num.end()) {
				all_ugly_num.emplace_back(*min_);
			}
		}
		return all_ugly_num.back();
	}
};

// solution3: similar to solution2 but use hash set to reduce complexity;
// Time complexity: O(n); Space complexity : O(n)
class Solution3 {
public:
	int nthUglyNumber(int n) {
		std::vector<int> all_ugly_num{ 1 };
		std::unordered_set<int> all_ugly_set{ 1 };
		std::vector<int> cur_idx{ 0,0,0 };
		while (all_ugly_num.size()<n) {
			std::vector<int> all_num{ all_ugly_num[cur_idx[0]] * 2,
				all_ugly_num[cur_idx[1]] * 3,all_ugly_num[cur_idx[2]] * 5 };
			auto min_ = std::min_element(all_num.begin(), all_num.end());
			++cur_idx[min_ - all_num.begin()];
			// use hash set to judge the existence;
			if (all_ugly_set.find(*min_) == all_ugly_set.end()) {
				all_ugly_num.emplace_back(*min_);
				all_ugly_set.emplace(*min_);
			}
		}
		return all_ugly_num.back();
	}
};


// solution4£ºeradicate duplicate ugly numbers;
class Solution {
public:
	int nthUglyNumber(int n) {
		std::vector<int> all_ugly_num{ 1 };
		// speed up the searching;
		std::vector<int> cur_idx{ 0,0,0 };
		while (all_ugly_num.size()<n) {
			std::vector<int> all_num{ all_ugly_num[cur_idx[0]] * 2,
				all_ugly_num[cur_idx[1]] * 3,all_ugly_num[cur_idx[2]] * 5 };
			auto min_ = std::min_element(all_num.begin(), all_num.end());
			if (*min_ == all_ugly_num[cur_idx[0]] * 2) {
				++cur_idx[0];
			}
			// use if but not else if to eradicate all duplicate ugly numbers;
			if (*min_ == all_ugly_num[cur_idx[1]] * 3) {
				++cur_idx[1];
			}
			if (*min_ == all_ugly_num[cur_idx[2]] * 5) {
				++cur_idx[2];
			}
			all_ugly_num.emplace_back(*min_);
		}
		return all_ugly_num.back();
	}
};

//solution5: follow the same idea and update the idx vector timely;
class solution {
	int nthUglyNumber(int n) {
		vector<int> ugly(n, 1);
		int c2 = 2, c3 = 3, c5 = 5;
		int i2 = 0, i3 = 0, i5 = 0;
		for (int i = 1; i<n; ++i) {
			int last = ugly[i] = min(c2, min(c3, c5));
			while (c2 <= last) c2 = 2 * ugly[++i2];
			while (c3 <= last) c3 = 3 * ugly[++i3];
			while (c5 <= last) c5 = 5 * ugly[++i5];
		}
		return ugly[n - 1];
	}
};

int main() {
	unsigned int i = 1;
	unsigned char * ptr = (unsigned char*)(&i);

	if(*ptr==0x1){
		std::cout << "little" << std::endl;
	}
	else {
		std::cout << "big" << std::endl;
	}
	
	//std::cout << Solution().nthUglyNumber(10);


	cin.get();
	return 0;

}