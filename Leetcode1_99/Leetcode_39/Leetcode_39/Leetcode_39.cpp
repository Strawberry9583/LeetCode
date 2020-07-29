/*
39. Combination Sum 1
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
*/
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end(), [](const int i1, const int i2) {return i1 < i2; });
		if (candidates.empty()||*candidates.begin()>target) {
			return std::vector<std::vector<int>>();
		}
		std::set<std::vector<int>> result_set;
		dfs(result_set, candidates, std::vector<int>(),target);
		vector<vector<int>> result;
		for (const auto & i : result_set) {
			result.emplace_back(i);
		}
		return result;
		
	}
	void dfs(std::set<std::vector<int>> & result, vector<int>& candidates, std::vector<int> path,int target) {
		if (target<*candidates.begin()) {
			return;
		}
		else {
			for (int i = 0; i < candidates.size(); ++i) {
				if (candidates[i] == target) {
					path.push_back(candidates[i]);
					sort(path.begin(), path.end(), [](const int i1, const int i2) {return i1 < i2; });
					result.insert(path);
					return;
				}
				else if (candidates[i] > target) {
					return;
				}
				else {
					vector<int> new_path(path);
					new_path.push_back(candidates[i]);
					dfs(result, candidates, new_path, target - candidates[i]);
				}
			}
		}
	}
};


//method of others' to improve the complexity;
//解题思路：回溯剪枝法，先将candidates排序，之后可以通过比较所需要的值与当前遍历到的值的大小比较，可以剪枝减少运算。
//class Solution {
//public:
//	vector<int>tempres;
//	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//		sort(candidates.begin(), candidates.end());
//		vector<vector<int>>res;
//		dfs(candidates, target, 0, res);
//		return res;
//	}
//	void dfs(vector<int>&candidates, int target, int cur, vector<vector<int>>&res) {
//		if (target == 0) {
//			res.push_back(tempres);
//			return;
//		}
//		if (target < candidates[cur])
//			return;
//		for (int i = cur; i < candidates.size(); ++i) {
//			tempres.push_back(candidates[i]);
//			dfs(candidates, target - candidates[i], i, res);
//			tempres.pop_back();
//		}
//	}
//};


int main() {
	Solution sol;
	vector<int> candidates{ 2,3,6,7 };
	auto res=sol.combinationSum(candidates, 7);
	for (const auto & i : res) {
		for (const auto & j : i) {
			std::cout << j << " ";
		}
		std::cout << endl;
	}
	cin.get();
	return 0;
}