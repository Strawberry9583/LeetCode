//leetcode 40 combinationSum2

//Given a collection of candidate numbers(candidates) and a target number(target), find all unique combinations in candidates where the candidate numbers sums to target.
//
//Each number in candidates may only be used once in the combination.
//
//Note:
//
//All numbers(including target) will be positive integers.
//The solution set must not contain duplicate combinations.
//Example 1 :
//
//	Input : candidates = [10, 1, 2, 7, 6, 1, 5], target = 8,
//	A solution set is :
//[
//	[1, 7],
//	[1, 2, 5],
//	[2, 6],
//	[1, 1, 6]
//]
//Example 2:
//
//Input: candidates = [2, 5, 2, 1, 2], target = 5,
//	A solution set is :
//	   [
//		   [1, 2, 2],
//		   [5]
//	   ]

#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;



class Solution {
public:
	vector<int>tempres;

	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		//sort from the smaller to bigger ones to prunning;
		sort(candidates.begin(), candidates.end());
		vector<vector<int>>res;
		dfs(candidates, target, 0, res);
		return res;
	}
	bool check_exist(std::vector<int> & temp, std::vector<std::vector<int>> & res) {
		for (const auto & ele : res) {
			if (temp == ele) {
				return true;
			}
		}
		return false;
	}
	void dfs(vector<int>&candidates, int target, int cur, vector<vector<int>>&res) {
		if (target == 0) {
			if (check_exist(tempres,res)) {
				return;
			}
			else {
				res.push_back(tempres);
			}
		}
		//caution that the cur< size to prevent access violation;
		if (cur==candidates.size()||target < candidates[cur])
			return;
		for (int i = cur; i < candidates.size(); ++i) {
			tempres.push_back(candidates[i]);
			//cur=i+1, owing to that all elements can be used only once;
			dfs(candidates, target - candidates[i], i+1, res);
			tempres.pop_back();
		}
	}
};

//method2:
class Solution2 {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> res;
		if (candidates.empty())
			return res;
		vector<int> currList;
		sort(candidates.begin(), candidates.end(), less<int>());
		helper(res, currList, candidates, target, 0);
		return res;
	}

	void helper(vector<vector<int>>& res, vector<int>& currList, const vector<int>& candidates, int target, int startIdx) {
		if (target < 0)
			return;
		if (target == 0) {
			res.push_back(currList);
			return;
		}

		for (int i = startIdx; i < candidates.size(); i++) {
			//cout << "i: " << i << ", startIdx: " << startIdx << ", candidates[i]: " << candidates[i] << endl; 
			
			//if i==starIdx && candidates[i]==candidates[i-1], then escape the startIdx=i;
			//because the canditates[i-1] have been tried.
			if (i != startIdx && candidates[i] == candidates[i - 1]) continue;
			currList.push_back(candidates[i]);
			//cout << "added " << i << "th element: " << candidates[i] << endl;
			helper(res, currList, candidates, target - candidates[i], i + 1);
			currList.pop_back();
		}
	}
};



int main() {
	vector<int> test{ 10,1,2,7,6,1,5 };
	Solution sol;
	auto result = sol.combinationSum2(test, 8);


	cin.get();
	return 0;
}