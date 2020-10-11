#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
	std::vector<std::vector<int>> m_result;
	std::vector<int> m_nums;
	int m_target;
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		int cur_sum = 0;
		m_target = target;
		m_nums = candidates;
		std::vector<int> path;
		dfs(path, cur_sum,0);
		return m_result;
	}
private:
	void dfs(std::vector<int> & path, int cur_sum,int last_idx) {
		if (cur_sum == m_target) {
			m_result.emplace_back(path);
		}
		else if (cur_sum > m_target) {
			return;
		}
		else {
			for (int idx = last_idx; idx < m_nums.size(); ++idx) {
				path.emplace_back(m_nums[idx]);
				dfs(path, cur_sum + m_nums[idx],idx);
				path.pop_back();
			}
		}
	}
};


int main() {
	cin.get();
	return 0;
}