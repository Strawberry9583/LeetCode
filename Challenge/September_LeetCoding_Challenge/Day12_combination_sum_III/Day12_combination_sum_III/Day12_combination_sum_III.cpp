#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

// method: dfs
class Solution {
	std::vector<std::vector<int>> m_result;
	int m_target_sum;
	int m_target_size;
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		if (k == 0) {
			return m_result;
		}
		m_target_sum = n;
		m_target_size = k;
		int cur_size = 1;
		for (int added_num = 1; added_num < 10; ++added_num) {
			std::vector<int> selected_num = { added_num };
			dfs(added_num,added_num,selected_num);
		}
		return m_result;
	}
private:
	void dfs(int cur_sum, int last_added_num,std::vector<int>& selected_num) {
		if (selected_num.size()== m_target_size) {
			if (cur_sum == m_target_sum) {
				m_result.emplace_back(selected_num);
			}
			else {
				return;
			}
		}
		else if (selected_num.size() < m_target_size&&cur_sum >= m_target_sum) {
			return;
		}
		else {
			for (int added_num = last_added_num + 1; added_num < 10; ++added_num) {
				selected_num.emplace_back(added_num);
				dfs(cur_sum + added_num, added_num, selected_num);
				selected_num.pop_back();
			}
		}
	}
};

int main() {
	auto ans = Solution().combinationSum3(3, 9);
	for (auto & arr : ans) {
		for (auto & ele : arr) {
			std::cout << ele << " ";
		}
		std::cout << endl;
	}
	cin.get();
	return 0;
}