#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<unordered_map>
#include<sstream>
#include<cmath>


using namespace std;


class Solution1 {
public:
	string thousandSeparator(int n) {
		string result = std::to_string(n);
		if (result.size() > 3 && result.size() < 7) {
			result.insert(result.end() - 3, '.');
		}
		else if (result.size() >= 7 && result.size() < 10) {
			result.insert(result.end() - 3, '.');
			result.insert(result.end() - 7, '.');
		}
		else if (result.size() >= 10 && result.size() < 12) {
			result.insert(result.end() - 3, '.');
			result.insert(result.end() - 7, '.');
			result.insert(result.end() - 11, '.');
		}
		return result;
	}
};


class Solution2 {
public:
	vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
		std::vector<int> is_root(n, 1);
		for (const auto & edge : edges) {
			if (is_root[edge[1]]) {
				is_root[edge[1]] = 0;
			}
		}
		std::vector<int> result;
		for (int node = 0; node < n; ++node) {
			if (is_root[node]) {
				result.emplace_back(node);
			}
		}
		return result;
	}
};


class Solution3 {
	std::vector<int> dp;
public:
	std::pair<int,int> get_plusAndMulti(int num) {
		if (dp.size() < 31) {
			dp.resize(31, 0);
			for (int power = 0; power < 31; ++power) {
				dp[power] = std::pow(2, power);
			}
		}
		int time = 0;
		int max_power=upper_bound(dp.begin(), dp.end(), num)-dp.begin()-1;

		while (num>0) {
			auto first_greater = upper_bound(dp.begin(), dp.end(), num);
			num -= *(first_greater - 1);
			++time;
		}
		return std::make_pair(time, max_power);
	}

	int minOperations(vector<int>& nums) {
		int result = 0;
		int max_power = 0;
		for (int idx = 0; idx < nums.size(); ++idx) {
			//if (max_num < nums[idx]) {
			//	max_num = nums[idx];
			//}
			if (nums[idx] == 0) {
				continue;
			}
			else {
				auto timeAndPower = get_plusAndMulti(nums[idx]);
				if (max_power < timeAndPower.second) {
					max_power = timeAndPower.second;
				}
				result += timeAndPower.first;
			}
		}
		return result + max_power;
	}
};


class Solution {

public:
	bool containsCycle(vector<vector<char>>& grid) {

	}
};
int main() {
	//std::cout << Solution1().thousandSeparator(1234567891);


	//int n = 5;
	//std::vector<std::vector<int>> edges = {{0, 1}, {2, 1}, {3, 1}, {1, 4}, {2, 4}};
	//auto ans = Solution2().findSmallestSetOfVertices(n, edges);
	//for (auto &ele : ans) {
	//	std::cout << ele << " ";
	//}

	//std::vector<int> test_vec{ 1,5};
	////std::cout << Solution().get_plusAndMulti(1).first << std::endl;
	////std::cout << Solution().get_plusAndMulti(1).second << std::endl;;

	//std::cout << Solution()3.minOperations(test_vec);


	cin.get();
	return 0;
}