#include<iostream>
#include<vector>
#include<string>
#include<functional>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>

using namespace std;


// partial specialization for pair<int,int> 
namespace std {

	template<>
	struct hash<pair<int, int>> {
		size_t operator()(const pair<int, int> &pos) const {
			return hash<int>()(pos.first) + hash<int>()(pos.second);
		};
	};
	template<>
	struct equal_to<pair<int, int>> {
		bool operator()(const pair<int, int>&pos1, const pair<int, int>& pos2)const {
			return pos1.first == pos2.first&&pos2.second == pos2.second;
		}
	};
}

class Solution {
public:


	bool isPathCrossing(string path) {
		std::unordered_set<pair<int, int>> all_pos;
		std::pair<int, int> pos(0, 0);
		all_pos.emplace(pos);

		for (auto & dir : path) {
			if (dir == 'N') {
				++pos.second;
			}
			else if (dir == 'S') {
				--pos.second;
			}
			else if (dir == 'W') {
				--pos.first;
			}
			else if (dir == 'E') {
				++pos.first;
			}
			if (all_pos.find(pos) == all_pos.end()) {
				all_pos.emplace(pos);
			}
			else {
				return true;
			}
		}
		return false;
	}
};
// problem2: 
// solution1: just pass for weak test cases;
// the following will accept the cases which is divided not only by two in a pair;
class Solution2_1 {
public:
	bool canArrange(vector<int>& arr, int k) {
		int sum = 0;
		for(auto & ele: arr){
			ele %= k;
			sum += ele;
		}
		return (sum%k) == 0;
	}
};

// solution2: 
// to count all rest of k then match th i and k-i until all can be matched.
class Solution2_2 {
public:
	bool canArrange(vector<int>& arr, int k) {

		int n = arr.size();
		unordered_map<int, int>mp;

		for (int i = 0; i < n; i++)
			/* Add k to ensure this works for negative numbers */
			mp[(k + arr[i] % k) % k]++;

		for (int i = 0; i < n; i++) {
			int r = (k + arr[i] % k) % k;
			if (r == 0) {
				/* If remainder is 0, then there must be even number of such array elements */
				if (mp[r] % 2 != 0)
					return false;
			}
			else if (mp[r] != mp[k - r]) {
				/* number of elements with remainder r must be same as number of elements with remainder k-r */
				return false;
			}
		}

		return true;
	}
};
// problem 3:
class Solution3 {
public:
	int numSubseq(vector<int>& nums, int target) {
		int result = 0;
		int mod = 1e9 + 7;
		std::sort(nums.begin(), nums.end(), [](int rhs1, int rhs2) {return rhs1 < rhs2; });
		for (int idx = 0; idx < nums.size(); ++idx) {
			int max_limit = target - nums[idx];
			auto first_greater=std::upper_bound(nums.begin() + idx, nums.end(), max_limit);
			int cases_num = first_greater - (nums.begin() + idx);
			result += cases_num;
			result %= mod;
		}
		return result;
	}
};
int main() {
	std::string tess = "WNSN";
	std::cout << Solution().isPathCrossing(tess);

	//std::vector<int> test_vec{ 1,2,3,4,5,10,6,7,8,9 };
	//int k = 5;
	//std::cout << Solution().canArrange(test_vec, k);

	//std::vector<int> test_vec{ 3,5,6,7 };
	//int target = 9;
	//std::cout << Solution().numSubseq(test_vec, target);
	cin.get();
	return 0;
}